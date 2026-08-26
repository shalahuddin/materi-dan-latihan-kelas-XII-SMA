---
title: Materi Hari 2 - Struktur Keputusan switch
---

# 🎯 TUJUAN PEMBELAJARAN
- Memahami sintaks dan penggunaan perintah `switch` dalam bahasa C.
- Mengetahui cara menangani `case` dan `default` serta pentingnya `break`.
- Membandingkan `switch` dengan rangkaian `if‑else` untuk kasus nilai diskrit.
- Mengidentifikasi dan menghindari kesalahan umum pada `switch`.

# 💡 MATERI PEMBELAJARAN
## 1. Struktur Dasar `switch`
```c
switch (ekspresi) {
    case nilai1:
        // blok kode untuk nilai1
        break;
    case nilai2:
        // blok kode untuk nilai2
        break;
    /* … */
    default:
        // blok kode jika tidak ada case yang cocok
}
```
- `ekspresi` harus menghasilkan nilai integral (int, char, enum).
- Setiap `case` harus diikuti oleh nilai konstan yang dapat dikonversi ke tipe ekspresi.
- `break;` menghentikan eksekusi lebih lanjut (fall‑through). Jika tidak ada `break`, eksekusi akan terus ke case berikutnya.

## 2. Penggunaan `default`
- `default` bersifat opsional tetapi **disarankan** untuk menangani nilai tak terduga.
- Diletakkan di akhir, namun posisi tidak berpengaruh pada alur eksekusi.

## 3. Contoh Praktis
```c
#include <stdio.h>

int main() {
    int hari;
    printf("Masukkan angka 1‑7 untuk hari (1=Senin): ");
    scanf("%d", &hari);

    switch (hari) {
        case 1: printf("Senin\n"); break;
        case 2: printf("Selasa\n"); break;
        case 3: printf("Rabu\n"); break;
        case 4: printf("Kamis\n"); break;
        case 5: printf("Jumat\n"); break;
        case 6: printf("Sabtu\n"); break;
        case 7: printf("Minggu\n"); break;
        default: printf("Input tidak valid!\n");
    }
    return 0;
}
```
- Pada contoh di atas, `default` menangani angka di luar 1‑7.

# 🛠️ GUIDED PRACTICE
1. **Latihan 1**: Buat program yang menerima huruf (A‑E) dan menampilkan nama buah (Apple, Banana, Cherry, Date, Elderberry) menggunakan `switch`.
2. **Latihan 2**: Tambahkan fitur “menu” dengan pilihan 1‑3; setiap pilihan mengeksekusi blok berbeda, gunakan `default` untuk menangani pilihan tak ada.
3. **Latihan 3**: Refaktor program penilaian nilai (A‑F) pada hari pertama menjadi `switch`.

# ⚠️ KESALAHAN UMUM PEMULA
- Lupa menambahkan `break;` sehingga terjadi fall‑through yang tidak diinginkan.
- Menggunakan tipe data yang tidak kompatibel (mis. `float`) dalam `switch`.
- Tidak menyertakan `default:` sehingga nilai tak terduga tidak ditangani.
- Menuliskan `case` berulang dengan nilai yang sama, menyebabkan error kompilasi.

# ✅ CHECKLIST KEBERHASILAN HARI 2
- [ ] Program menampilkan nama hari yang tepat berdasarkan angka input.
- [ ] Semua `case` memiliki `break;` kecuali yang memang di‑intentional untuk fall‑through.
- [ ] `default` menangani input yang tidak valid.
- [ ] Kode bebas error kompiler.

# 🔮 PREVIEW HARI 3
Mengenal operator ternary dan keputusan bersarang untuk menulis kode yang lebih ringkas dan efisien.
