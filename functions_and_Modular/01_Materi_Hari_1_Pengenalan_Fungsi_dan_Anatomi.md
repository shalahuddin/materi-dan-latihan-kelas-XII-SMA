# Hari 1: Pengenalan Fungsi & Anatomi Dasar
## Dari Spageti Monolitik Menuju Blok Rapi yang Reusable

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Menjelaskan prinsip **DRY (Don't Repeat Yourself)** dan kerugian kode duplikat (*code smell*).
2. Memahami konsep fungsi sebagai subprogram mandiri dengan input, proses, dan output.
3. Menyusun **anatomi fungsi C** yang valid: tipe kembalian (*return type*), nama fungsi, parameter formal, dan badan fungsi (*body*).
4. Membedakan fungsi ber-return value (`int`, `float`, `char`) dengan prosedur tanpa return value (`void`).
5. Memanggil fungsi berulang kali dari dalam fungsi `main()` dengan parameter yang bervariasi.

---

## 💡 MATERI PEMBELAJARAN

### 1. Masalah Kode Spageti & Prinsip DRY
Bayangkan kamu membuat program kasir kantin SMA LABS. Untuk setiap transaksi 3 barang berbeda, kamu harus menghitung diskon 10%, memotong harga, lalu mencetak struk rapi dengan garis pemisah.

Tanpa fungsi, kodemu akan tampak seperti ini:
```c
// Menghitung barang 1
int harga1 = 50000;
int diskon1 = harga1 * 10 / 100;
int bayar1 = harga1 - diskon1;
printf("================================\n");
printf("Item: Buku Tulis | Bayar: Rp%d\n", bayar1);
printf("================================\n");

// Menghitung barang 2 (rumus dan garis dicopy-paste ulang!)
int harga2 = 25000;
int diskon2 = harga2 * 10 / 100;
int bayar2 = harga2 - diskon2;
printf("================================\n");
printf("Item: Pulpen Gel | Bayar: Rp%d\n", bayar2);
printf("================================\n");
```

Apa yang terjadi jika manajer kantin minta diskon diubah jadi 15% dan garis pemisah diganti dengan tanda bintang `*`? Kamu harus mencari dan mengubah puluhan baris satu per satu! Jika terlewat satu baris saja, programmu akan menghasilkan bug inkonsistensi.

> ⭐ **Prinsip Industri: DRY (Don't Repeat Yourself)**  
> *"Setiap potongan pengetahuan atau logika dalam sistem harus memiliki representasi tunggal, tegas, dan tidak mendua."*  
> Jika kamu mendapati dirimu melakukan copy-paste logika kode lebih dari 2 kali, itu tanda mutlak bahwa logika tersebut harus diubah menjadi **fungsi**.

---

### 2. Apa Itu Fungsi? (Analogi Mesin Pembuat Jus)
Secara sederhana, fungsi adalah sebuah sub-program atau blok instruksi mandiri yang diberi nama, dirancang untuk menyelesaikan satu tugas spesifik.

```
       [ INPUT ]                     [ PROSES ]                    [ OUTPUT ]
(Apel + Gula + Air)  ───►  [ Mesin Blender: buat_jus() ]  ───►  (Segelas Jus Manis)
```
- **Input (Parameter)**: Bahan mentah yang dibutuhkan fungsi untuk bekerja.
- **Proses (Badan Fungsi)**: Algoritma atau logika komputasi di dalam kurung kurawal.
- **Output (Nilai Kembalian / Return Value)**: Hasil akhir pekerjaan yang diserahkan kembali kepada pemanggil (*caller*).

---

### 3. ⭐ Anatomi Fungsi dalam Bahasa C
Setiap fungsi di C wajib mematuhi format sintaks baku berikut:

```c
return_type nama_fungsi(tipe_param1 nama_param1, tipe_param2 nama_param2) {
    // Badan fungsi (instruksi / logika)
    return nilai_kembalian; // wajib jika return_type bukan void
}
```

Mari kita bedah anatomi fungsi penghitung diskon berikut:
```c
int hitung_diskon(int harga, int persen) {
//│        │            │             │
//│        │            └─────────────┴── Parameter Formal (input yang diterima)
//│        └───────────────────────────── Nama Fungsi (deskriptif, kata kerja)
//└────────────────────────────────────── Return Type (tipe data hasil keluaran)

    int total_potongan = harga * persen / 100;
    return total_potongan; // Mengembalikan hasil ke pemanggil
}
```

Tabel Komponen Anatomi Fungsi:
| Komponen | Penjelasan | Contoh Valid | Contoh Bermasalah |
|---|---|---|---|
| **Return Type** | Tipe data nilai yang dikembalikan fungsi kepada pemanggil. Gunakan `void` jika tidak menghasilkan nilai. | `int`, `float`, `char`, `void` | Dikosongkan (pada standar C modern akan dianggap error/warning) |
| **Nama Fungsi** | Identifier unik untuk memanggil fungsi. Gunakan huruf kecil bergaris bawah (`snake_case`). | `hitung_pajak`, `cetak_menu` | `123hitung`, `hitung pajak` (spasi dilarang) |
| **Parameter** | Variabel penampung nilai input dari pemanggil. Jika tidak butuh input, tulis `void` atau kosongkan. | `(int x, int y)`, `(void)` | `(int x, y)` (tipe tiap variabel wajib ditulis ulang!) |
| **Badan Fungsi** | Blok instruksi diapit tanda kurung kurawal `{ ... }`. | `{ return a + b; }` | Lupa kurung kurawal penutup |
| **Pernyataan Return**| Perintah mengirim nilai kembali sekaligus seketika menghentikan eksekusi fungsi tersebut. | `return hasil;` | `return;` pada fungsi ber-return type `int` |

---

### 4. Fungsi Ber-Return Value vs Fungsi Prosedur (`void`)

Dalam bahasa C, fungsi dikelompokkan menjadi dua kategori besar berdasarkan kembalian nilainya:

#### A. Fungsi Ber-Return Value (Menghasilkan Nilai)
Fungsi ini melakukan komputasi dan **mengembalikan hasil**. Hasil ini bisa langsung disimpan dalam variabel, dicetak, atau digunakan dalam ekspresi matematika lainnya.
```c
int kuadrat(int n) {
    return n * n;
}

int main() {
    int hasil = kuadrat(5);             // Disimpan dalam variabel: hasil = 25
    printf("Hasil: %d\n", kuadrat(4));  // Langsung dicetak: 16
    int gabungan = kuadrat(3) + 10;     // Dipakai dalam ekspresi: 9 + 10 = 19
    return 0;
}
```

#### B. Fungsi Tanpa Return Value (`void`)
Fungsi yang return type-nya `void` tidak mengembalikan data apa pun ke pemanggil. Tujuannya murni menjalankan aksi/prosedur, misalnya mencetak banner, membersihkan layar, atau menampilkan instruksi game.
```c
void tampilkan_sambutan(void) {
    printf("=========================================\n");
    printf("     SELAMAT DATANG DI SISTEM LABS       \n");
    printf("=========================================\n");
    // Tidak butuh pernyataan return ber-nilai!
}

int main() {
    tampilkan_sambutan(); // Dipanggil berdiri sendiri sebagai pernyataan
    return 0;
}
```

> ⚠️ **Catatan Penting**: Fungsi `main()` adalah fungsi khusus yang dipanggil oleh Operating System saat program mulai. Oleh standar C99/C11, `main()` bertipe `int` dan mengembalikan `0` (`return 0;`) sebagai sinyal kepada OS bahwa program selesai berjalan sukses tanpa crash.

---

## 💻 LIVE CODING DEMO

Berikut adalah contoh program lengkap terstruktur yang menggabungkan fungsi `void` dan fungsi penghitung nilai.

```c
/*
 * File: 01_void_greeting_and_dry.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi fungsi void dan fungsi kalkulasi nilai berprinsip DRY
 *
 * Compile:
 *   gcc 01_void_greeting_and_dry.c -o greeting_demo
 *   .\greeting_demo.exe
 */

#include <stdio.h>

// 1. Fungsi void: mencetak garis pembatas dekoratif
void cetak_garis(void) {
    printf("----------------------------------------\n");
}

// 2. Fungsi void: mencetak header aplikasi kartu siswa
void cetak_header(void) {
    cetak_garis();
    printf("     PORTAL AKADEMIK SMA LABS 2026      \n");
    cetak_garis();
}

// 3. Fungsi ber-return value int: menghitung nilai akhir terbobot
// Rumus: (Teori * 40%) + (Praktikum * 60%)
int hitung_nilai_akhir(int nilai_teori, int nilai_praktikum) {
    int skor_akhir = (nilai_teori * 40 / 100) + (nilai_praktikum * 60 / 100);
    return skor_akhir;
}

int main() {
    // Memanggil fungsi header
    cetak_header();

    // Data Siswa 1
    int teori1 = 80;
    int prak1 = 90;
    int akhir1 = hitung_nilai_akhir(teori1, prak1);
    printf("Siswa 1 -> Teori: %d | Prak: %d | Akhir: %d\n", teori1, prak1, akhir1);

    // Data Siswa 2 (Logika perhitungan tidak perlu ditulis ulang!)
    int teori2 = 70;
    int prak2 = 65;
    int akhir2 = hitung_nilai_akhir(teori2, prak2);
    printf("Siswa 2 -> Teori: %d | Prak: %d | Akhir: %d\n", teori2, prak2, akhir2);

    cetak_garis();
    printf("Status: Kedua data berhasil diproses via fungsi.\n");
    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

Kerjakan latihan berikut langsung di VS Code lokal komputermu:

### Latihan 1: Generator Garis Kustom (25 menit)
Buatlah fungsi `void cetak_pemisah(char karakter, int panjang)` yang mencetak karakter tertentu sebanyak `panjang` kali ke layar (gunakan percabangan atau manual 10 karakter dulu). Uji fungsi tersebut dengan mencetak pembatas bintang `*` dan tanda sama dengan `=`.

### Latihan 2: Konversi Satuan Suhu Laboratorium (30 menit)
Laboratorium Fisika SMA LABS membutuhkan fungsi C untuk mengubah suhu dari Reamur ke Celcius.
- Nama fungsi: `float reamur_ke_celcius(float suhu_reamur)`
- Rumus: $\text{Celcius} = \text{Reamur} \times \frac{5}{4}$ (Gunakan `5.0 / 4.0` agar tidak terkena integer division!)
- Buat fungsi `main()` untuk memanggil fungsi tersebut dengan input Reamur: `32.0` dan `60.0`. Tampilkan hasilnya hingga 2 angka desimal (`%.2f`).

### Latihan 3: Kalkulator Diskon Hari Ulang Tahun (35 menit)
Sebuah toko buku memberikan diskon spesial bagi siswa yang berulang tahun:
- Nama fungsi: `int hitung_harga_bersih(int harga_katalog, int diskon_persen, int voucher_potongan)`
- Logika: Kurangi harga katalog dengan persentase diskon, lalu kurangi lagi dengan nominal voucher potongan. Jika hasil akhirnya negatif, kembalikan nilai `0` (tidak boleh toko membayar pembeli).
- Uji dengan 2 skenario: belanja normal dan belanja diskon besar melebihi harga barang.

### Latihan 4: Bedah Bug Sintaks (40 menit)
Seorang siswa menulis kode fungsi berikut dan mengalami serangkaian pesan error dari GCC. Salin kode ini, identifikasi minimal 3 kesalahan sintaks/logika, lalu tuliskan versi yang telah diperbaiki:
```c
// KODE RUSAK - TEMUKAN KESALAHANNYA!
void hitung_keliling(int panjang, lebar) {
    int keliling = 2 * (panjang + lebar);
    return keliling;
}
```

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kasus Kesalahan | Contoh Kode Salah | Mengapa Salah & Cara Memperbaiki |
|---|---|---|
| **Tipe Parameter Tidak Diulang** | `void jumlah(int a, b)` | Di C, setiap parameter wajib memiliki tipe data sendiri: `void jumlah(int a, int b)`. |
| **Return Nilai pada Fungsi `void`** | `void halo() { return 42; }` | Fungsi `void` tidak boleh mengembalikan nilai. Kompilator akan melempar pesan *error: return with a value, in function returning void*. |
| **Lupa Nilai Balik pada Fungsi Non-Void** | `int tambah(int a, int b) { int c = a + b; }` | Fungsi bertipe `int` wajib memiliki pernyataan `return c;`. Tanpa return, fungsi akan mengembalikan nilai sampah acak (*garbage value*). |
| **Kode Berada di Bawah `return`** | `int luas(int s) { return s*s; printf("Selesai"); }` | Baris setelah `return` tidak akan pernah dieksekusi (*unreachable code*) karena kendali program langsung kembali ke pemanggil. |
| **Menampung Kembalian Fungsi `void`** | `int x = cetak_garis();` | Fungsi `void` tidak memiliki nilai; mencoba menampungnya ke dalam variabel menghasilkan error *void value not ignored as it ought to be*. |

---

## ✅ CHECKLIST KEBERHASILAN HARI 1
Pastikan kamu telah menguasai poin-poin berikut sebelum melanjutkan ke Hari 2:
- [ ] Mampu menjelaskan prinsip DRY dengan kata-katamu sendiri.
- [ ] Hafal struktur 4 elemen utama anatomi fungsi C (return type, nama, parameter, body).
- [ ] Tahu persis kapan harus menggunakan `void` dan kapan harus menggunakan tipe data angka (`int`/`float`).
- [ ] Mengetahui bahwa statement `return` langsung mengakhiri eksekusi fungsi saat itu juga.
- [ ] Berhasil mengompilasi program dengan minimal 2 fungsi buatan sendiri di VS Code lokal tanpa warning.

---

## 🔮 PREVIEW HARI 2
Besok kita akan membongkar rahasia internal memori: Apakah variabel di dalam `main()` bisa diubah nilainya oleh fungsi lain? Kita akan mempelajari konsep krusial **Call by Value** dan mengapa C selalu membuat salinan data cadangan, serta bagaimana **Prototipe Fungsi** bertindak sebagai "Daftar Isi" yang menyelamatkan programmu dari kebingungan kompilator!

---

**"Fungsi adalah blok bangunan peradaban software. Satu fungsi rapi, seribu kemudahan di masa depan." 🛠️**
