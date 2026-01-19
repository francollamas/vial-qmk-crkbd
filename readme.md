# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Compilar y Flashear el Firmware

### Requisitos previos

1. Instalar Homebrew si no está instalado:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. Instalar QMK:
   ```bash
   curl -fsSL https://install.qmk.fm | sh
   ```

3. Instalar el toolchain ARM:
   ```bash
   brew install --cask gcc-arm-embedded
   ```

4. Si usas pyenv, reinstalar Python para que tenga soporte xz:
   ```bash
   pyenv uninstall 3.13.4
   pyenv install 3.13.4
   ```

### Compilar

Desde la raíz del proyecto (carpeta `vial-qmk-crkbd`):
```bash
make crkbd/r2g:vial
```

Se generará un archivo `.uf2` en la raíz del proyecto.

### Flashear

1. Conectar solo un lado del teclado (SIN cable TRRS).

2. Entrar al bootloader:
   - Presionar la tecla `QK_BOOT`
   - Si es necesario, limpiar la EEPROM con `QK_CLEAR_EEPROM`

3. Aceptar la nueva unidad de almacenamiento mount.

4. Arrastrar el archivo `.uf2` a la unidad. El teclado se reiniciará automáticamente.

5. Repetir el proceso con el otro lado del teclado.

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
