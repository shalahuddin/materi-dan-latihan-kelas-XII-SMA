# Hari 3: Scope Variabel (Lokal vs Global) & Lifetime
## Batas Wilayah Hidup Variabel dan Bahaya Variable Shadowing

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Menjelaskan konsep **Scope (Lingkup Visibilitas)** dan **Lifetime (Masa Hidup)** variabel dalam memori komputer.
2. Membedakan karakteristik dan lokasi deklarasi **Variabel Lokal (Block Scope)** vs **Variabel Global (File Scope)**.
3. Menganalisis fenomena **Variable Shadowing** ketika nama variabel lokal bertabrakan dengan variabel global.
4. Mengidentifikasi bahaya laten (*side-effects* & *spaghetti state*) dari ketergantungan pada variabel global dalam proyek kolaboratif.
5. Menerapkan *best practices* perancangan software: membatasi aksesibilitas data (*Principle of Least Privilege*) dan mengandalkan parameter + return value.

---

## 💡 MATERI PEMBELAJARAN

### 1. Apa Itu Scope dan Lifetime?
Dua konsep ini menentukan di mana variabel bisa dilihat dan berapa lama variabel bertahan di RAM:

- **Scope (Lingkup Visibilitas)**: Di bagian baris kode mana saja nama sebuah variabel **dapat dikenali dan diakses**.
- **Lifetime (Masa Hidup)**: Durasi waktu sejak variabel dialokasikan di RAM sampai saat variabel tersebut dihancurkan/dikosongkan kembali oleh sistem.

```
+------------------------------------------------------------------+
|                     FILE PROGRAM UTAMA                           |
|                                                                  |
|   [ Variabel Global: int skor_total = 0; ]                       |
|   --> Scope: Seluruh file dari baris ini hingga paling bawah     |
|   --> Lifetime: Selama program berjalan                          |
|                                                                  |
|   void hitung() {                                                |
|       [ Variabel Lokal: int langkah = 5; ]                       |
|       --> Scope: Hanya di dalam kurung kurawal fungsi hitung()   |
|       --> Lifetime: Hanya saat fungsi hitung() sedang aktif      |
|   }                                                              |
+------------------------------------------------------------------+
```

---

### 2. Variabel Lokal (Local Variable / Block Scope)
Variabel lokal adalah variabel yang dideklarasikan **di dalam** badan fungsi atau di dalam blok kurung kurawal `{ ... }`.

**Ciri-ciri Variabel Lokal:**
1. **Lahir & Musnah Otomatis**: Diciptakan saat eksekusi program memasuki blok `{`, dan langsung lenyap saat eksekusi keluar dari blok `}` (*automatic storage duration*).
2. **Terisolasi Aman**: Fungsi lain tidak dapat melihat atau membaca variabel ini secara langsung. Kamu bisa membuat variabel bernama `int x;` di dalam `fungsi_a()` dan `int x;` di dalam `fungsi_b()` tanpa saling bentrok!
3. **Nilai Awal Sampah**: Jika tidak diinisialisasi secara eksplisit (misal hanya `int angka;`), nilainya berisi bit-bit acak sisa memori sebelumnya (*garbage value*).

```c
void fungsi_satu(void) {
    int rahasia = 1234; // Variabel lokal fungsi_satu
}

void fungsi_dua(void) {
    // ERROR KOMPILASI!
    // printf("%d", rahasia); // 'rahasia' undeclared identifier!
}
```

---

### 3. Variabel Global (Global Variable / File Scope)
Variabel global adalah variabel yang dideklarasikan **di luar seluruh fungsi**, biasanya diletakkan di baris-baris paling atas program (di bawah baris `#include`).

**Ciri-ciri Variabel Global:**
1. **Dapat Diakses Siapa Saja**: Semua fungsi yang berada di bawah deklarasinya bisa membaca, mengubah, dan menimpa nilainya kapan saja.
2. **Hidup Abadi**: Lahir saat program mulai dijalankan dan baru mati ketika program ditutup (*static storage duration*).
3. **Inisialisasi Otomatis**: Jika kamu tidak mengisi nilainya, bahasa C secara otomatis menginisialisasinya menjadi `0` (atau `0.0` / `'\0'`).

```c
#include <stdio.h>

int skor_global = 0; // VARIABEL GLOBAL

void tambah_skor(void) {
    skor_global += 10; // Mengubah variabel luar langsung
}

int main() {
    printf("Skor awal: %d\n", skor_global); // 0
    tambah_skor();
    printf("Skor akhir: %d\n", skor_global); // 10
    return 0;
}
```

---

### 4. ⭐ Bahaya Variabel Global: Mengapa Industri Membencinya?
Pemula sering berpikir: *"Wah, kalau variabel global bisa dibaca semua fungsi, mending semua variabel dijadikan global saja supaya tidak repot kirim-kirim parameter!"*

Ini adalah **jebakan terbesar** dalam rekayasa perangkat lunak! Berikut alasan mengapa programmer profesional sangat membatasi variabel global:

