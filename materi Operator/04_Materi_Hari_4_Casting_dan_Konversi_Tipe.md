# Hari 4: Casting / Konversi Tipe
## Mengubah Tipe Data dengan Aman dan Sadar

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Menjelaskan perbedaan **konversi implisit** (otomatis) dan **casting eksplisit** (paksa).
2. Menggunakan sintaks casting `(tipe)ekspresi` untuk mendapatkan hasil desimal dari `int`.
3. Menjelaskan bahwa casting **memotong** (truncate), bukan membulatkan.
4. Menerapkan casting untuk masalah nyata: rata-rata, suhu, kalkulasi uang.
5. Memahami urutan promosi tipe `char → int → float → double`.

---

## 💡 MATERI PEMBELAJARAN

### 1. Masalahnya: `int / int` = int

```c
int nilai1 = 85;
int nilai2 = 80;
int rata = (nilai1 + nilai2) / 2;    // 82 (padahal 82.5)

printf("Rata-rata: %d\n", rata);      // 82
```

Dua `int` dibagi → hasil `int`, desimal dibuang. Tapi nilai ujian rata-rata sering **butuh desimal**. Solusinya: **casting**.

### 2. Casting Eksplisit — Memaksa Tipe

Sintaks: tulis tipe tujuan dalam **kurung di depan** ekspresi.

```c
(float) nilai1        // nilai1 dibaca sebagai float untuk operasi ini
(double) a / b        // a jadi double, hasilnya double
(int) 3.9             // jadi 3 (desimal dibuang)
```

```c
int nilai1 = 85;
int nilai2 = 80;

printf("%.2f\n", (float)(nilai1 + nilai2) / 2);   // 82.50
```

**Tiga cara yang hasilnya berbeda — pahami perbedaannya:**
```c
int a = 7, b = 2;

printf("%d\n", a / b);              // 3   (int / int)
printf("%.2f\n", (float)a / b);     // 3.50  (a jadi float → float / int = float)
printf("%d\n", (int)(a / b));       // 3   (sudah int, di-cast int lagi)
printf("%.2f\n", (float)(a / b));   // 3.00  (BAGI dulu jadi int 3, baru jadi float 3.0!)
```

> ⚠️ Perhatikan baris terakhir: `(float)(a / b)` menghitung `a / b` **sebagai int dulu** (hasil 3), baru mengubahnya jadi `3.0`. Untuk hasil `3.5`, cast **salah satu operand** sebelum membagi, bukan seluruh hasil.

### 3. Casting Memotong, Bukan Membulatkan

```c
printf("%d\n", (int)3.9);    // 3 (dipotong, bukan 4)
printf("%d\n", (int)3.1);    // 3
printf("%d\n", (int)-3.9);   // -3 (di C, mendekati nol)
```

Casting `float → int` **membuang bagian desimal**, tidak membulatkan. Untuk membulatkan dengan benar, kamu harus menambahkan 0.5 dulu (preview):
```c
int pembulatan = (int)(3.6 + 0.5);   // 4
int pembulatan2 = (int)(3.4 + 0.5);  // 3
```

### 4. Konversi Implisit — Otomatis, Tapi Perlu Disadari

Ketika tipe **berbeda** bertemu dalam satu ekspresi, C otomatis menaikkan tipe yang lebih kecil:

```c
int a = 10;
float b = 2.5;
printf("%.2f\n", a + b);     // 12.50 (int diubah otomatis jadi float)

double d = 10 / 3;           // 3.000000 (bukan 3.33!)
                             // 10/3 dihitung sebagai int dulu = 3
```

**Urutan promosi umum:** `char` → `int` → `float` → `double` (yang lebih "besar"/presisi menang).

> ⚠️ `double d = 10 / 3;` → kiri `int/int` = `3`, baru disimpan ke `double` jadi `3.0`. Cast perlu **sebelum** pembagian.

### 5. Mengapa Casting Penting?

| Situasi | Tanpa cast | Dengan cast |
|---------|-----------|-------------|
| Rata-rata 3 nilai | `(85+80+92)/3 = 85` | `(float)(85+80+92)/3 = 85.67` |
| Suhu Celsius→Fahrenheit | `(9/5)*c + 32` — `9/5 = 1` ❌ | `(9.0/5)*c + 32` ✅ |
| Harga per item | `total / jumlah = 33` | `(float)total/jumlah = 33.33` |

---

