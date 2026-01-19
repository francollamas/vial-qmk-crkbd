# AGENTS.md - QMK Vial Corne Keyboard Development Guide

This document provides guidelines and instructions for agentic coding agents working on this QMK firmware repository for the Corne (CRKBD) keyboard with Vial support.

## Build Commands

### Building the Keyboard

```bash
# Build the default keymap
make crkbd:vial

# Build with verbose output
make crkbd:vial VERBOSE=yes

# Clean build artifacts
make clean

# Full clean including hex/bin files
make distclean
```

### Running Tests

```bash
# List all available tests
make list-tests

# Run all tests
make test:all

# Run a specific test (replace <test_name> with actual test)
make test:<test_name>

# Run test with debug output
make test:<test_name> DEBUG=yes
```

Available tests include: `basic`, `auto_shift`, `caps_word`, `combo`, `encoder`, `keycode_string`, `layer_lock`, `leader`, `mousekeys`, `pointing`, `repeat_key`, `tap_dance`, `tap_hold_configurations`, `debounce_*`, `wear_leveling_*`, and more.

### Python/CLI Commands

```bash
# Format C code (requires Docker)
make format-core

# Run pytest suite (requires Docker)
make pytest

# Format and test together (requires Docker)
make format-and-pytest
```

## Code Style Guidelines

### License Headers

All source files must include the GNU GPLv2 license header:

```c
/*
 Copyright <year> <author>

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
 */
```

### Header Guards

Use `#pragma once` for header files instead of traditional include guards:

```c
#pragma once
```

### Keymap Files

Keymap files follow QMK conventions:

```c
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        /* key definitions */
    ),
    [1] = LAYOUT_split_3x6_3(
        /* key definitions */
    ),
};
```

### Include Order

Follow this include order:
1. `#include QMK_KEYBOARD_H` (first for keymap files)
2. Standard library headers (`<stdio.h>`, `<string.h>`, etc.)
3. QMK/Quantum headers (`quantum.h`, `quantum_keycodes.h`, etc.)
4. Keyboard-specific headers
5. Feature-specific includes (wrapped in `#ifdef`)

```c
#include QMK_KEYBOARD_H

#include <stdio.h>

#include "quantum.h"
#include "quantum_keycodes.h"

#ifdef OLED_ENABLE
#    include <stdio.h>
#endif
```

### Naming Conventions

- **Constants/Macros**: Uppercase with underscores (`RGBLIGHT_HUE_STEP`)
- **Functions**: Snake case, descriptive (`oled_render_layer_state`)
- **Variables**: Snake case (`keylog_str`, `layer_state`)
- **Keymap Layers**: Define constants for layer indices (`#define L_BASE 0`)
- **Keycodes**: Use QMK keycode defines (`KC_TAB`, `KC_LCTL`, `QK_BOOT`)
- **Keyboard Names**: Use `keyboard_name:keymap_name` format (`crkbd:vial`)

### Config.h Guidelines

- Use `#undef` before redefining macros
- Define Vial-specific options at the top
- Use `#ifdef` guards for conditional features
- Comment hand selection (MASTER_LEFT/MASTER_RIGHT)

```c
#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}

#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 42
#endif
```

### Rules.mk Configuration

- Enable features with `FEATURE_ENABLE = yes`
- Disable with `FEATURE_ENABLE = no`
- Use `EXTRAFLAGS` for compiler options
- Group related settings together

```makefile
VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes
EXTRAFLAGS += -flto=auto

MOUSEKEY_ENABLE     = no
OLED_ENABLE         = yes
```

### Quantum Keycodes

Use QMK quantum keycodes for advanced features:
- `QK_BOOT` - Bootloader reset
- `QK_LAYER_TAP` - Layer tap toggle
- `QK_MOD_TAP` - Modifier tap toggle
- `RGB_TOG`, `RGB_MOD`, `RGB_HUI`, etc. - RGB control

### Process Record Functions

For keycode handling, implement `process_record_user`:

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Handle key press
    }
    return true; // Return false to skip default handling
}
```

### OLED Functions

Implement OLED rendering functions:

```c
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
```

### Memory Constraints

- Use `PROGMEM` for data stored in flash memory
- Use `pgm_read_*` for reading PROGMEM data
- Use `pgm_read_ptr()` for pointers in PROGMEM
- Use `F()` macro for string literals in flash
- Use `PSTR()` for program memory strings

```c
static const char PROGMEM logo[] = {0x00, 0x80, 0xc0, ...};
oled_write_P(PSTR("Layer: "), false);
```

### Feature Flags

Common feature flags used in this project:
- `VIA_ENABLE` - Via compatibility
- `VIAL_ENABLE` - Vial compatibility
- `LTO_ENABLE` - Link-time optimization
- `OLED_ENABLE` - OLED display support
- `RGBLIGHT_ENABLE` - Underglow RGB
- `RGB_MATRIX_ENABLE` - Per-key RGB
- `ENCODER_ENABLE` - Rotary encoder support
- `POINTING_DEVICE_ENABLE` - Trackpad/trackball

## Project Structure

```
vial-qmk-crkbd/
├── keyboards/crkbd/          # Keyboard definitions
│   ├── keymaps/vial/         # Vial keymap
│   │   ├── keymap.c          # Keymap definition
│   │   ├── config.h          # Keyboard configuration
│   │   ├── rules.mk          # Build rules
│   │   └── vial.json         # Vial configuration
│   └── r2g/                  # Rev2 to Glow variant
├── quantum/                  # QMK core functionality
├── tmk_core/                 # TMK keyboard core
├── tests/                    # Unit tests
└── builddefs/                # Build definitions
```

## Important Notes

1. **Bootloader**: QK_BOOT triggers Vial's bootloader, not the standard QMK one
2. **Vial Combos**: Define unlock combos in config.h for security features
3. **Dynamic Keymap**: Vial supports runtime keymap changes via USB
4. **Matrix Size**: This keyboard uses 8x6 matrix (48 keys per side)
5. **Serial Communication**: Uses split keyboard protocol with serial communication

## Working with QMK CLI

For full QMK functionality, install the QMK CLI:
```bash
pip install qmk
qmk setup
```

Then use `qmk compile -kb crkbd -km vial` as an alternative to make.

## Error Handling

- Check return values from QMK API functions
- Use `dprintf()` for debug output when `DEBUG` is enabled
- Follow firmware conventions for error recovery
- Use `#ifdef DEBUG` blocks for development code