1. **Jejak Kerusakan Misterius (Spaghetti State)**:  
   Jika programmu memiliki 10.000 baris dan 50 fungsi, lalu nilai variabel global tiba-tiba berubah menjadi minus atau corrupt, **fungsi mana yang menjadi biang keroknya?** Kamu harus memeriksa ke-50 fungsi satu per satu!
2. **Efek Samping Tersembunyi (*Side Effects*)**:  
   Fungsi yang bergantung pada variabel global tidak lagi independen. Kamu tidak bisa menguji fungsi tersebut secara terpisah (*unit testing*) tanpa menyetel ulang kondisi global.
3. **Tabrakan dalam Tim**:  
   Saat bekerja kelompok, temanmu bisa saja secara tidak sengaja mengubah variabel global yang sedang kamu pakai untuk perhitungan lain.

> 💡 **Aturan Emas LABS:**  
> Selalu gunakan **variabel lokal** yang dilewatkan lewat **parameter fungsi** dan dikembalikan lewat **return value**. Anggap variabel global sebagai opsi darurat terakhir, bukan kebiasaan!

---

### 5. ⭐ Fenomena Variable Shadowing (Pembajakan Nama)
Apa yang terjadi jika ada variabel lokal yang memiliki nama persis sama dengan variabel global?

```c
#include <stdio.h>

int angka = 100; // GLOBAL

void tes_shadowing(void) {
    int angka = 5; // LOKAL (Memiliki nama yang sama dengan global!)
    printf("Nilai angka di dalam fungsi: %d\n", angka);
}

int main() {
    tes_shadowing();
    printf("Nilai angka di main: %d\n", angka);
    return 0;
}
```

**Output:**
```text
Nilai angka di dalam fungsi: 5
Nilai angka di main: 100
```

**Mekanisme Variable Shadowing:**
- Di dalam `tes_shadowing()`, variabel lokal `int angka = 5` **"membayangi" / menutupi** variabel global `angka`.
- Selama berada di dalam fungsi tersebut, setiap kali nama `angka` dipanggil, kompilator akan memprioritaskan variabel yang paling dekat (lokal).
- Variabel global tidak rusak atau tertimpa, hanya saja ia menjadi "tak terlihat" sementara waktu di wilayah tersebut.
- Hal yang sama juga berlaku pada blok bersarang (*nested block* seperti di dalam blok `if` atau `for`).

---

## 💻 LIVE CODING DEMO

Mari kita pelajari kode demonstrasi berikut yang memperlihatkan perbedaan scope dan simulasi bahaya *side effect* variabel global.

```c
/*
 * File: 05_local_global_shadowing.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi scope lokal, global, shadowing, dan efek samping
 *
 * Compile:
 *   gcc 05_local_global_shadowing.c -o scope_demo
 *   .\scope_demo.exe
 */

#include <stdio.h>

// 1. Variabel Global
int saldo_kas_sekolah = 500000; // Semua panitia bisa lihat

// Prototipe
void belanja_panitia_konsumsi(int biaya);
void belanja_panitia_dekorasi(int biaya);
void demo_shadowing(void);

int main() {
    printf("=== DEMO SCOPE DAN LIFETIME MEMORI ===\n\n");
    printf("[AWAL] Saldo Kas Sekolah: Rp%d\n", saldo_kas_sekolah);

    // Dua fungsi berbeda memodifikasi satu variabel global yang sama
    belanja_panitia_konsumsi(150000);
    belanja_panitia_dekorasi(200000);

    printf("[AKHIR] Sisa Saldo Kas Sekolah: Rp%d\n\n", saldo_kas_sekolah);

    // Menguji Fenomena Variable Shadowing
    printf("--- Menguji Variable Shadowing ---\n");
    demo_shadowing();
    printf("[Cek Main] Saldo kas global tetap bernilai: Rp%d\n", saldo_kas_sekolah);

    // Uji Block Scope (Variabel lahir dan mati di dalam kurung kurawal)
    {
        int diskon_spesial = 25000; // Hanya hidup di dalam blok kurung ini!
        printf("[Dalam Blok] Diskon aktif: Rp%d\n", diskon_spesial);
    }
    // Baris berikut jika di-uncomment akan gagal compile:
    // printf("%d", diskon_spesial); // Error: undeclared identifier!

    return 0;
}

void belanja_panitia_konsumsi(int biaya) {
    // 'biaya' adalah variabel lokal fungsi ini
    saldo_kas_sekolah -= biaya; // Side-effect: merubah variabel global!
    printf("  -> Panitia Konsumsi belanja Rp%d. Saldo kas kini: Rp%d\n", biaya, saldo_kas_sekolah);
}

void belanja_panitia_dekorasi(int biaya) {
    saldo_kas_sekolah -= biaya;
    printf("  -> Panitia Dekorasi belanja Rp%d. Saldo kas kini: Rp%d\n", biaya, saldo_kas_sekolah);
}

void demo_shadowing(void) {
    // Variabel lokal dengan nama identik dengan variabel global
    int saldo_kas_sekolah = 999; 
    printf("  -> [Dalam demo_shadowing] Variabel lokal 'saldo_kas_sekolah' = Rp%d\n", saldo_kas_sekolah);
    printf("  -> Variabel global sedang tertutup bayang-bayang (shadowed)!\n");
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1: Tracing Output Shadowing Bertingkat (25 menit)
Prediksikan keluaran program berikut dengan menggambar tabel status variabel sebelum mengompilasinya:
```c
#include <stdio.h>

