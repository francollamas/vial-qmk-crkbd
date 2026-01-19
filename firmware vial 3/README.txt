Instrucciones para compilar el firmware QMK + Vial para el Corne Keyboard

1. Clonar el repositorio de Vial-QMK

sudo apt install pipx git make gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi
git clone https://github.com/vial-kb/vial-qmk.git
cd vial-qmk

2. Reemplazar la carpeta keyboards

Descomprimir keyboards.zip y copiar la carpeta keyboards dentro de ./vial-qmk, reemplazando todos los archivos.

3. Preparar el entorno

pipx install qmk
pipx ensurepath
source ~/.bashrc
make git-submodules

4. Compilar el firmware

make crkbd/r2g:vial

5. Ubicación del archivo compilado

El archivo .uf2 generado se guardará en la carpeta ./vial-qmk.


Instrucciones para flashear el archivo .uf2 en el Corne Keyboard

1. Desconectar el cable USB y el cable TRRS.
2. Quitar la tapa del microcontrolador.
3. Mantener presionado el botón superior (el más cercano al USB) y conectar ese lado a la PC sin soltar el botón.
4. La PC detectará una nueva unidad de almacenamiento. Arrastrar el archivo .uf2 dentro de esa unidad. El dispositivo se reiniciará automáticamente.
5. Repetir el procedimiento para el otro lado.
6. Listo, el Corne Keyboard ya está listo para usar con Vial.
