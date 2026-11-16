# 📋 MODUL PRAKTIKUM TERSTRUKTUR MINGGU 05 (LEVEL C3–C4: MENERAPKAN & MENGANALISIS)

## Studi Kasus Lanjutan: Mengubah Program _"LABS Smart Canteen"_ Menjadi Fungsi & Multi-File di OnlineGDB

**Mata Pelajaran:** Pemrograman C (Informatika Kelas XII LABS)  
**Topik Minggu 05:** Fungsi (*Functions*), *Call by Value*, *Scope Variabel*, & Pemrograman Modular (*Multi-File*)  
**Tingkat Kognitif:** C3 (Menerapkan) & C4 (Menganalisis)  
**Alat Eksekusi:** [OnlineGDB — GDB Online Debugger | Compiler (C)](https://www.onlinegdb.com/)  
**Durasi Pengerjaan:** 1 Sesi Pembelajaran (Praktikum Mandiri)

---

## 📌 GAMBARAN UMUM TUGAS

Pada tugas sebelumnya, kalian sudah berhasil membuat program **Kios Layanan Mandiri (*Self-Service Kiosk*) "LABS Smart Canteen"** di **OnlineGDB**. Namun, saat itu seluruh kode kalian masih menumpuk panjang di dalam satu fungsi `main()` saja.

Sekarang, tugas kalian adalah **memecah (*refactoring*) kode yang sudah kalian buat itu** ke dalam **Fungsi (*Functions*)** dan **File Terpisah (*Modular Multi-File*)** langsung di web **OnlineGDB** (tanpa perlu memakai terminal lokal atau menginstal aplikasi tambahan):

1. **Soal 1 (Membuat Fungsi Menu & Varian — Materi Hari 1 & 2):** Memindahkan bagian tampilan menu dan pilihan paket makanan keluar dari `main()` menjadi fungsi-fungsi kecil (`void` dan `int`), lengkap dengan **Prototipe Fungsi** di bagian atas.
2. **Soal 2 (Membuat Fungsi Kasir, Diskon & Validasi Saldo — Materi Hari 2 & 3):** Memindahkan rumus biaya kemasan, diskon pelajar, dan cek saldo kartu ke dalam fungsi tersendiri yang menggunakan **Variabel Lokal** dan **Call by Value** (tanpa variabel global).
3. **Soal 3 (Memecah Program Jadi 3 Tab File di OnlineGDB — Materi Hari 4 & 5):** Memisahkan program Kios Cerdas LABS ke dalam **3 tab file berbeda** di OnlineGDB (`main.c`, `canteen.h`, dan `canteen.c`) lalu menjalankannya dengan tombol **Run**.

---

## 📜 ATURAN MAIN PENGERJAAN

1. **Full di Browser (OnlineGDB):** Buka [https://www.onlinegdb.com/](https://www.onlinegdb.com/) dan pastikan pilihan **Language** di pojok kanan atas adalah **C**.
2. **Dilarang Memakai Variabel Global:** Semua variabel (seperti `subtotal`, `diskon`, `kemasan`, `saldo_kartu`) wajib dibuat di dalam fungsi (`main` atau fungsi lainnya). Pengiriman nilai antar-fungsi wajib lewat **parameter** `( ... )` dan hasil perhitungannya dikirim balik menggunakan **`return`**.
3. **Gaya Penulisan Rapi:**
   - Gunakan indentasi **4 spasi** agar kode mudah dibaca.
   - Beri nama fungsi dan variabel dengan gaya **`snake_case`** yang jelas (contoh: `hitung_diskon_siswa`, bukan `hds` atau `fungsi1`).
4. **Bebas Error:** Saat tombol **Run (▶)** berwarna hijau di OnlineGDB ditekan, program harus berjalan lancar tanpa pesan *error* maupun *warning*.

---

# 📝 RINCIAN TUGAS BERSAMBUNG DI ONLINEGDB

---

## 🔹 SOAL 1: Memecah Menu & Varian Makanan ke Dalam Fungsi (Tahap 1)

### 🎯 Tujuan
Memahami cara kerja prinsip **DRY (*Don't Repeat Yourself*)**, membedakan fungsi `void` (hanya menampilkan teks) dan fungsi `int` (menghasilkan angka perhitungan), serta memasang **Prototipe Fungsi** di atas `main()`.

### 📖 Cara Mengerjakan
Buka kode **Soal 1** kalian yang lama di OnlineGDB. Jangan tulis lagi `switch-case` dan `if-else` panjang lebar di dalam `main()`. Pindahkan logika tersebut ke dalam fungsi-fungsi di bawah ini, sehingga isi `main()` menjadi pendek dan rapi.

### ⚙️ Daftar Fungsi yang Wajib Kalian Buat

1. **Fungsi Tampilan Layar (`void` — Tidak mengembalikan angka):**
   - `void cetak_garis(void)`  
     Tugasnya hanya mencetak satu baris garis pembatas:  
     `printf("==================================================\n");`
   - `void tampilkan_menu_utama(void)`  
     Tugasnya menampilkan judul kios dan daftar 3 menu utama beserta harga dasarnya. Panggil juga `cetak_garis()` di dalamnya agar kita tidak perlu mengetik `printf` garis berkali-kali!

2. **Fungsi Hitung Harga Paket (`int` — Mengembalikan harga `subtotal`):**
   - `int pilih_paket_nusantara(int pilihan_lauk)`  
     Harga dasar Rp 20.000. Gunakan `if-else`:
     - Jika `pilihan_lauk == 1` (Ayam Geprek): kembalikan `20000 + 5000` (Rp 25.000).
     - Jika `pilihan_lauk == 2` (Rendang Sapi): kembalikan `20000 + 10000` (Rp 30.000).
     - Selain 1 atau 2: tampilkan pesan peringatan dan otomatis kembalikan harga Ayam Geprek (`25000`).
   - `int pilih_paket_western(int pilihan_ukuran)`  
     Harga dasar Rp 28.000. Gunakan `if-else`:
     - Jika `pilihan_ukuran == 1` (Reguler): kembalikan `28000`.
     - Jika `pilihan_ukuran == 2` (Jumbo / *Double Cheese*): kembalikan `28000 + 7000` (Rp 35.000).
   - `int pilih_paket_snack(int jumlah_porsi)`  
     Harga dasar Rp 12.000 per porsi (`jumlah_porsi * 12000`). Gunakan `if-else`:
     - Jika `jumlah_porsi >= 3`, kurangi totalnya sebesar Rp 3.000, lalu `return` hasilnya.

3. **Fungsi Pengatur Kategori Menu (`int`):**
   - `int proses_menu_utama(int kategori)`  
     Di dalam fungsi inilah kalian menaruh `switch-case` (1–3). Sesuai kategori yang dipilih, minta input sub-varian dari pengguna (`scanf`), lalu panggil fungsi paket yang sesuai (`pilih_paket_nusantara`, `pilih_paket_western`, atau `pilih_paket_snack`) dan `return` nilai subtotalnya. Jika pengguna memilih angka selain 1–3, tampilkan `"Pilihan menu tidak valid!"` pada `default:` dan `return -1;`.

### 💻 Kerangka Kode Soal 1 (Salin ke OnlineGDB & Lengkapi Bagian Bawahnya)

```c
#include <stdio.h>

// =========================================================
// 1. PROTOTIPE FUNGSI (Daftar isi fungsi di atas main)
//    Wajib diakhiri tanda titik koma (;)
// =========================================================
void cetak_garis(void);
void tampilkan_menu_utama(void);
int pilih_paket_nusantara(int pilihan_lauk);
int pilih_paket_western(int pilihan_ukuran);
int pilih_paket_snack(int jumlah_porsi);
int proses_menu_utama(int kategori);

// =========================================================
// 2. FUNGSI MAIN (Sekarang jadi sangat singkat dan rapi!)
// =========================================================
int main(void) {
    int menu_pilihan;

    tampilkan_menu_utama();
    printf("Pilih Menu Utama (1-3): ");
    scanf("%d", &menu_pilihan);

    // Panggil fungsi proses_menu_utama dan simpan hasilnya di variabel subtotal
    int subtotal = proses_menu_utama(menu_pilihan);

    // Jika fungsi mengembalikan -1, artinya input menu salah -> hentikan program
    if (subtotal == -1) {
        return 1;
    }

    printf("Subtotal Pesanan: Rp %d\n", subtotal);
    cetak_garis();

    return 0;
}

// =========================================================
// 3. ISI / DEFINISI FUNGSI (Tulis logika programmu di sini)
// =========================================================

void cetak_garis(void) {
    printf("==================================================\n");
}

// Lanjutkan menulis fungsi tampilkan_menu_utama(), pilih_paket_nusantara(), dst. di bawah ini:
```

---

## 🔹 SOAL 2: Membuat Fungsi Kasir, Diskon & Cek Saldo (Tahap 2)

### 🎯 Tujuan
Menggunakan fungsi dengan **Operator Ternary (`? :`)**, memahami bahwa fungsi di C hanya menerima **salinan nilai (*Call by Value*)**, dan memperbarui sisa saldo siswa di `main()` melalui **`return` value**.

### 📖 Cara Mengerjakan
Setelah Soal 1 berhasil dijalankan, tambahkan fungsi-fungsi kasir dari **Soal 2** dan **Soal 3** di bawah ini ke dalam kode OnlineGDB kalian.

### ⚙️ Daftar Fungsi Kasir yang Wajib Ditambahkan

1. **Fungsi Biaya Kemasan (Wajib pakai Operator Ternary `? :`):**
   - `int hitung_biaya_kemasan(int tipe_saji)`  
     Jika `tipe_saji == 2` (*Takeaway* / Bungkus), kembalikan `2000`. Jika `1` (*Dine-In*), kembalikan `0`.  
     *Contoh isi fungsi:* `return (tipe_saji == 2) ? 2000 : 0;`

2. **Fungsi Diskon Kartu Pelajar LABS (Wajib pakai Operator Ternary `? :`):**
   - `int hitung_diskon_siswa(int subtotal, int punya_kartu)`  
     Jika `punya_kartu == 1` (Punya), kembalikan diskon 10% (`subtotal * 10 / 100`). Jika `0`, kembalikan `0`.

3. **Fungsi Hitung Total Akhir:**
   - `int hitung_total_akhir(int subtotal, int diskon, int kemasan)`  
     Mengembalikan hasil `subtotal - diskon + kemasan`.

4. **Fungsi Pembayaran Kartu Siswa & Proteksi Limit Harian (`if-else`):**
   - `int bayar_pakai_kartu(int saldo_sekarang, int total_bayar, int limit_harian)`  
     Periksa syarat keamanan kantin secara berurutan:
     - **Cek Limit Harian:** Jika `total_bayar > limit_harian` (Rp 50.000), cetak `"[DITOLAK] Transaksi melebihi limit jajan harian siswa (Maks Rp 50.000)!\n"` lalu `return -1;` (kode gagal).
     - **Cek Kecukupan Saldo:** Jika `saldo_sekarang < total_bayar`, cetak `"[GAGAL] Saldo kartu tidak mencukupi! Sisa saldo Anda: Rp %d\n"` lalu `return -1;`.
     - **Jika Aman:** Cetak `"[BERHASIL] Pembayaran sukses via Kartu Siswa LABS\n"` dan **kembalikan sisa saldo yang baru** (`return saldo_sekarang - total_bayar;`).

5. **Fungsi Cetak Struk Resmi (`void`):**
   - `void cetak_struk(int subtotal, int diskon, int kemasan, int total_akhir, int sisa_saldo)`  
     Menampilkan rincian pembayaran lengkap hingga sisa saldo/kembalian seperti contoh output di bawah.

> 💡 **Pertanyaan Pemahaman *Call by Value* (Jawab Singkat di Komentar Kode `// ...`):**  
> Di dalam `main()`, saat kita memanggil `bayar_pakai_kartu(saldo_siswa, total_akhir, 50000)`, mengapa kita **harus** menampung hasilnya ke variabel (misalnya `int sisa_saldo = bayar_pakai_kartu(...);`)? Mengapa variabel `saldo_siswa` di `main()` tidak bisa berkurang sendiri secara otomatis jika di dalam fungsi hanya ditulis `saldo_sekarang = saldo_sekarang - total_bayar;` tanpa `return`?  
> *(Petunjuk Materi Hari 2: Ingat konsep fotokopi data / Call by Value!)*

---

## 🔹 SOAL 3: Memecah Program Menjadi 3 File (`.h` dan `.c`) di OnlineGDB (Tahap 3 - Final)

### 🎯 Tujuan
Mempraktikkan langsung **Pemrograman Modular (*Multi-File*)** seperti programmer profesional dengan memisahkan **File Header (`canteen.h`)**, **File Implementasi (`canteen.c`)**, dan **File Utama (`main.c`)** di dalam satu proyek **OnlineGDB**.

### 🛠️ Cara Membuat Banyak File (Multi-File) di Web OnlineGDB

Kalian **tidak perlu** menggunakan terminal lokal atau mengetik perintah `gcc` manual. Di **OnlineGDB**, tombol **Run** sudah otomatis menggabungkan semua file `.c` kalian! Ikuti 3 langkah mudah ini:

1. Lihat bagian atas area ketik kode di OnlineGDB (di sebelah kanan tab `main.c`), klik ikon **New File** (gambar kertas dengan tanda **`+`**) atau tekan tombol pintas **`Ctrl + M`**.
2. Ketik nama file pertama: **`canteen.h`** lalu klik **OK**.
3. Klik lagi ikon **New File (`+`)**, ketik nama file kedua: **`canteen.c`** lalu klik **OK**.
4. Sekarang di bagian atas editor OnlineGDB kalian akan terlihat **3 tab berjajar**:
   ```text
   [ main.c ]   [ canteen.h ]   [ canteen.c ]
   ```

---

### 🗂️ Pembagian Isi Ketiga Tab File di OnlineGDB

Pindahkan potongan kode yang sudah kalian buat di Soal 1 & Soal 2 ke masing-masing tab berikut:

#### 📄 Tab 1: `canteen.h` (Buku Menu / Kontrak Fungsi)
Tab ini **HANYA** berisi konstanta `#define` dan daftar **Prototipe Fungsi** yang dibungkus dengan **Include Guard (`#ifndef`)**.  
*(Ingat Materi Hari 4: Jangan pernah menulis isi/rumus fungsi `{ ... }` di dalam file `.h`!)*

```c
/*
 * File: canteen.h
 * Nama Siswa: [Tulis Nama Lengkapmu] (Kelas XII LABS)
 * Deskripsi: File Header (Kontrak Fungsi & Konstanta Kios LABS)
 */

#ifndef CANTEEN_H
#define CANTEEN_H

// Konstanta Harga dan Aturan Kios LABS
#define HARGA_NUSANTARA   20000
#define HARGA_WESTERN     28000
#define HARGA_SNACK       12000
#define BIAYA_BUNGKUS     2000
#define SALDO_AWAL_SISWA  45000
#define LIMIT_HARIAN_MAKS 50000

// Daftar Prototipe Fungsi (Semua diakhiri titik koma)
void cetak_garis(void);
void tampilkan_menu_utama(void);

int pilih_paket_nusantara(int pilihan_lauk);
int pilih_paket_western(int pilihan_ukuran);
int pilih_paket_snack(int jumlah_porsi);
int proses_menu_utama(int kategori);

int hitung_biaya_kemasan(int tipe_saji);
int hitung_diskon_siswa(int subtotal, int punya_kartu);
int hitung_total_akhir(int subtotal, int diskon, int kemasan);

int bayar_pakai_kartu(int saldo_sekarang, int total_bayar, int limit_harian);
int bayar_pakai_tunai(int uang_tunai, int total_bayar);
void cetak_struk(int subtotal, int diskon, int kemasan, int total_akhir, int metode, int sisa_uang);

#endif // CANTEEN_H
```

---

#### 📄 Tab 2: `canteen.c` (Dapur Rumus & Logika Fungsi)
Tab ini berisi **implementasi lengkap (badan fungsi `{ ... }`)** dari semua fungsi yang ada di `canteen.h`.  
Wajib menuliskan `#include "canteen.h"` (pakai tanda kutip dua `"..."`) di baris atas!

```c
/*
 * File: canteen.c
 * Nama Siswa: [Tulis Nama Lengkapmu] (Kelas XII LABS)
 * Deskripsi: File Implementasi seluruh fungsi Kios LABS Smart Canteen
 */

#include <stdio.h>
#include "canteen.h" // Wajib menyertakan file header buatan kita sendiri

void cetak_garis(void) {
    printf("==================================================\n");
}

void tampilkan_menu_utama(void) {
    cetak_garis();
    printf("        KIOS LABS SMART CANTEEN - PILIH MENU\n");
    cetak_garis();
    printf("1. Paket Nasi Nusantara      (Dasar: Rp %d)\n", HARGA_NUSANTARA);
    printf("2. Paket Western / Pasta     (Dasar: Rp %d)\n", HARGA_WESTERN);
    printf("3. Paket Snack & Minuman     (Dasar: Rp %d)\n", HARGA_SNACK);
    printf("--------------------------------------------------\n");
}

// Lanjutkan isi semua fungsi lainnya di bawah ini:
// - pilih_paket_nusantara(...)
// - pilih_paket_western(...)
// - pilih_paket_snack(...)
// - proses_menu_utama(...)
// - hitung_biaya_kemasan(...)
// - hitung_diskon_siswa(...)
// - hitung_total_akhir(...)
// - bayar_pakai_kartu(...)
// - bayar_pakai_tunai(...)
// - cetak_struk(...)
```

---

#### 📄 Tab 3: `main.c` (Program Utama Pemanggil Fungsi)
Tab `main.c` sekarang menjadi sangat pendek dan bersih karena hanya berisi fungsi `main()` yang memanggil fungsi-fungsi dari `canteen.h`.  
*(Ingat Materi Hari 4: Yang di-include adalah `#include "canteen.h"`, **JANGAN PERNAH** menulis `#include "canteen.c"`!)*

```c
/*
 * File: main.c
 * Nama Siswa: [Tulis Nama Lengkapmu] (Kelas XII LABS)
 * Deskripsi: Program utama Kios Mandiri LABS Smart Canteen
 *
 * JAWABAN ANALISIS CALL BY VALUE:
 * [Tulis jawaban singkatmu di sini mengapa saldo harus di-update pakai return value]
 */

#include <stdio.h>
#include "canteen.h" // Cukup panggil buku menunya (header)

int main(void) {
    // Variabel lokal di dalam main (Tidak boleh ada variabel global!)
    int saldo_kartu = SALDO_AWAL_SISWA;
    int limit_harian = LIMIT_HARIAN_MAKS;
    int kategori, tipe_saji, punya_kartu, metode_bayar;

    // 1. Tahap Pemilihan Menu
    tampilkan_menu_utama();
    printf("Pilih Menu Utama (1-3): ");
    scanf("%d", &kategori);

    int subtotal = proses_menu_utama(kategori);
    if (subtotal == -1) {
        return 1; // Berhenti jika menu tidak valid
    }

    // 2. Tahap Kemasan & Diskon
    printf("\nTipe Penyajian (1 = Dine-In, 2 = Takeaway): ");
    scanf("%d", &tipe_saji);
    int kemasan = hitung_biaya_kemasan(tipe_saji);

    printf("Status Kepemilikan Kartu Siswa LABS? (1 = Ya, 0 = Tidak): ");
    scanf("%d", &punya_kartu);
    int diskon = hitung_diskon_siswa(subtotal, punya_kartu);

    int total_akhir = hitung_total_akhir(subtotal, diskon, kemasan);

    // 3. Tahap Pembayaran & Cetak Struk
    printf("\nPilih Metode Pembayaran (1 = Tunai, 2 = Kartu Saldo LABS): ");
    scanf("%d", &metode_bayar);

    if (metode_bayar == 2) {
        int sisa_saldo = bayar_pakai_kartu(saldo_kartu, total_akhir, limit_harian);
        if (sisa_saldo != -1) {
            saldo_kartu = sisa_saldo; // Update saldo lokal dari return value
            cetak_struk(subtotal, diskon, kemasan, total_akhir, metode_bayar, saldo_kartu);
        }
    } else if (metode_bayar == 1) {
        int uang_tunai;
        printf("Masukkan Nominal Uang Tunai: Rp ");
        scanf("%d", &uang_tunai);
        int kembalian = bayar_pakai_tunai(uang_tunai, total_akhir);
        if (kembalian != -1) {
            cetak_struk(subtotal, diskon, kemasan, total_akhir, metode_bayar, kembalian);
        }
    } else {
        printf("[ERROR] Metode pembayaran tidak dikenali!\n");
    }

    return 0;
}
```

---

## 🖥️ CONTOH OUTPUT SAAT DITEKAN TOMBOL "RUN" DI ONLINEGDB

```text
==================================================
        KIOS LABS SMART CANTEEN - PILIH MENU
==================================================
1. Paket Nasi Nusantara      (Dasar: Rp 20000)
2. Paket Western / Pasta     (Dasar: Rp 28000)
3. Paket Snack & Minuman     (Dasar: Rp 12000)
--------------------------------------------------
Pilih Menu Utama (1-3): 1

-- Sub-Menu Pilihan Lauk --
1. Ayam Geprek (+Rp 5.000)
2. Rendang Sapi (+Rp 10.000)
Pilih Lauk (1/2): 2

Tipe Penyajian (1 = Dine-In, 2 = Takeaway): 2
Status Kepemilikan Kartu Siswa LABS? (1 = Ya, 0 = Tidak): 1

Pilih Metode Pembayaran (1 = Tunai, 2 = Kartu Saldo LABS): 2
[BERHASIL] Pembayaran sukses via Kartu Siswa LABS

==================================================
          STRUK RESMI LABS SMART CANTEEN          
==================================================
Subtotal Makanan   : Rp 30000
Diskon Siswa (10%) : Rp 3000
Biaya Kemasan      : Rp 2000
--------------------------------------------------
TOTAL AKHIR BAYAR  : Rp 29000
Metode Pembayaran  : Kartu Saldo LABS
Sisa Saldo Kartu   : Rp 16000
==================================================
```

---

## 📤 CARA MENYIMPAN & MENGUMPULKAN TUGAS DARI ONLINEGDB

Setelah program 3 tab kalian berhasil jalan (*Run*) tanpa error di OnlineGDB, kumpulkan dengan salah satu atau kedua cara berikut sesuai instruksi guru:

1. **Cara 1 — Bagikan Link Proyek OnlineGDB (Tombol *Share*):**
   - Klik tombol **Share** berwarna oranye di bagian atas halaman OnlineGDB.
   - Salin tautan pada bagian **Share Code** (contoh: `https://onlinegdb.com/xxxxxx`) dan kirimkan tautannya di tempat pengumpulan tugas. *(Satu link tersebut otomatis menyimpan ketiga tab file kalian sekaligus!)*
2. **Cara 2 — Unduh Kode (Tombol *Download Code*):**
   - Klik tombol **Download Code** (ikon panah bawah di sebelah tombol Run/Share) untuk mengunduh ketiga file (`main.c`, `canteen.h`, `canteen.c`) ke komputer kalian.

---


## ✅ CHECKLIST SEBELUM KLIK "SHARE / SUBMIT"
- [ ] Di bagian atas OnlineGDB sudah ada **3 tab file**: `main.c`, `canteen.h`, dan `canteen.c`.
- [ ] Tidak ada satu pun variabel yang dideklarasikan di luar fungsi (tidak ada variabel global).
- [ ] Di dalam `canteen.h` sudah dipasang pelindung `#ifndef CANTEEN_H`, `#define CANTEEN_H`, dan `#endif`.
- [ ] Di dalam `main.c` sudah tertulis jawaban singkat tentang *Call by Value* pada bagian komentar atas.
- [ ] Sudah diuji klik tombol **Run (▶)** di OnlineGDB untuk skenario saldo cukup dan skenario transaksi melebihi limit Rp 50.000.