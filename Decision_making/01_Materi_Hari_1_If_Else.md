---
title: Materi Hari 1 - Struktur Keputusan if‑else
---

# 🎯 TUJUAN PEMBELAJARAN
- Memahami sintaks dasar `if`, `else if`, dan `else` dalam bahasa C.
- Mengidentifikasi kapan harus menggunakan keputusan bertingkat.
- Menghindari kesalahan umum pada kondisi kontrol.

# 💡 MATERI PEMBELAJARAN
## 1. Struktur Dasar `if`
```c
if (kondisi) {
    // blok kode dijalankan bila kondisi bernilai true (non‑zero)
}
```
- Kondisi berupa ekspresi yang mengembalikan nilai integer.
- Nilai selain 0 dianggap **true**, 0 dianggap **false**.

## 2. Menambahkan `else`
```c
if (kondisi) {
    // true‑branch
} else {
    // false‑branch
}
```
- `else` mengeksekusi blok alternatif bila kondisi false.

## 3. Keputusan Bertingkat dengan `else if`
```c
if (kondisi1) {
    // blok 1
} else if (kondisi2) {
    // blok 2
} else {
    // blok default
}
```
- Digunakan ketika ada **lebih dari dua** kemungkinan.

# 🛠️ PRAKTIKUM KODE (contoh)
```c
#include <stdio.h>

int main() {
    int angka;
    printf("Masukkan sebuah angka: ");
    scanf("%d", &angka);

    if (angka > 0) {
        printf("Positif\n");
    } else if (angka < 0) {
        printf("Negatif\n");
    } else {
        printf("Nol\n");
    }
    return 0;
}
```
- **Latihan**: Ubah program sehingga menilai apakah angka **ganjil** atau **genap** dengan tambahan **positif/negatif**.

# ⚠️ KESALAHAN UMUM PEMULA
- Menggunakan satu tanda `=` alih‑alih `==` pada kondisi.
- Lupa menutup tanda kurung `()` setelah kondisi.
- Tidak menambahkan `{}` pada blok multi‑pernyataan; hanya satu pernyataan yang akan terasosiasi.

# ✅ CHECKLIST KEBERHASILAN HARI 1
- [ ] Program dapat membedakan tiga rentang nilai (positif, negatif, nol).
- [ ] Semua error kompilasi telah di‑atasi.
