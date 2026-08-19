# Hari 1: Operator Aritmatika & Modulo
## Variabel Mulai Dihitung — Kalkulator Pertama

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Menjelaskan apa itu **operator**, **operand**, dan **ekspresi** dalam C.
2. Menggunakan operator aritmatika `+ - * / %` untuk menghitung.
3. Memahami perbedaan **integer division** (`int / int`) dan pembagian desimal.
4. Menggunakan operator **modulo** `%` untuk mendapatkan sisa bagi.
5. Menerapkan aturan **precedence** (urutan pengerjaan) dan tanda kurung.

---

## 💡 MATERI PEMBELAJARAN

### 1. Operator, Operand, dan Ekspresi
```c
int hasil = 10 + 3;
//           │  │  └─ operator
//           │  └──── operand (angka/nilai)
//           └─────── operand
//        "10 + 3" = EKSPRESI (perhitungan yang menghasilkan satu nilai)
```
* **Operator**: simbol yang melakukan operasi → `+`, `-`, `*`, `/`, `%`
* **Operand**: nilai yang dioperasikan → `10`, `3`, atau variabel
* **Ekspresi**: gabungan operand + operator yang menghasilkan **satu nilai**

Variabel hanyalah tempat menyimpan. Supaya berguna, nilainya harus **dioperasikan** — itulah tugas operator.

### 2. Operator Aritmatika Dasar

| Operator | Arti | Contoh | Hasil |
|----------|------|--------|-------|
| `+` | Penjumlahan | `7 + 2` | `9` |
| `-` | Pengurangan | `7 - 2` | `5` |
| `*` | Perkalian | `7 * 2` | `14` |
| `/` | Pembagian | `7 / 2` | **`3`** (lihat bawah!) |
| `%` | Sisa bagi (modulo) | `7 % 2` | `1` |

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    printf("a + b = %d\n", a + b);   // 13
    printf("a - b = %d\n", a - b);   // 7
    printf("a * b = %d\n", a * b);   // 30
    printf("a / b = %d\n", a / b);   // 3   <-- baca bagian integer division!
    printf("a %% b = %d\n", a % b);  // 1
    return 0;
}
```

> ⚠️ Perhatikan: untuk mencetak simbol `%`, tulis `%%` dalam `printf`. `printf("a %% b")` akan menampilkan `a % b`.

### 3. ⭐ Integer Division — Miskonsepsi Nomor 1 Pemula C

```c
int a = 7;
int b = 2;

printf("%d\n", a / b);      // 3  (bukan 3.5!)
```

**Ketika `int` dibagi `int`, hasilnya `int`** — bagian desimal **dibuang** (truncation), bukan dibulatkan.

| Ekspresi | Hasil | Penjelasan |
|----------|-------|------------|
| `7 / 2` | `3` | desimal `.5` dibuang |
| `9 / 4` | `2` | 9 = 4×2 + sisa 1 |
| `1 / 3` | `0` | 3×0 = 0, sisa 1 |
| `10 / 5` | `2` | habis |

Kalau kamu mau hasil desimal, minimal satu operand harus `float`/`double` — caranya kita pelajari hari ke-4 (**casting**). Contoh preview:
```c
printf("%.2f\n", (float)7 / 2);   // 3.50
```

### 4. ⭐ Modulo `%` — Sisa Bagi

`a % b` = **sisa** dari pembagian `a / b`.

```c
7 % 2 = 1      // 7 = 2*3 + 1
9 % 4 = 1      // 9 = 4*2 + 1
10 % 5 = 0     // habis dibagi
15 % 4 = 3     // 15 = 4*3 + 3
```

**Kegunaan praktis modulo:**
* Cek bilangan **genap/ganjil**: `x % 2 == 0` → genap, `x % 2 == 1` → ganjil
* Cek **kelipatan**: `x % 7 == 0` → kelipatan 7
* **Sisa uang**: belanja `Rp 100`, harga per item `Rp 30` → sisa `100 % 30 = 10`
* **Memecah angka**: `47 % 10 = 7` (angka terakhir), `47 / 10 = 4` (angka pertama)

```c
int sisa_uang = 100 % 30;   // 10
int genap_ganjil = 13 % 2;  // 1 → ganjil
```

### 5. Precedence — Urutan Pengerjaan

Sama seperti matematika, C punya urutan:
1. **Tanda kurung `()`** — dikerjakan paling dulu
2. **`*` `/` `%`** — kali, bagi, sisa
3. **`+` `-`** — tambah, kurang

```c
int x = 2 + 3 * 4;      // 2 + 12 = 14  (kali dulu)
int y = (2 + 3) * 4;    // 5 * 4 = 20   (kurung mengubah urutan)
int z = 10 - 2 + 3;     // 8 + 3 = 11   (kiri ke kanan untuk + -)
int w = 20 / 5 * 2;     // 4 * 2 = 8    (kiri ke kanan untuk * /)
```

> 💡 **Aturan emas**: jika ragu urutan pengerjaan, **pakai tanda kurung** `()` agar maksudmu jelas.

---

## 💻 LIVE CODING DEMO

### Demo 1 — Kalkulator Sederhana

```c
/*
 * File: 01_arithmetic_demo.c
 * Week: 03 - Operators & Expressions
 * Description: Demo operator aritmatika dasar + % dan integer division
 */

