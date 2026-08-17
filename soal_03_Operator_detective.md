# Latihan Harian: Operator Detective (OnlineGDB Friendly)
## Minggu 03 — Hari 2/4 (Penguatan Konsep Operator C)

* **Bentuk**: Game analisis detektif kode & penelusuran ekspresi
* **Durasi**: 40–60 menit
* **Tujuan**: Melatih ketelitian siswa terhadap operator — *integer division*, *modulo*, *precedence*, `=` vs `==`, *casting*, dan *short-circuit evaluation*.

---

## 💡 CARA SISWA MENGERJAKAN DI ONLINEGDB:
1. Buka situs [OnlineGDB](https://www.onlinegdb.com/).
2. Pada pojok kanan atas, ubah pilihan bahasa (**Language**) menjadi **C (GCC)**.
3. Salin (*copy*) seluruh kode program di setiap kasus di bawah ini ke editor OnlineGDB.
4. Klik tombol **Run** (atau tekan **F9** pada keyboard).
5. Amati output yang dihasilkan, bandingkan dengan perkiraan/ekspektasimu, lalu jawab pertanyaan analisisnya!

---

## 🕵️ KASUS 1 — Integer Division Trap
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 1: Integer Division Trap
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int a = 7;
    int b = 2;
    printf("7 / 2 = %.1f\n", a / b);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Apakah program ini menghasilkan peringatan (*warning*) saat di-compile di OnlineGDB? Mengapa? (Petunjuk: bandingkan tipe data hasil pembagian dengan spesifikasi format `%.1f`).
2. Apa output aktual yang tercetak di terminal OnlineGDB? Mengapa hasilnya tidak `3.5`?
3. Bagaimana kode perbaikan yang tepat agar program mencetak `7 / 2 = 3.5`?

---

## 🕵️ KASUS 2 — Rata-Rata yang Hilang
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 2: Rata-Rata yang Hilang
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int u1 = 85, u2 = 92, u3 = 78;
    int rata = (u1 + u2 + u3) / 3;
    printf("Rata-rata = %d\n", rata);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Apa output aktual dari program di atas?
2. Secara matematis, rata-rata sebenarnya adalah `85.00`. Mengapa program hanya menampilkan angka `85` tanpa pecahan desimal?
3. Jika variabel `rata` diubah tipe datanya menjadi `float rata = (float)(u1 + u2 + u3) / 3;` dan format `%d` diganti `%f`, apakah hasilnya menjadi benar? Apa perbedaan jika casting `(float)` diletakkan **setelah** pembagian dilakukan, contoh: `(float)((u1 + u2 + u3) / 3)`?

---

## 🕵️ KASUS 3 — Misteri Sisa Bagi Negatif
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 3: Sisa Bagi Negatif
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    printf("Hasil -7 %% 3  = %d\n", -7 % 3);
    printf("Hasil  7 %% -3  = %d\n", 7 % -3);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Tuliskan output dari kedua operasi modulo di atas!
2. Analisislah aturan dalam bahasa C terkait penentuan tanda positif/negatif (`+` atau `-`) dari hasil operasi modulo (`%`). Mengapa tanda hasilnya bisa berbeda?

---

## 🕵️ KASUS 4 — Jebakan Assignment Tertukar
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 4: Jebakan Assignment Tertukar
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int x = 5;
    int cek = (x = 7);   // Siswa bermaksud membandingkan apakah x sama dengan 7
    printf("cek = %d, x = %d\n", cek, x);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Apa output aktual dari variabel `cek` dan `x` setelah program dijalankan?
2. Mengapa variabel `x` yang semula bernilai `5` bisa berubah menjadi `7` di akhir? Operator apa yang salah digunakan pada ekspresi `(x = 7)`?
3. Bagaimana cara memperbaiki kode tersebut agar benar-benar membandingkan apakah `x` sama dengan `7`?

---

## 🕵️ KASUS 5 — Precedence Drama
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 5: Precedence Drama
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    printf("Hasil Ekspresi 1 = %d\n", 2 + 3 * 4 - 6 / 2);
    printf("Hasil Ekspresi 2 = %d\n", (2 + 3) * (4 - 6 / 2));
    return 0;
}
```

**Pertanyaan Detektif:**
1. Berapa output dari Ekspresi 1 dan Ekspresi 2?
2. Jabarkan langkah-langkah urutan pengerjaan operator pada Ekspresi 1 dan Ekspresi 2 berdasarkan aturan **prioritas operator (precedence)**!

---

## 🕵️ KASUS 6 — Short-Circuit Tersembunyi
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 6: Short-Circuit Tersembunyi
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int count = 0;
    int a = 0, b = 1;

    int r1 = (a && count++);
    int r2 = (b || count++);

    printf("r1 = %d, r2 = %d, count = %d\n", r1, r2, count);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Tuliskan output lengkap program tersebut!
2. Mengapa nilai `count` tetap bernilai **0** di akhir program, padahal ekspresi increment `count++` tertulis sebanyak dua kali?
3. Jelaskan konsep **Short-Circuit Evaluation** pada operator logika `&&` dan `||` berdasarkan kasus di atas!

---

## 🕵️ KASUS 7 — Casting yang Salah Tempat
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 7: Casting yang Salah Tempat
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int a = 9, b = 5;
    printf("Metode A (9/5) = %.2f\n", (float)(a / b));
    printf("Metode B (9/5) = %.2f\n", (float)a / b);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Tuliskan output dari Metode A dan Metode B!
2. Mengapa Metode A menghasilkan `1.00`, sedangkan Metode B menghasilkan `1.80`? 
3. Analisislah urutan proses casting dan pembagian yang terjadi pada masing-masing metode tersebut!

---

## 🕵️ KASUS 8 — Bonus Campuran (Prediksi & Logika Kasir)
Salin kode berikut ke OnlineGDB dan jalankan.

```c
/*
 * Kasus 8: Bonus Campuran
 * Jalankan kode ini di OnlineGDB dan amati hasilnya!
 */
#include <stdio.h>

int main() {
    int uang = 15000;
    int harga = 7000;
    int jumlah = uang / harga;
    int sisa = uang % harga;
    printf("Beli %d item, sisa %d\n", jumlah, sisa);

    // Bagian Prediksi Skor
    int skor = 0;
    skor += 200;
    skor = skor - 100;
    skor *= 2;
    printf("Skor Akhir = %d\n", skor);
    return 0;
}
```

**Pertanyaan Detektif:**
1. Berapa nilai `jumlah` dan `sisa` uang belanjaan? Apakah rumusnya sudah tepat?
2. Berapa nilai `skor` akhir? Jelaskan jalannya perubahan nilai `skor` baris demi baris!
3. Bandingkan gaya penulisan operator penugasan gabungan `skor += 200` dengan operator biasa `skor = skor - 100`. Apakah keduanya memiliki fungsi yang setara? Mana yang lebih ringkas?

---

## 📑 LEMBAR JAWABAN DETEKTIF (Salin dan isi untuk pengumpulan)

| Kasus | Compile Sukses? (Ya/Tidak) | Output yang Muncul | Bug yang Ditemukan | Ide Solusi / Perbaikan Kode |
| :--- | :---: | :--- | :--- | :--- |
| **Kasus 1** | | | | |
| **Kasus 2** | | | | |
| **Kasus 3** | | | | |
| **Kasus 4** | | | | |
| **Kasus 5** | | | | |
| **Kasus 6** | | | | |
| **Kasus 7** | | | | |
| **Kasus 8** | | | | |

---

