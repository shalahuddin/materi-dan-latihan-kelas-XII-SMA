# Hari 3: Operator Logika & Short-Circuit
## Menggabungkan Keputusan — AND, OR, NOT

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Menggabungkan kondisi dengan operator logika `&&` (AND), `||` (OR), `!` (NOT).
2. Membaca **tabel kebenaran** untuk ketiga operator.
3. Memahami bahwa nilai non-zero dianggap "true" dan nol dianggap "false".
4. Menjelaskan **short-circuit evaluation**: mengapa `&&` dan `||` bisa menghemat kerja.
5. Mengombinasikan operator relasional + logika dalam satu ekspresi.

---

## 💡 MATERI PEMBELAJARAN

### 1. Kenapa Butuh Operator Logika?

Syarat di dunia nyata sering majemuk:
* "Ikut lomba kalau **umur ≥ 17** **DAN** **tinggi ≥ 150**"
* "Dapat diskon kalau **member** **ATAU** **belanja ≥ Rp 100.000**"
* "**Tidak** boleh masuk kalau **tidak** memakai seragam"

Operator logika menggabungkan beberapa hasil perbandingan (`0`/`1`) menjadi satu keputusan (`0`/`1`).

### 2. Operator `&&` (AND)

Hasil **1** hanya jika **keduanya** 1.

| A | B | A && B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | **1** |

```c
printf("%d\n", 1 && 1);   // 1
printf("%d\n", 1 && 0);   // 0
printf("%d\n", 0 && 0);   // 0
```

Contoh nyata:
```c
int umur = 18;
int tinggi = 160;
printf("%d\n", umur >= 17 && tinggi >= 150);  // 1 (keduanya penuhi)
```

### 3. Operator `||` (OR)

Hasil **1** jika **minimal satu** di antaranya 1.

| A | B | A \|\| B |
|---|---|-----------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

```c
printf("%d\n", 1 || 0);   // 1
printf("%d\n", 0 || 0);   // 0

int member = 0;
int belanja = 150000;
printf("%d\n", member || belanja >= 100000);  // 1 (belanja cukup)
```

### 4. Operator `!` (NOT)

**Membalik** nilai: `!0 = 1`, `!1 = 0`.

| A | !A |
|---|---|
| 0 | 1 |
| 1 | 0 |

```c
printf("%d\n", !0);   // 1
printf("%d\n", !1);   // 0

int lampu_menyala = 1;
printf("Lampu mati? %d\n", !lampu_menyala);  // 0
```

> ⚠️ Jangan bingung `!=` (tidak sama dengan) dengan `!` di depan ekspresi. `a != b` adalah perbandingan; `!(a == b)` juga sama artinya dengan `a != b`. Keduanya valid.

### 5. Nilai Non-Zero = True, Nol = False

Dalam C, ekspresi logika **menerima angka berapa pun** sebagai "benar":
```c
printf("%d\n", 5 && 0);   // 1 && 0 = 0
printf("%d\n", 5 && 3);   // 1 && 1 = 1  (5 dan 3 keduanya non-zero)
printf("%d\n", 0 || -7);  // 0 || 1 = 1  (-7 non-zero = true)
printf("%d\n", !42);      // 0  (42 true → NOT true = false)
```

### 6. ⭐ Short-Circuit Evaluation — Berhenti Lebih Awal

C mengevaluasi `&&` dan `||` **dari kiri ke kanan** dan **berhenti lebih awal** jika hasil sudah pasti:

* `A && B`: jika `A` = 0, hasil pasti 0 → **`B` tidak dievaluasi**
* `A || B`: jika `A` = 1, hasil pasti 1 → **`B` tidak dievaluasi**

```c
int x = 0;
int hasil = 0 && (x = 5);   // x TIDAK menjadi 5! (kiri sudah 0)
printf("x = %d, hasil = %d\n", x, hasil);   // x = 0, hasil = 0

int y = 0;
int hasil2 = 1 || (y = 5);  // y TIDAK menjadi 5! (kiri sudah 1)
printf("y = %d, hasil2 = %d\n", y, hasil2); // y = 0, hasil2 = 1
```

**Kenapa penting?**
* Menghemat kerja (bagian kanan tidak dihitung)
* Aman: `pembagi != 0 && (10 / pembagi) > 2` — pembagian tidak terjadi kalau `pembagi` nol, jadi tidak error!

---

## 💻 LIVE CODING DEMO

### Demo 1 — Syarat Ikut Lomba

