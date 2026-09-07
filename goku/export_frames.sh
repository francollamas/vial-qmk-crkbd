#!/usr/bin/env bash
#
# Copyright 2026 Franco
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

set -euo pipefail

readonly SOURCE="$(dirname "$0")/frames/preview.png"
readonly OUTPUT="$(dirname "$0")/frames"
readonly FRAME_WIDTH=32
readonly FRAME_HEIGHT=96
readonly ART_WIDTH=30
readonly SHEET_COLUMNS=6
readonly SHEET_ROWS=5

# Midpoints of the white gaps in the generated 793x1983 source sheet.
# Equal sixths include the aura of the next frame, especially at column three.
readonly -a COLUMN_BOUNDS=(0 124 256 377 523 655 793)
readonly -a ROW_BOUNDS=(0 424 795 1173 1545 1983)
# The third/fourth boundary varies by row because generator auras are uneven.
readonly -a TRANSFORMATION_STARTS=(377 356 377 360 360)

readonly -a ANIMATIONS=(
    base-idle
    base-to-ssj
    ssj-idle
    ssj-to-ssj2
    ssj2-idle
    ssj2-to-ssj3
    ssj3-idle
    ssj3-to-ssj4
    ssj4-idle
    ssj4-to-base
)

if [[ ! -f "$SOURCE" ]]; then
    printf 'Missing sprite sheet: %s\n' "$SOURCE" >&2
    exit 1
fi

mkdir -p "$OUTPUT"
temporary_directory="$(mktemp -d)"
trap 'rm -rf "$temporary_directory"' EXIT

read -r source_width source_height < <(identify -format '%w %h\n' "$SOURCE")
if ((source_width != 793 || source_height != 1983)); then
    printf 'Expected a 793x1983 source sheet, received %sx%s.\n' "$source_width" "$source_height" >&2
    exit 1
fi
preview_frames=()
reference_width=0

for row in $(seq 0 $((SHEET_ROWS - 1))); do
    y="${ROW_BOUNDS[row]}"
    next_y="${ROW_BOUNDS[row + 1]}"
    cell_height=$((next_y - y))

    for column in $(seq 0 $((SHEET_COLUMNS - 1))); do
        x="${COLUMN_BOUNDS[column]}"
        next_x="${COLUMN_BOUNDS[column + 1]}"
        if ((column == 2)); then
            next_x="${TRANSFORMATION_STARTS[row]}"
        elif ((column == 3)); then
            x="${TRANSFORMATION_STARTS[row]}"
        fi
        cell_width=$((next_x - x))
        temporary_frame="$temporary_directory/$row-$column.png"

        # Keep the original ink until after downscaling so thin generated strokes survive.
        magick "$SOURCE" -crop "${cell_width}x${cell_height}+${x}+${y}" +repage -alpha off -fuzz 5% -trim +repage "$temporary_frame"

        if ((row == 0 && column == 0)); then
            read -r reference_width < <(identify -format '%w\n' "$temporary_frame")
        fi
    done
done

for row in $(seq 0 $((SHEET_ROWS - 1))); do
    for column in $(seq 0 $((SHEET_COLUMNS - 1))); do
        animation_index=$((row * 2 + column / 3))
        animation="${ANIMATIONS[animation_index]}"
        frame_number=$((column % 3 + 1))
        temporary_frame="$temporary_directory/$row-$column.png"

        read -r frame_width frame_height < <(identify -format '%w %h\n' "$temporary_frame")
        scaled_width=$(((frame_width * ART_WIDTH + reference_width / 2) / reference_width))
        scaled_height=$(((frame_height * ART_WIDTH + reference_width / 2) / reference_width))
        output_frame="$OUTPUT/$animation-$frame_number.png"

        # Keep Goku at one scale across all phases; crop only oversized aura and rays.
        magick "$temporary_frame" -colorspace gray -filter box -resize "${scaled_width}x${scaled_height}!" -threshold 85% -alpha on -transparent white -gravity south -background none -extent "${FRAME_WIDTH}x${FRAME_HEIGHT}" "$output_frame"
        preview_frames+=("$output_frame")
    done
done

montage "${preview_frames[@]}" -filter point -tile "${SHEET_COLUMNS}x${SHEET_ROWS}" -geometry '64x192+8+8' "$temporary_directory/contact-sheet.png"
magick "$temporary_directory/contact-sheet.png" -background '#B8D995' -alpha remove -alpha off "$OUTPUT/contact-sheet.png"