int x = 10;

void fungsi_uji(void) {
    int x = 20;
    {
        int x = 30;
        printf("Tingkat 3: x = %d\n", x);
    }
    printf("Tingkat 2: x = %d\n", x);
}

int main() {
    fungsi_uji();
    printf("Tingkat 1: x = %d\n", x);
    return 0;
}
```

### Latihan 2: Refactoring "Dosa" Global Variable (35 menit)
Seorang siswa membuat program perhitungan berat badan ideal yang buruk karena semua variabelnya global:
```c
// KODE BURUK - REFACTOR JADI BERSIH!
#include <stdio.h>
int tinggi;
float ideal;

void hitung(void) {
    ideal = (tinggi - 100) - ((tinggi - 100) * 0.10);
}

int main() {
    tinggi = 170;
    hitung();
    printf("Ideal: %.1f kg\n", ideal);
    return 0;
}
```
**Tugasmu**: Hapus semua variabel global! Ubah fungsi `hitung` agar menerima parameter `int tinggi_badan` dan mengembalikan nilai `float`. Tampung hasilnya di variabel lokal fungsi `main()`.

### Latihan 3: Eksperimen Deteksi Garbage Value (30 menit)
Buat program dengan fungsi `void tampil_sampah(void)` yang mendeklarasikan tiga variabel lokal tanpa inisialisasi: `int a; float b; char c;`. Cetak ketiganya dengan `printf`.
- Amati output angka aneh yang keluar di terminal.
- Diskusikan: Mengapa variabel lokal wajib diberi nilai awal (*initialization*), sedangkan variabel global otomatis bernilai nol?

### Latihan 4: Desain Sistem Dompet Digital Anti-Side Effect (40 menit)
Rancang program dompet digital dengan dua transaksi:
1. `int top_up(int saldo_sekarang, int nominal);`
2. `int bayar_qr(int saldo_sekarang, int nominal);` (Jika saldo tidak cukup, batalkan transaksi dan beri pesan peringatan).
- Aturan wajib: Dilarang menggunakan variabel global sama sekali! Semua status saldo dikelola di dalam variabel lokal `main()` dan diperbarui lewat nilai kembalian fungsi.

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kasus Kesalahan | Contoh Kode Salah | Penjelasan & Perbaikan |
|---|---|---|
| **Mengakses Variabel Lokal dari Luar** | Fungsi A punya `int n;`<br>Fungsi B mencoba `printf("%d", n);` | Variabel lokal tidak ada di luar fungsinya. Solusi: Oper nilai `n` sebagai parameter saat memanggil fungsi B. |
| **Mengharapkan Nilai Lokal Bertahan** | Fungsi dipanggil 2 kali, berharap nilai variabel lokalnya bertambah dari panggilan pertama | Setiap kali fungsi selesai, variabel lokal dihancurkan. Pada panggilan kedua, variabel lahir baru dari awal. |
| **Mendeklarasikan Ulang di Scope Sama** | `int x = 5; int x = 10;` *(dalam satu fungsi)* | Error *redeclaration of 'x'*. Kamu tidak boleh menduplikasi deklarasi nama yang sama di dalam satu scope yang sama. |
| **Shadowing yang Tidak Disengaja** | Menulis `int saldo = 100;` di dalam blok `if`, padahal di atas sudah ada `int saldo;` | Variabel baru tercipta di dalam `if` dan menutupi variabel luar, menyebabkan variabel luar tidak terupdate saat keluar dari `if`. |

---

## ✅ CHECKLIST KEBERHASILAN HARI 3
- [ ] Bisa membedakan scope lokal (block scope) dan scope global (file scope).
- [ ] Paham konsep lifetime (variabel lokal dihancurkan begitu fungsi berakhir).
- [ ] Mengerti mengapa variabel lokal yang tidak diisi menghasilkan *garbage value*.
- [ ] Mampu menganalisis efek *variable shadowing* saat nama variabel bertabrakan.
- [ ] Mampu merancang program bebas variabel global dengan memanfaatkan parameter dan nilai kembalian secara murni.

---

## 🔮 PREVIEW HARI 4
Sekarang kodemu sudah rapi dengan fungsi-fungsi independen. Tapi bagaimana jika kodemu mencapai ribuan baris dalam satu file? Besok kita akan naik level ke tingkat arsitektur software profesional: **Pemrograman Modular**. Kita akan memecah kode menjadi file header `.h` dan file implementasi `.c`, serta mempelajari perintah sakti GCC untuk mengompilasi proyek multi-source!

---

**"Variabel yang baik tahu batas tempat ia hidup dan kapan ia harus beristirahat. Hindari global state, cintai fungsi murni." 🛡️**
