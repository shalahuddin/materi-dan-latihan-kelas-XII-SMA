# Hari 5: Praktikum Terstruktur & Quiz Evaluasi HOTS
## Pembuktian Penguasaan Fungsi dan Arsitektur Modular C

---

## 🎯 TUJUAN PEMBELAJARAN HARI 5
Setelah sesi evaluasi dan praktikum hari ini, kamu diharapkan dapat:
1. Mengintegrasikan pemahaman prinsip DRY, anatomi fungsi, prototipe, scope variabel, dan kompilasi multi-source secara komprehensif.
2. Menganalisis output program dengan penalaran mendalam (*Higher Order Thinking Skills*) pada kasus *Call by Value* dan *Variable Shadowing*.
3. Menyelesaikan soal kuis teori-analisis (15 poin) berstandar Taksonomi Bloom level C4 (Analisis) dan C5 (Evaluasi).
4. Membangun proyek praktikum mandiri multi-file (*Modular Student Utility Toolkit*, 25 poin) sesuai standar industri dan konvensi LABS.
5. Mendokumentasikan progress kode menggunakan Git lokal (minimal 2 commit) dan mengemas hasil pekerjaan dalam format arsip yang ditentukan.

---

## ⚡ REVIEW KILAT MINGGU 05 (Peta Konsep)

Sebelum membuka kuis dan editor kode, ingat kembali 4 pilar utama yang telah kita pelajari:

```
                                  [ FUNGSI DI C ]
                                         │
        ┌───────────────────┬────────────┴───────────┬───────────────────┐
        ▼                   ▼                        ▼                   ▼
  [ Anatomi & DRY ]   [ Call by Value ]       [ Scope & Shadow ]   [ Multi-File GCC ]
  - Return Type       - C menyalin nilai      - Lokal (Block)      - Header (.h)
  - Parameter         - Kertas asli aman      - Global (Bahaya!)   - Source (.c)
  - Body & return     - Prototipe di atas     - Shadowing lokal    - Include Guard
  - void vs bernilai  - main() di tengah      - Hindari global!    - gcc main.c mod.c
```

1. **Prinsip DRY**: Jangan tulis ulang kode komputasi lebih dari 2 kali. Satukan ke dalam fungsi!
2. **Anatomi & Prototipe**: Tipe kembalian, nama fungsi deskriptif, tipe parameter. Prototipe fungsi di atas `main()` adalah kontrak agar kompilator tidak bingung.
3. **Call by Value**: Parameter fungsi menerima salinan data. Variabel asli milik pemanggil tidak akan pernah terpengaruh oleh manipulasi lokal fungsi anak.
4. **Scope & Lifetime**: Variabel lokal hidup di dalam kurung kurawal `{ ... }` dan langsung musnah saat blok berakhir. Jika nama bertabrakan, variabel lokal akan menutupi (*shadowing*) variabel global.
5. **Pemrograman Modular**: Pisahkan kontrak publik (`.h` dengan include guard `#ifndef`) dan implementasi (`.c`). Kompilasi keduanya bersamaan: `gcc main.c utils.c -o app`.

---

## 📋 PREVIEW & KISI-KISI QUIZ MINGGUAN (15 Poin)

Quiz dilaksanakan selama **40 menit** dengan komposisi:
- **Bagian A (6 Soal Analisis Singkat - Bobot 6 Poin)**: Menelusuri (*tracing*) nilai variabel pada Call by Value dan memprediksi keluaran program.
- **Bagian B (3 Soal Evaluasi Kasus / C5 - Bobot 6 Poin)**: Mengidentifikasi bug arsitektur, kesalahan penempatan kode, atau kegagalan kompilator pada multi-file.
- **Bagian C (1 Soal Desain Prototipe Mini / C6 - Bobot 3 Poin)**: Merancang header dan prototipe fungsi untuk modul nyata.

### Contoh Perbandingan Soal: LOTS vs HOTS

