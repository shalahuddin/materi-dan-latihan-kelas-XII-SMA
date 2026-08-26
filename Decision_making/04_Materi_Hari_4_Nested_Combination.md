---
title: Materi Hari 4 - Keputusan Bersarang & Kombinasi if‑else & switch
---

# 🎯 TUJUAN PEMBELAJARAN
- Menggabungkan `if‑else` dan `switch` dalam satu program untuk menangani logika keputusan kompleks.
- Memahami **keputusan bersarang** (nested) dan cara menghindari *deep nesting* dengan teknik *early return*.
- Menulis kode yang **terstruktur** agar mudah dipelihara dan dibaca.

# 💡 MATERI PEMBELAJARAN
## 1. Keputusan Bersarang dengan `if‑else`
```c
if (kondisi1) {
    if (kondisi2) {
        // aksi A
    } else {
        // aksi B
    }
} else {
    // aksi C
}
```
- **Masalah**: terlalu dalam dapat membuat kode sulit dibaca.
- **Solusi**: gunakan *guard clauses* (early returns) atau **switch** untuk memecah logika.

## 2. Kombinasi `if‑else` + `switch`
- Contoh: memproses nilai input, kemudian berdasarkan kategori nilai memilih sub‑menu dengan `switch`.
```c
int nilai;
scanf("%d", &nilai);
if (nilai < 0 || nilai > 100) {
    printf("Nilai tidak valid\n");
    return 0; // guard clause
}
/* kategori nilai */
char kategori;
if (nilai >= 80) kategori = 'A';
else if (nilai >= 70) kategori = 'B';
else if (nilai >= 60) kategori = 'C';
else kategori = 'D';

/* sub‑menu berdasarkan kategori */
switch (kategori) {
    case 'A':
        printf("Excellent!\n");
        break;
    case 'B':
        printf("Good!\n");
        break;
    case 'C':
        printf("Average.\n");
        break;
    case 'D':
        printf("Needs improvement.\n");
        break;
}
```
- Mengurangi *nesting* dengan memisahkan keputusan pertama dan kedua.

## 3. Menggunakan `else if` dengan `switch` dalam **loop**
```c
for (int i = 0; i < n; ++i) {
    int pilihan = menu[i];
    if (pilihan == 0) {
        break; // keluar dari loop
    } else {
        switch (pilihan) {
            case 1: /* ... */ break;
            case 2: /* ... */ break;
            default: printf("Pilihan tidak dikenal\n");
        }
    }
}
```
- Menunjukkan kombinasi kontrol alur dalam iterasi.

# 🛠️ GUIDED PRACTICE
1. **Latihan 1**: Buat program yang menerima dua angka, lalu:
   - Jika kedua angka **positif**, pilih `switch` untuk menampilkan operasi (`+`, `-`, `*`, `/`).
   - Jika salah satu **negatif**, tampilkan pesan “Tidak dapat proses” dan **keluar**.
2. **Latihan 2**: Refaktor contoh `if‑else` pada materi hari 1 menjadi fungsi `int classify(int x)` yang mengembalikan kode (`1` positif, `0` nol, `-1` negatif) dan gunakan `switch` untuk mencetak teks.
3. **Latihan 3**: Tambahkan *early return* pada contoh `switch` hari 2 untuk menangani nilai di luar 1‑7 sebelum masuk ke `switch`.

# ⚠️ KESALAHAN UMUM PEMULA
- Menumpuk terlalu banyak level `if` sehingga kode menjadi *pyramid of doom*.
- Menggunakan `switch` di dalam `if` tanpa `break;` menyebabkan *fall‑through* tak terduga.
- Mengabaikan *guard clause* sehingga kode tetap mengeksekusi logika tidak relevan setelah menemukan error.

# ✅ CHECKLIST KEBERHASILAN HARI 4
- [ ] Program menggabungkan `if‑else` dengan `switch` tanpa error.
- [ ] Kode bersih dari *deep nesting* berlebih.
- [ ] Semua skenario (valid, invalid, edge) ter‑handle.

# 🔮 PREVIEW HARI 5
Membahas **praktikum akhir**: penerapan seluruh konsep keputusan dalam mini‑project “Menu Penilaian Siswa” serta soal‑soal HOTS yang menuntut analisis pilihan kontrol.