```c
/*
 * File: 05_logical_operators.c
 * Week: 03 - Operators & Expressions
 * Description: Demo operator logika &&, ||, ! dan short-circuit
 */

#include <stdio.h>

int main() {
    int umur = 18;
    int tinggi = 158;
    int member = 1;
    int belanja = 75000;

    // AND: harus dua-duanya
    printf("Ikut lomba? %d\n", umur >= 17 && tinggi >= 150);  // 1

    // OR: cukup salah satu
    printf("Dapat diskon? %d\n", member || belanja >= 100000); // 1

    // NOT
    printf("Belum cukup umur? %d\n", !(umur >= 17));          // 0

    // Kombinasi
    printf("Bonus member premium? %d\n",
           (member && belanja >= 50000) || umur >= 20);       // 1

    return 0;
}
```

### Demo 2 — Short-Circuit yang Terlihat

```c
#include <stdio.h>

int main() {
    int counter = 0;
    int a = 0;

    // a=0 → hasil pasti 0 → counter++ TIDAK dijalankan
    int r1 = a && (counter++);
    printf("r1 = %d, counter = %d\n", r1, counter);  // r1=0, counter=0

    int b = 1;
    // b=1 → hasil pasti 1 → counter++ TIDAK dijalankan
    int r2 = b || (counter++);
    printf("r2 = %d, counter = %d\n", r2, counter);  // r2=1, counter=0

    // Supaya dijalankan, letakkan counter di KIRI:
    int r3 = (counter++) || 0;
    printf("r3 = %d, counter = %d\n", r3, counter);  // r3=0, counter=1
    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1 — Syarat Masuk Kelas (25 menit)
* `hadir` (`int`, 1=ya 0=tidak), `tugas_dikumpul` (`int`)
* Cetak: `"Boleh masuk? %d"` dengan syarat **hadir DAN tugas dikumpul**
* Variasikan nilainya dan lihat hasilnya

### Latihan 2 — Diskon Pelanggan (25 menit)
* `is_member`, `total_belanja`
* Diskon jika **member** ATAU **belanja > 100000**
* Cetak hasil `0`/`1`

### Latihan 3 — Cetak Tabel Kebenaran (30 menit)
Buat program yang mencetak tabel kebenaran `&&` dan `||` untuk semua kombinasi `0`/`1`:
```c
printf("0 && 0 = %d\n", 0 && 0);
printf("0 && 1 = %d\n", 0 && 1);
// ... lengkapi sampai 1 && 1, lalu 0||0 ... 1||1
printf("!0 = %d, !1 = %d\n", !0, !1);
```

### Latihan 4 — Cek Tahun Kabisat (sederhana, 30 menit)
Tahun **kabisat** jika:
* habis dibagi 4, **DAN**
* tidak habis dibagi 100, **ATAU** habis dibagi 400

Preview rumusnya (kita potong yang sulit):
```c
int tahun = 2024;
int kabisat = (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
printf("2024 kabisat? %d\n", kabisat);
```
Coba juga `tahun = 1900` dan `tahun = 2000`.

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kesalahan | Contoh | Perbaikan |
|-----------|--------|-----------|
| `&` / `|` bukan logika | `a & b` adalah bitwise | Gunakan `&&` / `||` |
| Menulis `&&` dengan satu `&` | `(x>=17) & (y>=150)` | `&&` |
| Menyamakan `!` dengan `!=` | `!x` vs `x != 0` | `!x` membalik; `x != 0` membandingkan |
| Mengira `&&` dan `||` sama | lupa tabel kebenaran | Hafal: AND butuh semua, OR cukup satu |
| Tak sadar short-circuit | `x && (x=5)` mengira x berubah | Bagian kanan bisa dilewati |
| Tidak pakai kurung | `a && b || c` ambigu | `(a && b) || c` jelas |

---

## ✅ CHECKLIST KEBERHASILAN HARI 3
- [ ] Hafal tabel kebenaran `&&`, `||`, `!`
- [ ] Bisa menggabungkan perbandingan + logika
- [ ] Tahu kapan `&&` vs `||` dipakai
- [ ] Bisa menjelaskan short-circuit dengan contoh
- [ ] Program compile di **lokal**

---

## 🔮 PREVIEW HARI 4
Bilangan bulat dan desimal perlu **bekerja sama**. Besok: **casting** — cara mengubah tipe data dengan sadar (`(float)7 / 2 = 3.5`), dan konversi otomatis yang terjadi diam-diam.

---

**Logika membuat program cerdas. Keputusan majemuk dimulai dari sini. 🧩**