#### Contoh Soal Hafalan (LOTS - Kurang Menantang)
> *Pertanyaan:* Apa singkatan dari prinsip DRY dan sebutkan tipe fungsi yang tidak mengembalikan nilai!  
> *Jawaban:* Don't Repeat Yourself dan void.  
> *(Catatan: Soal seperti ini hanya menguji memori hafalan teks, bukan kemampuan berpikir kritis).*

#### Contoh Soal HOTS 1 (Tingkat C4: Analisis Tracing Call by Value)
> **Soal:** Perhatikan potongan program berikut:
> ```c
> void ubah_data(int a, int b) {
>     a = a + 5;
>     b = b * 2;
> }
> 
> int main() {
>     int a = 10, b = 4;
>     ubah_data(b, a); // Perhatikan posisi argumen!
>     printf("a = %d, b = %d\n", a, b);
>     return 0;
> }
> ```
> *Pertanyaan:* Berapakah nilai `a` dan `b` yang tercetak di layar? Jelaskan langkah analisis memorimu!  
> 
> *Kunci & Pembahasan:*  
> **Output:** `a = 10, b = 4`.  
> **Alasan Analisis:**  
> 1. Terjadi pemanggilan `ubah_data(b, a)`, di mana nilai `b` (4) disalin ke parameter `a` fungsi, dan nilai `a` (10) disalin ke parameter `b` fungsi.  
> 2. Di dalam fungsi, salinan tersebut dimanipulasi: `a` lokal menjadi 9 dan `b` lokal menjadi 20.  
> 3. Namun, karena mekanisme **Call by Value**, variabel asli `a` dan `b` di dalam `main()` tidak terpengaruh sama sekali. Ketika fungsi selesai, stack frame dibuang, dan nilai `a` serta `b` di `main()` tetap 10 dan 4.

#### Contoh Soal HOTS 2 (Tingkat C5: Evaluasi Arsitektur Multi-File)
> **Soal:** Seorang programmer junior membuat dua file: `hitung.h` dan `main.c`. Di dalam `hitung.h`, ia menuliskan:
> ```c
> // hitung.h
> int kali_dua(int x) {
>     return x * 2;
> }
> ```
> Lalu di terminal ia mengetik: `gcc main.c -o app`. Jika `main.c` me-include `hitung.h`, program berhasil jalan. Namun saat programmer lain membuat file baru `admin.c` yang juga me-include `hitung.h` dan mengompilasi `gcc main.c admin.c -o app`, kompilator melempar error *multiple definition of 'kali_dua'*.  
> 
> *Pertanyaan:* Evaluasi kesalahan desain yang dilakukan programmer junior tersebut dan jelaskan perbaikan yang harus dilakukan!  
> 
> *Kunci & Pembahasan:*  
> **Evaluasi:** Programmer junior melanggar prinsip dasar header file dengan menaruh **badan fungsi (implementasi)** di dalam file `.h`. Ketika dua file `.c` berbeda me-include header tersebut, kode implementasi fungsi `kali_dua` disalin dua kali ke dalam unit kompilasi yang berbeda, sehingga saat tahap linking (*ld*) terjadi bentrok duplikasi simbol.  
> **Perbaikan:**  
> 1. Pindahkan badan fungsi `{ return x * 2; }` ke dalam file baru `hitung.c`.  
> 2. Di dalam `hitung.h`, sisakan hanya prototipe fungsinya saja: `int kali_dua(int x);` dibungkus include guard.  
> 3. Kompilasi ketiga file bersamaan: `gcc main.c admin.c hitung.c -o app`.

---

## 🛠️ PANDUAN PRAKTIKUM MINGGU 05 (Bobot: 25 Poin)

Hari ini kamu akan mengerjakan **Praktikum Mandiri: Modular Student Utility Toolkit**.
- **Waktu Pengerjaan**: 140 Menit.
- **Sifat**: Mandiri (*Individual Hands-on*).
- **Environment Wajib**: Terminal GCC lokal di VS Code (bukan OnlineGDB).
- **Detail Tugas Lengkap**: Buka file `Praktikum_Minggu_05_Modular_Math_and_Student_Toolkit.md`.

