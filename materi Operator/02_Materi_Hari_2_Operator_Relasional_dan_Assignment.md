# Hari 2: Operator Relasional & Assignment Gabungan

## Membandingkan Nilai dan Memperbarui Variabel dengan Cepat

---

## 🎯 TUJUAN PEMBELAJARAN

Setelah pembelajaran hari ini, kamu diharapkan dapat:

1. Membandingkan dua nilai dengan operator relasional `== != < > <= >=`.
2. Membaca hasil perbandingan sebagai integer: `0` (false) atau `1` (true).
3. Membedakan operator `=` (assignment) dan `==` (perbandingan) — sumber bug terbesar di C.
4. Menggunakan operator assignment gabungan `+= -= *= /= %=`.
5. Mengenali increment/decrement `++` / `--` sebagai preview.

---

## 💡 MATERI PEMBELAJARAN

### 1. Operator Relasional — "Apakah ini benar?"

| Operator | Arti               | Contoh   | Hasil |
| -------- | ------------------ | -------- | ----- |
| `==`     | sama dengan        | `5 == 5` | `1`   |
| `!=`     | tidak sama dengan  | `5 != 5` | `0`   |
| `<`      | kurang dari        | `3 < 7`  | `1`   |
| `>`      | lebih dari         | `3 > 7`  | `0`   |
| `<=`     | kurang dari / sama | `5 <= 5` | `1`   |
| `>=`     | lebih dari / sama  | `3 >= 7` | `0`   |

**Hasil perbandingan selalu berupa integer:**

- `1` = benar (true)
- `0` = salah (false)

```c
printf("%d\n", 5 > 3);    // 1
printf("%d\n", 5 == 3);   // 0
printf("%d\n", 5 != 3);   // 1
printf("%d\n", 5 <= 5);   // 1
```

Nilai `1`/`0` ini nanti menjadi **bahan bakar** untuk `if` (Minggu 04) dan operator logika (Hari 3).

### 2. ⭐ `=` vs `==` — Jangan Tertukar!

```c
int umur = 17;        // '='  : ASSIGNMENT (isi variabel)
int cek = (umur == 17); // '==' : PERBANDINGAN (apakah sama?)
```

- `=` → **memasukkan** nilai ke variabel
- `==` → **mempertanyakan** apakah dua nilai sama

> ⚠️ Di C, `umur = 17` **selalu** menghasilkan nilai 17 (assignment mengembalikan nilai yang diisi). Jadi `umur == 17` adalah perbandingan, sedangkan `umur = 17` adalah pengisian. Banyak bug lahir karena menulis `=` padahal maksudnya `==`. Program tetap compile, tapi hasilnya salah diam-diam.

```c
int a = 5;
int b = 5;

printf("%d\n", a == b);   // 1 (benar: 5 sama dengan 5)
printf("%d\n", a = b);    // 5 (ini mengisi a dengan b, bukan membandingkan!)
```

### 3. Assignment Gabungan — Menulis Lebih Singkat

Kamu sering menulis `x = x + 5`. C punya versi singkatnya:

| Penulisan panjang | Singkatan | Arti        |
| ----------------- | --------- | ----------- |
| `x = x + 5`       | `x += 5`  | tambah 5    |
| `x = x - 5`       | `x -= 5`  | kurang 5    |
| `x = x * 5`       | `x *= 5`  | kali 5      |
| `x = x / 5`       | `x /= 5`  | bagi 5      |
| `x = x % 5`       | `x %= 5`  | sisa bagi 5 |

```c
int skor = 100;
skor += 50;        // skor = 150
skor *= 2;         // skor = 300
skor -= 80;        // skor = 220
skor /= 2;         // skor = 110
skor %= 100;       // skor = 10
```

**Kegunaan:** counter game, akumulasi total, nilai yang bertambah berulang.

### 4. Increment & Decrement (Preview)

```c
int nyawa = 3;
nyawa++;        // sama dengan nyawa += 1 → 4
nyawa--;        // sama dengan nyawa -= 1 → 3
```

`++` dan `--` menambah/mengurangi 1. Detail posisi `++x` vs `x++` akan dibahas di Minggu 06 (loops). Hari ini cukup kenali.

### 5. ⭐ Berhati-hati Membandingkan Float

```c
printf("%d\n", 0.1 + 0.2 == 0.3);   // 0  (?!)
```

Angka desimal di komputer disimpan dalam biner sehingga sering **tidak persis** (`0.1 + 0.2` = `0.30000000000000004`). Membandingkan float dengan `==` bisa mengecoh. Preview solusi: bandingkan dengan **toleransi** (selisihnya sangat kecil):

