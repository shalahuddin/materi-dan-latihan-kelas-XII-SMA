# Hari 4: Pemrograman Modular, Header File, & Multi-Source GCC
## Separation of Concerns: Arsitektur Proyek Skala Industri

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Memahami prinsip **Separation of Concerns (Pemisahan Tanggung Jawab)** dalam arsitektur rekayasa perangkat lunak.
2. Membedakan fungsi file header (`.h`) sebagai antarmuka/kontrak publik dan file sumber (`.c`) sebagai implementasi logika.
3. Menjelaskan perbedaan direktif preprosesor `#include <...>` (standar sistem) dengan `#include "..."` (proyek lokal).
4. Menerapkan **Include Guards (`#ifndef`, `#define`, `#endif`)** untuk mencegah bahaya *double inclusion* dan redefinisi kode.
5. Melakukan kompilasi multi-source file secara mandiri menggunakan terminal kompilator GCC (`gcc main.c modul.c -o output`).

---

## 💡 MATERI PEMBELAJARAN

### 1. Mengapa Kita Butuh Pemrograman Modular?
Bayangkan kamu bekerja di tim pengembang game atau sistem operasi. Proyek tersebut memiliki lebih dari 100.000 baris kode. Jika seluruh kode tersebut ditaruh di dalam satu file raksasa `main.c`:
- **Sulit Dikelola**: Menggulir file butuh waktu lama, mencari letak bug terasa seperti mencari jarum di tumpukan jerami.
- **Konflik Kerja Tim (Git Merge Conflict)**: Jika 5 programmer mengedit file `main.c` yang sama pada saat bersamaan, proses penggabungan kode (*merge*) akan menjadi bencana.
- **Waktu Kompilasi Lambat**: Setiap kali ada perubahan kecil 1 karakter, seluruh 100.000 baris harus dikompilasi ulang dari awal.

> ⭐ **Solusi: Pemrograman Modular & Separation of Concerns**  
> Pecahlah program monolitik besar menjadi modul-modul kecil independen.  
> Setiap modul fokus pada satu domain tugas tertentu: misalnya modul kalkulasi matematika, modul pengelolaan user, modul tampilan layar.

---

### 2. Triad Struktur Proyek C Profesional
Dalam ekosistem C standar industri, setiap modul perangkat lunak dibagi menjadi 3 berkas:

```
proyek_kalkulator/
├── kalkulator.h    <-- KONTRAK / ANTARMUKA (Apa saja fungsi yang tersedia?)
├── kalkulator.c    <-- IMPLEMENTASI (Bagaimana cara kerja fungsi tersebut?)
└── app_main.c      <-- PROGRAM UTAMA (Konsumen yang menggunakan fungsi)
```

Mari kita bedah masing-masing perannya:

#### A. File Header (`.h`) — "Buku Menu Restoran"
File header berisi deklarasi apa saja yang boleh dilihat dan dipakai oleh pihak luar:
- Prototipe fungsi (hanya nama, parameter, dan return type).
- Konstanta penting (`#define PI 3.14159`).
- File ini **TIDAK BOLEH** berisi implementasi algoritma (tidak ada kurung kurawal badan fungsi).

#### B. File Implementasi (`.c`) — "Dapur Koki Restoran"
File ini berisi kode nyata dari seluruh fungsi yang dijanjikan pada file header.
- Wajib me-include header-nya sendiri: `#include "kalkulator.h"`.
- Tempat seluruh rumus, logika percabangan, dan algoritma bekerja.

#### C. File Driver Utama (`main.c`) — "Pelanggan di Meja Makan"
File yang berisi fungsi `main()`. File ini cukup membaca menu dengan `#include "kalkulator.h"`, lalu memanggil fungsi-fungsi tersebut tanpa perlu tahu kerumitan rumus di baliknya.

---

### 3. Perbedaan `#include <...>` vs `#include "..."`
Perhatikan tanda kurung yang digunakan saat melakukan `#include`:

| Sintaks | Kapan Digunakan? | Jalur Pencarian Kompilator |
|---|---|---|
| `#include <stdio.h>` | Untuk pustaka standar bahasa C (*standard library*). | Mencari di folder instalasi GCC bawaan sistem (C:\MinGW\include atau sejenisnya). |
| `#include "kalkulator.h"` | Untuk modul buatanmu sendiri di dalam folder proyek. | Mencari terlebih dahulu di direktori lokal tempat file `.c` saat ini berada. |

---

### 4. ⭐ Include Guards: Tameng Pelindung dari Double Inclusion
Jika sebuah file header di-include lebih dari satu kali secara tidak sengaja (misalnya file A include B, file C include A dan B), kompilator akan melihat deklarasi ganda dan melemparkan error *redefinition*.

Untuk mencegah hal ini, setiap file header **WAJIB** dibungkus dengan **Include Guard**:

