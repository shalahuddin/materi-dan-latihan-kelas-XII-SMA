# 📋 MODUL TUGAS PROYEK BERKELANJUTAN (LEVEL C3 - MENERAPKAN)

## Studi Kasus: Rancang Bangun Sistem Kios Mandiri _"LABS Smart Canteen"_

**Mata Pelajaran:** Pemrograman C (Informatika Kelas XII LABS)  
**Tingkat Kognitif:** C3 (Menerapkan / _Applying_)  
**Alat Eksekusi:** [OnlineGDB (C GCC)](https://www.onlinegdb.com/) atau Compiler GCC Lokal  
**Durasi Pengerjaan:** 1 Sesi Pembelajaran (Praktikum & Mandiri)

---

## 📌 GAMBARAN UMUM TUGAS

Dalam tugas proyek ini, kalian akan membangun sistem software untuk mesin **Kios Layanan Mandiri (_Self-Service Kiosk_) "LABS Smart Canteen"**.

Tugas ini terdiri dari **3 Soal yang saling bersambung secara berurutan (Modul 1 ➔ Modul 2 ➔ Modul 3)**:

- **Soal 1 (Modul Pemilihan Menu & Varian):** Menerapkan navigasi menu utama menggunakan `switch-case` dan sub-varian menggunakan `nested if-else`.
- **Soal 2 (Modul Kasir, Diskon & Metode Pembayaran):** Menerapkan aturan diskon kartu pelajar, biaya kemasan, dan kalkulasi pembayaran menggunakan `operator ternary` dan `if-else`.
- **Soal 3 (Modul Integrasi Penuh & Proteksi Saldo Akun):** Menggabungkan seluruh alur program (Modul 1 + Modul 2) menjadi satu sistem kasir cerdas yang dilengkapi validasi saldo kartu dompet siswa, limit harian, dan ringkasan struk transaksi.

---

## 📜 PETUNJUK UMUM PENGERJAAN

1. Kerjakan secara berurutan mulai dari **Soal 1**, lanjutkan ke **Soal 2**, lalu gabungkan pada **Soal 3**.
2. Gunakan indentasi rapi (4 spasi) dan penamaan variabel yang deskriptif (_snake_case_ atau _camelCase_).
3. Pastikan setiap blok keputusan memiliki penanganan kesalahan (_error handling_ / input invalid).
4. Program harus dapat dikompilasi tanpa _error_ maupun _warning_ di **OnlineGDB** (Pilih bahasa: **C (GCC)**).

---

# 📝 RINCIAN TUGAS BERSAMBUNG

---

## 🔹 SOAL 1: Modul Pemilihan Menu & Varian Paket Makanan (Tahap 1)

### 🎯 Tujuan

Menerapkan pemilihan menu kategori dengan `switch-case` dan pemilihan sub-opsi paket makanan dengan `nested if-else`.

### 📖 Deskripsi Kasus

Mesin kios menampilkan 3 kategori paket makanan. Setelah pengguna memilih salah satu kategori, program akan meminta pengguna menentukan sub-varian lauk / ukuran porsi, lalu menghitung subtotal harga dasar.

### ⚙️ Spesifikasi & Aturan Logika

1. **Menu Kategori Utama (Wajib `switch-case`):**
   - **`1` = Paket Nasi Nusantara** (Harga Dasar: Rp 20.000)
   - **`2` = Paket Western / Pasta** (Harga Dasar: Rp 28.000)
   - **`3` = Paket Snack & Minuman Sehat** (Harga Dasar: Rp 12.000)
   - Pilihan selain 1–3: Tampilkan pesan error melalui `default:` `"Pilihan menu tidak valid!"` dan program berakhir (_return 1_).
2. **Sub-Pilihan Varian (Wajib `nested if-else` di dalam masing-masing `case`):**
   - **Untuk Paket 1 (Nasi Nusantara):**
     - Sub-varian `1` (Ayam Geprek): Tambahan harga Rp 5.000.
     - Sub-varian `2` (Rendang Sapi): Tambahan harga Rp 10.000.
     - Selain 1 atau 2: Otomatis pilih Ayam Geprek (+Rp 5.000) dengan pesan peringatan.
   - **Untuk Paket 2 (Western):**
     - Sub-varian `1` (Ukuran Reguler): Tambahan harga Rp 0.
     - Sub-varian `2` (Ukuran Jumbo / _Double Cheese_): Tambahan harga Rp 7.000.
   - **Untuk Paket 3 (Snack & Minuman):**
     - Minta input jumlah porsi (1–10). Jika memesan $\ge 3$ porsi, berikan potongan khusus Rp 3.000 dari total harga snack.

### 🖥️ Contoh Output yang Diharapkan (Soal 1)

```text
==================================================
        KIOS LABS SMART CANTEEN - PILIH MENU
==================================================
1. Paket Nasi Nusantara      (Dasar: Rp 20.000)
2. Paket Western / Pasta     (Dasar: Rp 28.000)
3. Paket Snack & Minuman     (Dasar: Rp 12.000)
--------------------------------------------------
Pilih Menu Utama (1-3): 1

-- Sub-Menu Pilihan Lauk --
1. Ayam Geprek (+Rp 5.000)
2. Rendang Sapi (+Rp 10.000)
Pilih Lauk (1/2): 2

[SUKSES] Pesanan: Nasi Nusantara (Rendang Sapi)
Subtotal Pesanan: Rp 30000
==================================================
```

---


## 🔹 SOAL 2: Modul Kalkulasi Diskon, Kemasan & Pembayaran (Tahap 2)

### 🎯 Tujuan
Menerapkan perhitungan potongan diskon, penentuan biaya kemasan, dan pemilihan metode pembayaran menggunakan **Operator Ternary (`? :`)** dan **`if-else`**.

### 📖 Deskripsi Kasus
Melanjutkan dari subtotal yang diperoleh pada Soal 1, sistem sekarang meminta informasi tipe penyajian (*Dine-In* vs *Takeaway*), memeriksa apakah pembeli memiliki **Kartu Siswa LABS**, serta menentukan metode pembayaran.

### ⚙️ Spesifikasi & Aturan Logika
1. **Biaya Kemasan (Wajib Operator Ternary `? :`):**
   - Input: Tipe Penyajian (`1` = Dine-in / Makan di tempat, `2` = Takeaway / Bungkus).
   - Jika Takeaway (`2`), dikenakan biaya kemasan ramah lingkungan sebesar **Rp 2.000**, jika Dine-in biaya = **Rp 0**.
2. **Diskon Pelajar LABS (Wajib Operator Ternary `? :`):**
   - Input: Status Kartu Siswa (`1` = Punya, `0` = Tidak Punya).
   - Jika `1` (Punya), dapatkan diskon sebesar **10%** dari subtotal pesanan. Jika `0`, diskon = **Rp 0**.
3. **Pilihan Jalur Pembayaran (`if-else` atau `switch`):**
   - `1` = Tunai / Cash (Uang pas atau kembalian dihitung).
   - `2` = Kartu Saldo Digital LABS (*Smart Card*).

### 🖥️ Contoh Output yang Diharapkan (Soal 2)
```text
Subtotal Menu: Rp 30000

Tipe Penyajian:
1. Dine-In (Makan di Tempat)
2. Takeaway (Bungkus)
Pilih (1/2): 2

Status Kepemilikan Kartu Siswa LABS? (1 = Ya, 0 = Tidak): 1

==================================================
               RINCIAN PEMBAYARAN                 
==================================================
Subtotal Makanan   : Rp 30000
Diskon Siswa (10%) : Rp 3000
Biaya Kemasan      : Rp 2000
--------------------------------------------------
TOTAL AKHIR BAYAR  : Rp 29000
==================================================
```

---

## 🔹 SOAL 3: Integrasi Sistem Lengkap Kios Cerdas LABS (Tahap 3 - Final)

### 🎯 Tujuan
Menggabungkan **Soal 1** dan **Soal 2** ke dalam satu program utuh yang terstruktur, serta menambahkan **sistem validasi saldo kartu siswa**, **proteksi limit transaksi harian**, dan **pencetakan struk pembayaran resmi**.

### 📖 Deskripsi Kasus
Gabungkan seluruh komponen kode program dari Soal 1 dan Soal 2. Pada tahap final ini, jika pembeli memilih pembayaran via **Kartu Saldo LABS**, program harus memeriksa apakah saldo mencukupi dan tidak melebihi batas maksimal jajan harian sekolah (Maksimal Rp 50.000 per transaksi).

### ⚙️ Spesifikasi & Aturan Tambahan (Integrasi Penuh)
1. **Inisialisasi Data Pengguna:**
   - Saldo awal Kartu Siswa ditentukan sebesar: **Rp 45.000**.
   - Batas Limit Transaksi Harian: **Rp 50.000**.
2. **Logika Validasi Pembayaran Digital (Wajib `nested if-else` & `guard clauses`):**
   - Jika Total Bayar > Rp 50.000: Batalkan transaksi dengan pesan `"[DITOLAK] Transaksi melebihi limit jajan harian siswa (Maks Rp 50.000)!"`.
   - Jika Saldo Kartu < Total Bayar: Batalkan transaksi dengan pesan `"[GAGAL] Saldo kartu tidak mencukupi! Sisa saldo Anda: Rp ..."`
   - Jika Saldo Mencukupi: Kurangi saldo kartu dengan total bayar dan cetak pesan `"[BERHASIL] Pembayaran sukses via Kartu Siswa LABS"`.
3. **Pencetakan Struk Resmi:**
   - Tampilkan rincian pesanan lengkap, status diskon, tipe penyajian, metode bayar, dan sisa saldo/kembalian.

---
