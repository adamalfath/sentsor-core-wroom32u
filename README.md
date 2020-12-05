# SENTSOR Core Board WROOM-32U
## Introduction
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img0.jpg" width="600">  

Kebutuhan performa tinggi dari device IoT dibutuhkan untuk membantu proses penerjemahan aksi menjadi informasi ataupun sebaliknya, terlebih jika device tersebut dijadikan sebagai master gateway bagi node-node lain yang berada disekitarnya. Interkoneksi peripheral dengan macam-macam protokol komunikasi, jumlah I/O dari device, ataupun pengolahan data in-situ sebelum dilempar ke node berikutnya dapat menyederhanakan alur kerja serta mereduksi cost akan modul-modul tambahan. Menjawab kebutuhan itu, SENTSOR Core Board WROOM-32U hadir dengan varian development board yang siap di embed dalam tantangan tersebut.

Dibekali dengan chip ESP32 dual core CPU dengan clock up to 240MHz dengan on-chip 520kB SRAM dan 4MB memory flash yang memanjakan hampir semua kebutuhan processing at edge. Untuk hal interkomunikasi, chip yang dikemas dalam modul WROOM-32U ini menghadirkan konektivitas wireless kombo WiFi, bluetooth (classic) dan bluetooth low energy (BLE), serta interkoneksi wired umum seperti SPI, I2C, I2S, UART dan GPIO. Dipadukan dengan fitur utama dari board SENTSOR yaitu RTC presisi DS3231 yang tentunya mempunyai kapabilitas sinkronisasi terhadap NTP untuk timestamp akurat, serta adapter memory card ukuran MicroSD untuk keperluan penyimpanan data lokal. Tanpa melupakan power management, dengan semua fitur yang dikemas dalam ukuran mini (~6x4cm), board ini hanya mengkonsumsi arus idle sebesar 172uA. Dipadukan dengan on-board BMS (charger + proteksi) menjadikan SENTSOR Core Board WROOM-32U kompatibel untuk dijadikan perangkat remote yang self-sustained.

## Features
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-pinoutposter.jpg" width="600">  
  
- **Compact & powerful**, 58.42x40.64mm (2300x1600mil) dengan MCU+RTC+uSD+BMS onboard.  
- **2x18P pinout layout**, pitch 2.54mm (100mil), dengan susunan 1 sisi untuk peripheral (power, programming, communication) dan 1 sisi untuk GPIO, mempermudah manajemen jalur/kabel yang akan digunakan.  
- **Castellated holes & pin header**, pilihan koneksi untuk mempermudah pengaplikasian board SENTSOR Core pada setiap kebutuhan.  
- **ESP32 SOC**, Dual Core 32-bit MCU, ULP co-processor dan 4MB flash dengan clock up to 240MHz.  
- **802.11b/g/n WiFi connectivity**, support mode STA/AP/STA+AP dengan antena external via konektor U.FL/IPEX memungkinkan board SENTSOR Core WROOM-32U ditanam didalam enclosure metal tanpa menggangu kualitas sinyal transceiver.  
- **Bluetooth 4.2 connectivity**, support protokol bluetooth classic dan Low Energy (LE).  
- **Low Power**, down to 52uA (deep sleep ESP32 only), 172uA (deep sleep ESP32+DS3231) dan 37.2mA (modem sleep ESP32 @240MHz+DS3231).  
- **DS3231 Extremely Accurate RTC**, terhubung via I2C pada alamat 0x68.  
- **MicroSD socket**, terhubung via SPI dengan slave select (SS) pada pin IO5.  
- **Built-in LED**, terhubung pada pin IO2, konfigurasi active-low.  
- **Auto-reset trigger**, memudahkan penggantian boot mode saat proses upload firmware dengan pin kontrol DTR dan RTS.  
- **Battery Powered**, jalankan board SENTSOR Core WROOM-32U dimana saja tanpa masalah power dengan Li-ion 1S via konektor JST-PH.  
- **TP4054 Battery Charger**, charge baterai dengan arus up to 500mA.  
- **DW01A Battery Protection**, pengamanan saat penggunaan baterai terhadap overcharge, overdischarge, overcurrent, dan short circuit.  
- **ME6211 LDO**, dengan VIN max. 6V dan IOUT max. 500mA. Kompatibel untuk dihubungkan dengan solar cell sebagai power input charger.  
- **18 pin GPIO** @3V3 level, 3xUART, 2xSPI, 2xI2C, 2xI2S, 12bit ADC, 8bit DAC, hall-effect sensing, capacitive sensing dll. Silahkan lihat gambar diatas untuk lebih lanjut.  
- **Built-in Voltage Divider**, 0.1% precision resistor divider rasio 1/2 pada pin ADC yang terhubung ke internal I35 memungkinkan untuk melakukan sensing tegangan up to 6.6V. Kompatibel untuk monitoring tegangan VBAT sebagai metode estimasi kapasitas baterai.  

## How to Use
### Programming & Uploading Firmware
SENTSOR Core Board WROOM-32U memerlukan programmer external (USB to UART) untuk mengupload firmwarenya seperti FT232, CH340, CP2102, PL2303, dll. Untuk melakukan proses upload firmware, hubungkan chip programmer dengan board SENTSOR seperti berikut:
|Programmer|SENTSOR board|
|-|-|
|+3V3 (atau +5V)|+3V3 (atau VIN)|
|GND|GND|
|TX|RX|
|RX|TX|
|DTR|DTR|
|RTS|RTS|

