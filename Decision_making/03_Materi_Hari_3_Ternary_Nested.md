---
title: Materi Hari 3 - Operator Ternary & Keputusan Bersarang
---

# 🎯 TUJUAN PEMBELAJARAN
- Memahami cara kerja **operator ternary** (`condition ? expr1 : expr2`).
- Menggunakan ternary untuk menulis keputusan satu‑baris yang ringkas.
- Menggabungkan beberapa keputusan bersarang (nested) menggunakan `if‑else` dan ternary.
- Mengidentifikasi kapan ternary lebih tepat daripada `if‑else` dan sebaliknya.

# 💡 MATERI PEMBELAJARAN
## 1. Sintaks Operator Ternary
```c
result = (kondisi) ? nilai_jika_true : nilai_jika_false;
```
- Nilai yang dikembalikan bisa berupa variabel, literal, atau ekspresi.
- Hanya **satu** pernyataan; tidak dapat menampung blok multi‑pernyataan.

## 2. Contoh Dasar
```c
int a = 5;
int b = (a > 0) ? 1 : -1;   // b menjadi 1 karena a > 0
```
## 3. Nested Ternary (Keputusan Bersarang)
```c
char *grade = (nilai >= 80) ? "A" :
               (nilai >= 70) ? "B" :
               (nilai >= 60) ? "C" : "D";
```
- Membaca dari kiri ke kanan; setiap `:` memisahkan **true** dan **false** bagian.

## 4. Kapan Memakai Ternary vs `if‑else`
| Situasi | Ternary | if‑else |
|---|---|---|
| Penugasan sederhana (satu ekspresi) | ✅ Ringkas | ❌ Verbose |
| Lebih dari satu pernyataan atau logika kompleks | ❌ Tidak cocok | ✅ Lebih jelas |
| Membutuhkan blok kode (mis. printf) | ❌ Tidak dapat | ✅ Dapat |

# 🛠️ GUIDED PRACTICE
1. **Latihan 1**: Ubah contoh penilaian nilai pada hari pertama menjadi satu baris menggunakan ternary.
2. **Latihan 2**: Buat program yang menerima usia dan menghasilkan kategori (`"Anak"`, `"Remaja"`, `"Dewasa"`, `"Lansia"`) menggunakan **nested ternary**.
3. **Latihan 3**: Refaktor kode `if‑else` pada contoh `positif/negatif/nol` menjadi ternary dan bandingkan panjang kode.

# ⚠️ KESALAHAN UMUM PEMULA
- Menulis **nested ternary** tanpa menambahkan tanda kurung yang tepat, menyebabkan urutan evaluasi tidak sesuai harapan.
- Menggunakan ternary untuk blok multi‑pernyataan; seharusnya memakai `if‑else`.
- Lupa menutup tanda kurung `(` pada kondisi, sehingga terjadi error sintaks.
- Menghasilkan tipe data yang tidak konsisten antara `expr1` dan `expr2` (mis. `int` vs `char*`).

# ✅ CHECKLIST KEBERHASILAN HARI 3
- [ ] Program menghasilkan output yang benar menggunakan ternary.
- [ ] Nested ternary memberikan hasil yang sesuai dengan harapan.
- [ ] Tidak ada error kompilasi terkait tipe data atau kurung.

# 🔮 PREVIEW HARI 4
Membahas **HOTS**: Analisis dan optimasi keputusan dalam algoritma, serta membuat soal evaluatif yang menuntut siswa **mengevaluasi** pilihan kontrol.