### Ringkasan Pekerjaan Praktikum:
Kamu diminta membangun sistem toolkit siswa berbasis 3 file terpisah:
1. `student_utils.h`: Berisi konstanta predikat KKM, include guard, dan prototipe fungsi konversi nilai, validasi kehadiran, serta kalkulasi bobot kelulusan.
2. `student_utils.c`: Berisi implementasi logika murni dari semua prototipe.
3. `toolkit_main.c`: Program driver utama yang menampilkan antarmuka konsol rapi, menerima input pengguna, dan menampilkan laporan akademik siswa.

---

## 📦 PANDUAN STANDAR PENGUMPULAN LABS

Setiap karya praktikum di SMA LABS wajib mematuhi standar kerapian industri:

### 1. Header Komentar Wajib pada Setiap File `.c` dan `.h`
```c
/*
 * File: toolkit_main.c
 * Week: 05 - Functions & Modular Programming
 * Author: [Nama Lengkap Siswa] (Kelas XII-X / No. Absen)
 * Date: 2026-10-XX
 * Description: Program utama pengujian Modular Student Utility Toolkit
 *
 * Attribution:
 * - Dikembangkan mandiri berdasarkan materi Week 05 LABS.
 *
 * Integrity Statement:
 * Kode ini adalah hasil karya saya sendiri tanpa plagiasi.
 */
```

### 2. Standar Gaya Kode (Code Style)
- Indentasi konsisten: **4 spasi** (dilarang mencampur tab dan spasi).
- Penamaan variabel dan fungsi: **`snake_case`** bermakna (`hitung_kkm`, bukan `hk` atau `fungsi1`).
- Spasi rapi di sekitar operator matematika dan logika: `a + b * c`, bukan `a+b*c`.

### 3. Version Control (Git Tracking)
Lakukan pelacakan commit selama pengerjaan praktikum di terminal:
```powershell
git init
git add .
git commit -m "feat: inisialisasi header modul dan prototipe fungsi"
# ... lanjutkan koding implementasi dan main ...
git add .
git commit -m "feat: implementasi lengkap modul utilitas dan pengujian main"
```

### 4. Format Kemasan ZIP
Kemas seluruh folder proyekmu ke dalam arsip ZIP dengan format:
`[Nama_Lengkap]_Minggu05_Functions.zip`

Isi dalam folder ZIP:
```
[Nama_Lengkap]_Minggu05_Functions/
├── student_utils.h
├── student_utils.c
├── toolkit_main.c
├── README.md (berisi petunjuk kompilasi & screenshot output)
└── git_log.txt (hasil perintah: git log --oneline > git_log.txt)
```

---

## 🔮 SNEAK PEEK MINGGU 06: STRUKTUR PERULANGAN (LOOPS)
Minggu depan kita akan memasuki babak baru yang sangat bertenaga: **Loops (`for`, `while`, `do-while`)**! Kamu akan belajar bagaimana menggabungkan fungsi yang telah kamu pelajari minggu ini agar dapat dieksekusi ratusan bahkan jutaan kali secara otomatis dalam hitungan milidetik!

---

## ✅ CHECKLIST KEBERHASILAN MINGGU 05
Sebelum menutup hari ini, periksa apakah kamu sudah menyelesaikan seluruh target:
- [ ] Telah membaca dan memahami materi Hari 1 s.d. 4.
- [ ] Mampu menjawab soal analisis tracing Call by Value dan Scope tanpa ragu.
- [ ] Telah menyelesaikan Quiz Mingguan 15 Poin.
- [ ] Proyek praktikum `student_utils` terbagi rapi dalam file `.h` dan `.c`.
- [ ] Program praktikum berhasil dikompilasi di terminal lokal tanpa satu pun peringatan (*zero warnings*).
- [ ] Minimal 2 commit Git tercatat di repository lokal.
- [ ] File ZIP sudah terkompres rapi dan siap dikumpulkan ke instruktur.

---

**"Ujian terbesar seorang programmer bukan saat kompilator berkata 'Success', melainkan saat arsitektur kodenya mampu dibaca, dipahami, dan dikembangkan oleh orang lain." 🏆**