```c
#ifndef NAMA_FILE_H
#define NAMA_FILE_H

// --- Seluruh prototipe dan konstanta diletakkan di sini ---

#endif // NAMA_FILE_H
```

**Cara Kerja Include Guard:**
1. `#ifndef KALKULATOR_H` (*if not defined*): Cek apakah identifier `KALKULATOR_H` belum pernah didefinisikan sebelumnya.
2. Jika belum, `#define KALKULATOR_H` langsung menandai tanda tersebut di memori preprosesor.
3. Seluruh isi header dibaca oleh kompilator.
4. Jika file ini di-include kedua kalinya, preprosesor melihat `KALKULATOR_H` sudah ada, sehingga melompati seluruh isi header hingga `#endif`!

---

### 5. ⭐ Mengompilasi Proyek Multi-File dengan GCC

Perhatikan aturan mutlak kompilasi di terminal:

> ⚠️ **Miskonsepsi Fatal Pemula:**  
> Banyak siswa mengetik: `gcc main.c kalkulator.h -o program` *(SALAH BESAR!)*  
> File `.h` tidak pernah dikompilasi langsung di terminal karena sudah disisipkan oleh preprosesor ke dalam file `.c`.

**Perintah Kompilasi yang Benar:**
Sebutkan seluruh file sumber `.c` yang terlibat:

```powershell
gcc app_main.c kalkulator.c -o program_kalkulator
.\program_kalkulator.exe
```

Jika kamu lupa menyebutkan `kalkulator.c`, kompilator akan berhasil di tahap kompilasi tetapi gagal di tahap *Linker* dengan pesan error legendaris:
```text
undefined reference to 'hitung_tambah'
collect2.exe: error: ld returned 1 exit status
```
Pesan ini artinya: *"Hai programmer, kamu menjanjikan ada fungsi hitung_tambah di header, tapi saya cari di file-file .c yang kamu serahkan, kodenya tidak ditemukan!"*

---

## 💻 LIVE CODING DEMO

Mari kita bangun proyek modular nyata berupa modul penghitung diskon dan voucher kantin LABS.

### File 1: `06_calc_utils.h` (File Header)
```c
/*
 * File: 06_calc_utils.h
 * Description: Header kontrak modul kalkulator utilitas LABS
 */

#ifndef CALC_UTILS_H
#define CALC_UTILS_H

// Konstanta publik
#define TARIF_PAJAK_PPN 11
#define MINIMAL_GRATIS_ONGKIR 100000

// Prototipe Fungsi
int hitung_subtotal(int harga_satuan, int jumlah);
int hitung_pajak(int total_belanja);
int hitung_ongkos_kirim(int total_belanja);
void cetak_garis_pemisah(void);

#endif // CALC_UTILS_H
```

### File 2: `06_calc_utils.c` (File Implementasi)
```c
/*
 * File: 06_calc_utils.c
 * Description: Implementasi algoritma modul kalkulator utilitas LABS
 */

#include <stdio.h>
#include "06_calc_utils.h" // Sertakan kontrak header sendiri

int hitung_subtotal(int harga_satuan, int jumlah) {
    return harga_satuan * jumlah;
}

int hitung_pajak(int total_belanja) {
    return total_belanja * TARIF_PAJAK_PPN / 100;
}

int hitung_ongkos_kirim(int total_belanja) {
    if (total_belanja >= MINIMAL_GRATIS_ONGKIR) {
        return 0; // Bebas ongkir!
    } else {
        return 15000; // Tarif reguler
    }
}

void cetak_garis_pemisah(void) {
    printf("----------------------------------------\n");
}
```

### File 3: `06_modular_calc_main.c` (Program Utama)
```c
/*
 * File: 06_modular_calc_main.c
 * Description: Program utama yang mengonsumsi modul kalkulator utilitas
 *
 * Compile:
 *   gcc 06_modular_calc_main.c 06_calc_utils.c -o kasir_modular
 *   .\kasir_modular.exe
 */

#include <stdio.h>
#include "06_calc_utils.h" // Cukup panggil header modul!

int main() {
    cetak_garis_pemisah();
    printf("   APLIKASI KASIR MODULAR SMA LABS      \n");
    cetak_garis_pemisah();

    int harga_buku = 45000;
    int jumlah_beli = 3;

    int subtotal = hitung_subtotal(harga_buku, jumlah_beli);
    int pajak = hitung_pajak(subtotal);
    int ongkir = hitung_ongkos_kirim(subtotal);
    int grand_total = subtotal + pajak + ongkir;

    printf("Item         : Buku Pemrograman C\n");
    printf("Subtotal     : Rp%d\n", subtotal);
    printf("PPN (%d%%)    : Rp%d\n", TARIF_PAJAK_PPN, pajak);
    printf("Ongkos Kirim : Rp%d (%s)\n", ongkir, ongkir == 0 ? "PROMO FREE" : "REGULER");
    cetak_garis_pemisah();
    printf("TOTAL BAYAR  : Rp%d\n", grand_total);
    cetak_garis_pemisah();

    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1: Eksekusi Kompilasi Multi-File Mandiri (25 menit)
Buka terminal VS Code di folder `code_examples/`.
1. Jalankan kompilasi multi-source:
   ```powershell
   gcc 06_modular_calc_main.c 06_calc_utils.c -o kasir_modular
   .\kasir_modular.exe
   ```
2. Eksperimen sengaja membuat error: Coba ketik hanya `gcc 06_modular_calc_main.c -o tes`. Baca dan amati pesan error linker yang muncul. Dokumentasikan artinya!

### Latihan 2: Membangun Modul Geometri Fisika (35 menit)
Buatlah modul geometri untuk perhitungan fisika SMA:
1. `fisika_geo.h`: Berisi `#define PHI 3.14159` dan prototipe fungsi:
   - `float luas_lingkaran(float radius);`
   - `float keliling_lingkaran(float radius);`