#include <stdio.h>

int main() {
    int a = 15;
    int b = 4;

    printf("=== KALKULATOR MINI ===\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d  (integer division!)\n", a / b);
    printf("a %% b = %d  (sisa bagi)\n", a % b);
    printf("(float)a / b = %.2f  (casting preview)\n", (float)a / b);

    return 0;
}
```

### Demo 2 — Genap/Ganjil & Sisa Uang

```c
#include <stdio.h>

int main() {
    int uang = 50000;
    int harga_per_item = 12000;
    int jumlah_item = uang / harga_per_item;
    int sisa = uang % harga_per_item;

    printf("Bisa beli %d item, sisa Rp %d\n", jumlah_item, sisa);

    int angka = 47;
    printf("Angka terakhir: %d\n", angka % 10);  // 7
    printf("Angka pertama : %d\n", angka / 10);  // 4
    return 0;
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1 — Harga & Diskon (25 menit)
* Simpan `harga` dan `jumlah_beli` di variabel `int`
* Hitung `total = harga * jumlah_beli`
* Hitung `total_diskon = total - (total * 20 / 100)`
* Tampilkan rapi dengan `printf`

> 💡 Hati-hati: `total * 20 / 100` memakai integer division. Prediksi hasilnya dulu!

### Latihan 2 — Bagi Rata Makanan (25 menit)
* `permen = 47`, `teman = 5`
* Hitung `per_teman = permen / teman` dan `sisa = permen % teman`
* Output: `"Tiap teman dapat X permen, sisa Y untukmu"`

### Latihan 3 — Genap atau Ganjil (20 menit)
* Simpan `angka` di variabel `int`
* Hitung `angka % 2`
* Output: `"13 adalah ganjil (13 % 2 = 1)"` — pakai `%%` di printf

### Latihan 4 — Prediksi Ekspresi (30 menit)
Sebelum menjalankan program, prediksi hasil ekspresi berikut. Lalu cek dengan program:
```c
int a = 8 + 2 * 3;          // ?
int b = (8 + 2) * 3;        // ?
int c = 17 / 5;             // ?
int d = 17 % 5;             // ?
int e = 2 + 3 * 4 / 2;      // ?
int f = (2 + 3) * (4 - 1);  // ?
```
Bandingkan prediksimu dengan hasil compile. Jika berbeda, diskusikan mengapa.

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kesalahan | Contoh | Perbaikan |
|-----------|--------|-----------|
| Lupa integer division | `int x = 7/2; printf("%f", x);` | Pahami `7/2` = `3`; cast bila butuh desimal |
| Mencetak `%` polos | `printf("7 %% 2");` → error/salah | Pakai `%%` |
| Mengira `/` membulatkan | `9/4` dikira `2.25` | `int/int` memotong → `2` |
| Salah urutan operasi | `2 + 3 * 4` dikira 20 | `*` dulu → `14` |
| Modulo dengan operand lebih besar | `3 % 7` | hasilnya `3` (3 = 7×0 + 3) |
| Mengabaikan kurung | `a + b * c` | Pakai `()` bila maksudnya `(a+b)*c` |

---

## ✅ CHECKLIST KEBERHASILAN HARI 1
- [ ] Bisa menjelaskan operator, operand, ekspresi
- [ ] Tahu hasil `7 / 2` dalam int (bukan `3.5`)
- [ ] Bisa memakai `%` untuk sisa bagi
- [ ] Prediksi precedence dengan benar
- [ ] Semua program compile di **lokal**

---

## 🔮 PREVIEW HARI 2
Besok variabelmu tidak hanya **dihitung**, tapi juga **dibandingkan** (`==`, `<`, `>`) dan **diperbarui dengan cepat** (`+=`, `-=`). Program mulai bisa membuat keputusan!

---

**Variabel itu diam. Operator yang membuatnya hidup. ⚡**