Selanjutnya pilih board _ESP32 Dev Module_. Beberapa hal yang perlu diperhatikan yaitu ESP32 WROOM-32U memiliki ukuran flash sebesar 4MB (silahkan pilih kombinasi alokasi partisi sesuai keperluan), dan tanpa PSRAM. Setelah itu SENTSOR Core Board WROOM-32U dapat digunakan sebagaimana development board pada umumnya. 

<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-arduinoideinfo.png" width="600">  

### Dependency
Arduino IDE memerlukan ESP32 Core untuk bisa melakukan pemrograman terhadap chip ESP32. Silahkan ikuti instruksi [ini](https://github.com/espressif/arduino-esp32) untuk melakukan instalasi ESP32 Core untuk Arduino IDE, untuk IDE lain menyesuaikan sesuai instruksi masing-masing.

File example yang disediakan memiliki library dependency terkait RTC yaitu:
- RTCLib https://github.com/adafruit/RTClib  
- SdFat https://github.com/greiman/SdFat  

Silahkan install library tersebut jika dibutuhkan dalam program yang akan kalian buat.  

### Battery Powered
SENTSOR Core Board WROOM-32U dapat dijalankan dengan menggunakan battery Li-ion 1S (3.7V-4.2V) via konektor JST-PH. Proses charging dapat dilakukan langsung on-board dengan cara mensupply daya via pin VIN (max. 6V).  

> **:warning: Perhatian!**  
> Harap perhatikan secara seksama polaritas dari konektor baterai agar sama dengan yang tertera pada board (terdapat tulisan +/- pada silkscreen). Dikarenakan konektor ini belum distandarisasi maka memungkinkan baterai yang akan digunakan memiliki susunan polaritas berbeda (positif di pin 1 & negatif di pin 2 atau sebaliknya).

### On-board Jumper Pad
SENTSOR Core Board WROOM-32U memiliki 2 buah jumper pad:
- Jumper JP1 menghubungkan VBAT dengan ADC yang selanjutnya terhubung ke pin I35 via voltage divider.
- Jumper JP2 menghubungkan IO4 dengan gate Q4 sebagai switching power VIN (konfigurasi active-high). Saat IO4 aktif (high/1), supply daya dari VIN akan diputus sehingga modul beralih menggunakan VBAT, berguna saat operasi yang membutuhkan supply daya yang reliable dari baterai.  

Untuk informasi lebih lengkap silahkan lihat pada file skematik.  

## Bill of Materials
|Designator|Qty|Name/Value|Footprint|
|-|-|-|-|
|U1|1|ESP32-WROOM-32U|ESP32-WROOM-32U|
|U2|1|ME6211C33|SOT-23-5|
|U3|1|TP4054|SOT-23-5|
|U4|1|DW01A|SOT-23-6|
|U5|1|DS3231SN#|SOIC-16_300MIL|
|R2,R1|2|100k|R0603|
|R19|1|100k|R0402|
|R9,R11|2|10k|R0603|
|R15,R12,R14,R13|4|10k|R0402|
|R16,R17|2|4.7k|R0603|
|R10,R3,R6,R4|4|1k|R0603|
|R5|1|100|R0603|
|R18|1|100|R0402|
|R7,R8|2|300k, 0.1%|R0603|
|C4,C6|2|10u|C0603|
|C7|1|10u|C0402|
|C1,C2|2|1u|C0603|
|C10|1|1u|C0402|
|C5|1|100n|C0603|
|C9,C11,C8,C12|4|100n|C0402|
|C3|1|330u, 4V|CASE-B_3528|
|Q4,Q1|2|CJ2301|SOT-23-3|
|Q2|1|SL8205S|SOT-23-6|
|Q3|1|UMH3N|SC-70-6|
|D1|1|B5819W|SOD-123|
|LED1|1|Blue|LED0603|
|LED2|1|White|LED0603|
|RST|1|Tact Switch|3x4x2_SMD|
|CN1|1|JST-PH, 2P|PH-2P_P2.00_SMD|
|CARD1|1|TF-115K|TF-115K|
|B1|1|CR1220|BAT_CR1220_SMD|  
  
## Design 
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-pcb-ss.png" width="600">  

SENTSOR Core Board WROOM-32U merupakan open source hardware, silahkan dimanfaatkan secara bijaksana.  

Link: https://easyeda.com/sentsor-project/sentsor-core-wroom-32u  

## Gallery
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img1.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img2.jpg" width="400">  
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img3.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img4.jpg" width="400">  
<img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img5.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-core-wroom32u/blob/main/media/core32u-img6.jpg" width="400">  

## Support Open-Source Hardware & SENTSOR!
Bila kalian tertarik dengan produk-produk SENTSOR, kalian bisa cek marketplace ataupun memberikan donasi pada link berikut:  

[![Store](https://img.shields.io/badge/marketplace-Tokopedia-brightgreen.svg)](https://www.tokopedia.com/gerai-sagalarupa/etalase/sentsor-product)  [![Donate](https://img.shields.io/badge/donate-PayPal-blue.svg)](https://www.paypal.me/adamalfath)  

Support kalian akan sangat membantu untuk pengembangan open-source hardware dari SENTSOR selanjutnya.

## Information
SENTSOR  
Author: Adam Alfath  
Contact: adam.alfath23@gmail.com  
Web: [sentsor.net](http://www.sentsor.net)  
Repo: [SENTSOR Main Repo](http://github.com/adamalfath/sentsor)

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/80x15.png"/></a><br/>
SENTSOR Core Board WROOM-32U is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