```c
float selisih = (0.1 + 0.2) - 0.3;
if (selisih < 0.000001) printf("dianggap sama\n");  // detail if di Minggu 04
```

---

## 💻 LIVE CODING DEMO

### Demo 1 — Cek Usia & Kelulusan

```c
/*
 * File: 03_relational_demo.c
 * Week: 03 - Operators & Expressions
 * Description: Demo operator relasional: hasil 0/1
 */

#include <stdio.h>

int main() {
    int umur = 16;
    int nilai = 80;

    printf("Umur  : %d\n", umur);
    printf("Nilai : %d\n", nilai);

    printf("Sudah 17+?  %d\n", umur >= 17);     // 0
    printf("Lulus (>=75)? %d\n", nilai >= 75);  // 1
    printf("Nilai pas 80? %d\n", nilai == 80);  // 1
    printf("Nilai beda 80? %d\n", nilai != 80); // 0

    // Assignment gabungan
    int skor = 0;
    skor += 100;   // menang ronde 1
    skor += 50;    // menang ronde 2
    skor -= 30;    // kena penalti
    printf("\nSkor akhir: %d\n", skor);         // 120

    return 0;
}
```

### Demo 2 — `=` vs `==` (Awas Bug!)

```c
#include <stdio.h>

int main() {
    int umur = 17;

    // BENAR: perbandingan
    printf("umur == 17 ? %d\n", umur == 17);

    // BAHAYA: ini bukan membandingkan, tapi MENGISI umur menjadi 17
    // printf("%d\n", umur = 17);  // mengubah nilai umur!

    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1 — Bandingkan Dua Angka (20 menit)

- Simpan `angka1 = 23`, `angka2 = 45` di variabel `int`
- Cetak hasil `==`, `!=`, `<`, `>`, `<=`, `>=`
- Output contoh: `"23 > 45 ? 0"`

### Latihan 2 — Cek Kelulusan (25 menit)

- `nilai_uts = 82`, `nilai_uas = 70`
- `rata_rata = (nilai_uts + nilai_uas) / 2` — awas integer division!
- Cetak: `"Rata-rata = 76"` dan `"Lulus? 1"` (jika `rata_rata >= 75`)

### Latihan 3 — Akumulasi Skor Game (25 menit)

- Mulai `skor = 0`
- `+= 100` (menang), `+= 50` (bonus), `-= 40` (penalti), `*= 2` (double point)
- Cetak skor di tiap langkah

### Latihan 4 — Tantangan: Swap Tanpa Variabel Sementara (30 menit)

Dengan **hanya** `+` dan `-`, tukar nilai `a` dan `b`:

```c
int a = 7, b = 13;
// ... tanpa int temp; hanya a = ... b = ... a = ...
printf("Setelah swap: a = %d, b = %d\n", a, b);  // a = 13, b = 7
```

Petunjuk: `a = a + b; b = a - b; a = a - b;`

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kesalahan                            | Contoh                                                               | Perbaikan                            |
| ------------------------------------ | -------------------------------------------------------------------- | ------------------------------------ |
| `=` dipakai untuk membandingkan      | `if (x = 5)` keliru                                                  | Gunakan `==`                         |
| Mengira hasil `<` berupa teks        | `5 > 3` "harusnya true"                                              | Hasilnya integer `1`                 |
| Lupa integer division pada rata-rata | `(82 + 70) / 2` = `76` (ok) tapi `(75 + 70) / 2` = `72` padahal 72.5 | Cast bila butuh presisi              |
| Membandingkan float dengan `==`      | `0.1 + 0.2 == 0.3` → `0`                                             | Pakai toleransi / bandingkan selisih |
| Mengira `x += 5` tidak mengubah x    | `printf("%d", x += 5)`                                               | `+=` mengubah nilai x                |

---

## ✅ CHECKLIST KEBERHASILAN HARI 2

- [ ] Bisa membandingkan dua nilai dan membaca hasil `0`/`1`
- [ ] Tidak pernah tertukar `=` vs `==`
- [ ] Mahir memakai `+= -= *= /= %=`
- [ ] Paham kenapa float `==` berbahaya
- [ ] Program compile di **lokal**

---

## 🔮 PREVIEW HARI 3

Banyak keputusan butuh **lebih dari satu syarat**: "ikut lomba kalau umur ≥ 17 **DAN** tinggi ≥ 150". Besok: operator logika `&&`, `||`, `!` dan **short-circuit evaluation**.

---

**Program yang bisa membandingkan = program yang mulai bisa berpikir. 🧠**
