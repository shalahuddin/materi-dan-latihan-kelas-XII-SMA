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
