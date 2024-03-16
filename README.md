# ZEAPAD-QMK-VIA

## Spesification
- STM32F401 as Microcontroller
- QMK Firmware
- Support VIA, all key and knob can proggrammed
- RGB Underglow
- 4x Layer 
- 16x Switch or 15x Switch + 1 Encoder or 14x Switch + 2 Encoder
- Hotswap Switch
- 3D Case 
- USB type C

## Download VIA
Link Download VIA(Pilih sesuai OS) : https://github.com/the-via/releases/releases
VIA WEB VERSION : https://usevia.app/

## Autodetect on VIA or you can load JSON File
- Connect your macropad to PC
- Open VIA
- In Tab Setting, enable "Show Design Tab"
- Open Design Tab
- Load file with name "zeapad_via_definitions.json" 
- Open Configure Tab to setting your macropad
- If nothing happend , do it again from first

## Preview Hardware
<p align="center">
  
  <img src="DOC/HARDWARE/3.png" width="25%" height="25%">
  <img src="DOC/HARDWARE/2.png" width="25%" height="25%">
  <img src="DOC/HARDWARE/1.png" width="25%" height="25%">
  <img src="DOC/HARDWARE/4.jpeg" width="25%" height="25%">
  <img src="DOC/HARDWARE/5.jpeg" width="25%" height="25%">
</p>

## Preview VIA
[![Positron Electronic on YouTube](http://img.youtube.com/vi/qvMjg3LCvkY/0.jpg)](http://www.youtube.com/watch?v=qvMjg3LCvkY "zeapad stm32")


## Cara Update/Upgrade Firmware
- Siapkan dahulu macropad, kabel usb dan firmware yang ingin di update/upgrade ke macropad anda
- Siapkan Firmware yang akan digunakan untuk update/upgrade
- Download Software QMK Toolbox di [link berikut](https://github.com/qmk/qmk_toolbox/releases)
- Install Software QMK Toolbox, Install Semua drivernya. setelah siap anda dapat meload Firmware yang seblumnya. Lalu Centang Auto-Flash seperti gambar dibawah
<p align="center">
  <img src="DOC/QMK Tollbox Awal.PNG" width="50%" height="50%">
</p>

- Colok kabel ujung usb type C ke macropad tanpa mencolokannya dahulu ke USB PC anda
- Tekan dan tahan tombol yang berada di ujung atas kiri. lalu colokan Ujung USB yang sebelum ke USB PC anda sambil tetap menahan tombol sebelum nya sebentar
- Setelah ada bunyi/notif USB masuk. anda dapat melepaskan tombol knobnya
- Maka secara otomatis macropad akan terflash. jika selesai maka tampilan QMK toolbox akan seperti gambar dibawah
<p align="center">
  <img src="DOC/Selesai Flash QMK Toolbox.PNG" width="50%" height="50%">
</p>