## 💻 LIVE CODING DEMO

### Demo 1 — Rata-Rata Tiga Nilai

```c
/*
 * File: 06_casting_demo.c
 * Week: 03 - Operators & Expressions
 * Description: Demo casting untuk rata-rata dan konversi suhu
 */

#include <stdio.h>

int main() {
    int uts = 85;
    int uas = 92;
    int tugas = 80;

    // Tanpa cast: int/int → int (hilang presisi)
    printf("Rata (tanpa cast) : %d\n", (uts + uas + tugas) / 3);

    // Dengan cast: hasil float
    printf("Rata (dengan cast): %.2f\n", (float)(uts + uas + tugas) / 3);

    // Konversi suhu
    int celsius = 30;
    // (9/5) itu int/int = 1 → salah! Pakai 9.0
    float fahrenheit = (9.0 / 5) * celsius + 32;
    printf("%d C = %.1f F\n", celsius, fahrenheit);

    return 0;
}
```

### Demo 2 — Casting Memotong

```c
#include <stdio.h>

int main() {
    float pi = 3.14159;

    printf("pi asli      : %.5f\n", pi);
    printf("(int) pi     : %d\n", (int)pi);       // 3
    printf("pi ke double : %.10f\n", (double)pi); // presisi lebih

    int detik = 95;
    printf("Menit: %d, Sisa detik: %d\n",
           detik / 60, detik % 60);               // 1 menit 35 detik

    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1 — Rata-Rata Ujian (25 menit)
* `uts = 78`, `uas = 85`, `tugas = 90`
* Tampilkan rata-rata dengan **2 desimal** memakai casting
* Bandingkan dengan versi tanpa casting — tulis keduanya

### Latihan 2 — Konversi Suhu (25 menit)
* `celsius = 100` (air mendidih)
* `fahrenheit = (9.0 / 5) * celsius + 32`
* Juga hitung `kelvin = celsius + 273.15`
* Tampilkan semuanya rapi

### Latihan 3 — Luas Lingkaran (Integrasi Minggu 02) (25 menit)
```c
float phi = 3.14159f;
int r = 7;                       // jari-jari
float luas = phi * r * r;        // int r dikalikan otomatis jadi float
printf("Luas lingkaran r=%d : %.2f\n", r, luas);
```
Tambahkan keliling: `float keliling = 2 * phi * r;`

### Latihan 4 — Prediksi & Cek Casting (30 menit)
Prediksi hasil, lalu verifikasi dengan program:
```c
printf("%d\n", (int)7.9);             // ?
printf("%.2f\n", (float)7 / 3);       // ?
printf("%.2f\n", 7 / 3.0);            // ?
printf("%d\n", (int)(2.7 + 0.5));     // ? (pembulatan)
printf("%.2f\n", (float)(9 / 5));     // ? (bagi dulu baru cast)
```

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kesalahan | Contoh | Perbaikan |
|-----------|--------|-----------|
| Cast setelah pembagian | `(float)(7/2)` → `3.0` | `(float)7/2` → `3.5` |
| Cast di kedua sisi tapi salah | `(float)(a/b)` | Cast salah satu operand: `(float)a/b` |
| Mengira casting membulatkan | `(int)3.9` dikira 4 | Casting memotong → `3` |
| Lupa `9/5` = 1 | `(9/5)*c + 32` | Tulis `9.0/5` atau `(float)9/5` |
| Menyimpan hasil int ke double | `double d = 10/3;` | `double d = 10.0/3;` |
| Variabel asli berubah | setelah `(float)a`, a tetap int | Casting **tidak** mengubah variabel asli |

---

## ✅ CHECKLIST KEBERHASILAN HARI 4
- [ ] Bisa menulis `(float)a / b` untuk hasil desimal
- [ ] Tahu beda `(float)(a/b)` vs `(float)a/b`
- [ ] Tahu casting memotong, bukan membulatkan
- [ ] Bisa menghitung rata-rata & konversi suhu
- [ ] Paham konversi implisit terjadi otomatis
- [ ] Program compile di **lokal**

---

## 🔮 PREVIEW HARI 5
Semua bahan sudah lengkap: variabel, tipe data, dan semua operator. Besok **Quiz 3** + **Praktikum "Smart Calculator"** — tiga program yang memakai seluruh kemampuanmu!

---

**Casting = mengubah cara komputer melihat angka, tanpa mengubah angkanya. 🔄**