2. `fisika_geo.c`: Berisi implementasi rumus.
3. `main_fisika.c`: Berisi `main()` yang memanggil kedua fungsi tersebut dengan radius $r = 7.0$ dan $r = 10.0$.

### Latihan 3: Menyelidiki Bahaya Tanpa Include Guard (30 menit)
Buat sebuah header `pesan.h` yang mendeklarasikan suatu konstanta. Include file `pesan.h` dua kali di file `test.c`:
```c
#include "pesan.h"
#include "pesan.h"
```
Ujilah versi tanpa `#ifndef` vs versi dengan `#ifndef`. Jelaskan mengapa include guard sangat penting saat proyek software mulai memiliki banyak ketergantungan antar-header.

### Latihan 4: Modular Student Grade Converter (40 menit)
Rancang arsitektur 3 file untuk sistem penilaian:
- `grade_converter.h`: Deklarasi fungsi `char konversi_ke_huruf(int skor);` dan `void cetak_predikat(char grade);`.
- `grade_converter.c`: Implementasi konversi (skor $\ge 85 \rightarrow \text{'A'}$, $\ge 75 \rightarrow \text{'B'}$, dsb.).
- `main_grade.c`: Input 3 nilai siswa, hitung rata-rata, lalu panggil fungsi konversi huruf dan cetak predikat.

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kasus Kesalahan | Contoh Perintah Salah | Penjelasan & Solusi |
|---|---|---|
| **Menyertakan File `.h` di Perintah GCC** | `gcc main.c utils.h -o app` | GCC tidak mengompilasi header secara langsung. Tulis hanya file `.c`: `gcc main.c utils.c -o app`. |
| **Menaruh Badan Fungsi di File `.h`** | Menulis logika lengkap `{ ... }` di dalam `utils.h` | Jika header ini di-include oleh 2 file `.c` berbeda, linker akan crash dengan pesan error *multiple definition of 'nama_fungsi'*. Header hanya boleh berisi prototipe! |
| **Lupa Menyertakan File `.c` Kedua** | `gcc main.c -o app` *(padahal butuh `utils.c`)* | Linker gagal menemukan kode implementasi fungsi (*undefined reference to...*). Tambahkan `utils.c` di baris perintah. |
| **Include File `.c` di Dalam File Lain** | `#include "utils.c"` *(di dalam main.c)* | Jangan pernah me-include file `.c`! Yang di-include hanyalah file header `.h`. Me-include file `.c` merusak prinsip kompilasi terpisah. |

---

## ✅ CHECKLIST KEBERHASILAN HARI 4
- [ ] Mampu menjelaskan pembagian peran antara file `.h`, file `.c`, dan `main.c`.
- [ ] Memahami kapan memakai tanda `<...>` dan kapan memakai tanda `"..."` pada `#include`.
- [ ] Berhasil menuliskan struktur Include Guard lengkap dengan `#ifndef`, `#define`, dan `#endif`.
- [ ] Menguasai perintah terminal GCC untuk mengompilasi lebih dari satu file `.c` sekaligus.
- [ ] Mengenali dan bisa memperbaiki pesan error linker *undefined reference*.

---

## 🔮 PREVIEW HARI 5
Selamat! Kamu telah menguasai seluruh konsep inti fungsi dan arsitektur modular di C! Besok pada Hari 5, saatnya membuktikan kemampuanmu dalam **Praktikum Mandiri: Modular Student Utility Toolkit** dan menaklukkan **Quiz HOTS Mingguan**. Siapkan VS Code dan pemahaman analisismu!

---

**"Programmer amatir menulis kode dalam satu file panjang. Software Engineer merancang arsitektur modular yang elegan dan tahan uji zaman." 🏛️**
