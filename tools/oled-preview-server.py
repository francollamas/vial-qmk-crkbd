#!/usr/bin/env python3
"""
 Copyright 2026 Franco

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""

import json
import re
from http import HTTPStatus
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VISUAL_SOURCE = ROOT / "keyboards/crkbd/keymaps/vial/oled_visuals.h"
TABLE_PATTERN = re.compile(
    r"(static const uint16_t PROGMEM oled_large_icons\[\]\[OLED_ICON_HEIGHT\] = \{\n)(.*?)(\n\};)",
    re.DOTALL,
)
ICON_ROW_PATTERN = re.compile(r"(?m)^[ \t]*\{[^{}\n]+\},[ \t]*$")
ICON_NAME_PATTERN = re.compile(r"^#define\s+OLED_ICON_(\w+)\s+'\\x[\da-f]{2}'", re.MULTILINE | re.IGNORECASE)


class PreviewHandler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=str(ROOT), **kwargs)

    def send_json(self, status, payload):
        data = json.dumps(payload).encode()
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def do_POST(self):
        if self.path != "/save-icon":
            self.send_json(HTTPStatus.NOT_FOUND, {"error": "Unknown endpoint."})
            return

        try:
            content_length = int(self.headers.get("Content-Length", "0"))
            if content_length > 4096:
                raise ValueError("Request is too large.")
            payload = json.loads(self.rfile.read(content_length))
            self.save_icon(payload)
        except (json.JSONDecodeError, TypeError, ValueError) as error:
            self.send_json(HTTPStatus.BAD_REQUEST, {"error": str(error)})

    def save_icon(self, payload):
        source = VISUAL_SOURCE.read_text(encoding="utf-8")
        icon_names = ICON_NAME_PATTERN.findall(source)
        icon = payload.get("icon")
        rows = payload.get("rows")
        width = int(re.search(r"#define\s+OLED_ICON_WIDTH\s+(\d+)", source).group(1))
        height = int(re.search(r"#define\s+OLED_ICON_HEIGHT\s+(\d+)", source).group(1))

        if icon not in icon_names:
            raise ValueError("Unknown icon.")
        if not isinstance(rows, list) or len(rows) != height:
            raise ValueError(f"An icon must have exactly {height} rows.")
        if any(not isinstance(row, int) or row < 0 or row >= 1 << width for row in rows):
            raise ValueError(f"Rows must fit within {width} bits.")

        table = TABLE_PATTERN.search(source)
        if not table:
            raise ValueError("Could not find oled_large_icons.")
        icon_rows = list(ICON_ROW_PATTERN.finditer(table.group(2)))
        icon_index = icon_names.index(icon)
        if len(icon_rows) != len(icon_names):
            raise ValueError("The icon table and icon definitions are out of sync.")

        digits = (width + 3) // 4
        replacement = "    {" + ", ".join(f"0x{row:0{digits}X}" for row in rows) + "},"
        body = table.group(2)
        row = icon_rows[icon_index]
        updated_body = body[:row.start()] + replacement + body[row.end():]
        updated_source = source[:table.start(2)] + updated_body + source[table.end(2):]
        VISUAL_SOURCE.write_text(updated_source, encoding="utf-8")
        self.send_json(HTTPStatus.OK, {"path": str(VISUAL_SOURCE.relative_to(ROOT))})


if __name__ == "__main__":
    server = ThreadingHTTPServer(("127.0.0.1", 8000), PreviewHandler)
    print("OLED preview server: http://localhost:8000/tools/oled-preview.html")
    server.serve_forever()
