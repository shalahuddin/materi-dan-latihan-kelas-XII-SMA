# Hari 2: Parameter, Argumen, dan Call by Value
## Salinan Nilai yang Terisolasi dan Kontrak Prototipe Fungsi

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Membedakan secara presisi antara **Parameter Formal** (pada deklarasi/definisi fungsi) dan **Argumen Aktual** (saat pemanggilan).
2. Memahami mekanisme dasar pengiriman data di C: **Call by Value** (Passing by Value).
3. Membuktikan melalui visualisasi memori bahwa modifikasi parameter di dalam fungsi tidak memengaruhi nilai variabel asli pada fungsi pemanggil.
4. Mendeklarasikan dan menggunakan **Prototipe Fungsi (Function Prototype / Forward Declaration)** untuk menghindari error urutan kompilasi.
5. Menerapkan konvensi penulisan kode standar industri: *Prototipe di atas $\rightarrow$ `main()` di tengah $\rightarrow$ Definisi fungsi di bawah*.

---

## 💡 MATERI PEMBELAJARAN

### 1. Parameter Formal vs Argumen Aktual
Dua istilah ini sering tertukar di kalangan pemrogram pemula. Mari kita bedah perbedaannya:

```c
// x dan y di sini adalah PARAMETER FORMAL (Wadah / Penampung nilai)
int hitung_kali(int x, int y) {
    return x * y;
}

int main() {
    int angka_a = 7;
    int angka_b = 3;

    // angka_a dan angka_b di sini adalah ARGUMEN AKTUAL (Nilai nyata yang dikirim)
    int hasil = hitung_kali(angka_a, angka_b);
    
    // Atau bisa berupa konstanta langsung:
    int hasil2 = hitung_kali(10, 5); // 10 dan 5 adalah argumen aktual
    return 0;
}
```

| Aspek | Parameter Formal | Argumen Aktual |
|---|---|---|
| **Definisi** | Variabel yang dideklarasikan pada *header* fungsi sebagai penampung input. | Nilai nyata atau variabel yang dikirimkan saat fungsi dipanggil. |
| **Lokasi** | Di dalam tanda kurung saat membuat fungsi. | Di dalam tanda kurung saat memanggil fungsi dari `main()`. |
| **Contoh** | `int x` dalam `int kuadrat(int x)` | `nilai_kuis` dalam `kuadrat(nilai_kuis)` atau angka `5` dalam `kuadrat(5)` |
| **Analogi** | Slot koin pada mesin minuman (tempat koin masuk). | Uang koin Rp1.000 asli yang kamu masukkan ke dalam slot. |

---

### 2. ⭐ Mekanisme Call by Value: Rahasia Isolasi Memori di C

Bahasa C secara *default* menggunakan mekanisme **Call by Value** saat melewatkan argumen ke dalam fungsi.

> ⭐ **Prinsip Emas Call by Value:**  
> Ketika sebuah variabel dilewatkan sebagai argumen ke sebuah fungsi, C **TIDAK** memberikan variabel aslinya. Kompilator membuat **SALINAN BARU (FOTOKOPI)** dari nilai tersebut di slot memori terpisah milik fungsi tersebut.  
> Apapun perubahan yang kamu lakukan pada salinan itu, **kertas asli milik pemanggil tidak akan pernah terpengaruh**.

#### Eksperimen Klasik: "Jebakan Fungsi Tukar Nilai (Swap Trap)"
Perhatikan kode berikut yang ditulis seorang siswa yang mencoba menukar dua angka:

```c
#include <stdio.h>

void tukar_gagal(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("[Di dalam fungsi] a = %d, b = %d\n", a, b); // Terlihat tertukar!
}

int main() {
    int x = 10;
    int y = 99;

    printf("[Sebelum panggil] x = %d, y = %d\n", x, y);
    tukar_gagal(x, y);
    printf("[Sesudah panggil] x = %d, y = %d\n", x, y); // Apakah tertukar?!
    return 0;
}
```

**Output Program:**
```text
[Sebelum panggil] x = 10, y = 99
[Di dalam fungsi] a = 99, b = 10
[Sesudah panggil] x = 10, y = 99
```

**Mengapa Nilai `x` dan `y` Tidak Tertukar?**
1. Saat `tukar_gagal(x, y)` dipanggil, memori sistem membuat variabel baru bernama `a` dan `b`.
2. Nilai `x` (10) disalin ke `a`. Nilai `y` (99) disalin ke `b`.
3. Variabel `a` dan `b` berhasil ditukar di dalam stack frame fungsi `tukar_gagal`.
4. Begitu fungsi selesai, seluruh variabel `a` dan `b` **dihapus dari memori**!
5. Variabel `x` dan `y` di `main()` tetap tenang di alamat memorinya sendiri tanpa tersentuh sedikit pun.

*(Catatan: Untuk benar-benar mengubah variabel luar, di Semester Genap kita akan menggunakan Pointer / Call by Reference).*

---

### 3. ⭐ Prototipe Fungsi (Function Prototype / Forward Declaration)

Pernahkah kamu memindahkan fungsi buatanmu ke baris paling bawah (di bawah `main()`), lalu saat dikompilasi muncul peringatan (*warning*) atau error seperti ini?
```text
warning: implicit declaration of function 'hitung_pajak' [-Wimplicit-function-declaration]
```

#### Mengapa Kompilator C Bingung?
Kompilator C bekerja secara **single-pass top-down** (membaca teks kodemu dari baris 1 mengalir ke bawah). Jika saat membaca `main()` ia menemukan pemanggilan `hitung_pajak()`, padahal fungsi tersebut baru ditulis di baris 50, kompilator akan panik karena belum tahu:
- Berapa jumlah parameter yang seharusnya?
- Tipe data apa yang dikembalikan?

#### Solusi: Prototipe Fungsi (Forward Declaration)
Prototipe fungsi adalah pernyataan satu baris di bagian atas program yang bertindak sebagai **"Kontrak / Janji"** kepada kompilator: *"Hai kompilator, tenang saja! Nanti di bawah ada fungsi bernama X dengan tipe data Y. Tolong catat dulu formatnya."*

**Format Prototipe Fungsi:**
```c
return_type nama_fungsi(tipe_parameter1, tipe_parameter2);
```
*(Perhatikan tanda titik koma `;` wajib ada di akhir prototipe!)*

Contoh:
```c
// PROTOTIPE FUNGSI (Deklarasi di atas main)
int hitung_pajak(int penghasilan, float tarif);
void sapa_pengguna(char inisial);
```

---

### 4. Struktur Kode Standar Industri (Best Practice)
Dalam proyek rekayasa perangkat lunak profesional, fungsi `main()` selalu diletakkan di bagian atas agar pembaca kode dapat langsung memahami alur utama sistem tanpa harus menggulir melewati ratusan baris fungsi bantuan.

Susunan standar program C:
```
1. Header Library   (#include <stdio.h>, dsb.)
2. Prototipe Fungsi (Daftar isi seluruh fungsi)
3. Fungsi main()    (Alur cerita utama program)
4. Definisi Fungsi  (Implementasi rincian fungsi satu per satu)
```

---

## 💻 LIVE CODING DEMO

Simak dan ketiklah kode lengkap berikut untuk memahami sinergi antara prototipe fungsi dan pembuktian Call by Value.

```c
/*
 * File: 02_function_return_calc.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi prototipe fungsi dan simulasi Call by Value
 *
 * Compile:
 *   gcc 02_function_return_calc.c -o return_calc_demo
 *   .\return_calc_demo.exe
 */

#include <stdio.h>

// ==========================================================
// 1. PROTOTIPE FUNGSI (Kontrak Deklarasi di Atas)
// ==========================================================
int hitung_total_belanja(int harga_satuan, int jumlah_barang);
int terapkan_pajak(int total_kotor, int persen_pajak);
void coba_ubah_saldo(int saldo_asli);

// ==========================================================
// 2. FUNGSI UTAMA (MAIN)
// ==========================================================
int main() {
    printf("=== SISTEM KASIR LABS (CALL BY VALUE & PROTOTIPE) ===\n\n");

    int harga = 15000;
    int qty = 4;
    
    // Memanggil fungsi ber-prototipe
    int total_kotor = hitung_total_belanja(harga, qty);
    int total_akhir = terapkan_pajak(total_kotor, 11); // Pajak PPN 11%

    printf("Harga Satuan : Rp%d\n", harga);
    printf("Jumlah Item  : %d pcs\n", qty);
    printf("Total Kotor  : Rp%d\n", total_kotor);
    printf("Total Akhir  : Rp%d (Termasuk PPN 11%%)\n\n", total_akhir);

    // Pembuktian Call by Value
    int dompet_siswa = 100000;
    printf("[Sebelum fungsi] Saldo dompet siswa : Rp%d\n", dompet_siswa);
    
    coba_ubah_saldo(dompet_siswa);
    
    printf("[Sesudah fungsi] Saldo dompet siswa : Rp%d\n", dompet_siswa);
    printf("Kesimpulan: Variabel 'dompet_siswa' kebal dari manipulasi fungsi!\n");

    return 0;
}

// ==========================================================
// 3. DEFINISI / IMPLEMENTASI FUNGSI DI BAWAH MAIN
// ==========================================================

// Menghitung total perkalian harga dan kuantitas
int hitung_total_belanja(int harga_satuan, int jumlah_barang) {
    return harga_satuan * jumlah_barang;
}

// Menghitung total setelah ditambah persentase pajak
int terapkan_pajak(int total_kotor, int persen_pajak) {
    int nominal_pajak = total_kotor * persen_pajak / 100;
    return total_kotor + nominal_pajak;
}

// Fungsi eksperimen pengubah nilai
void coba_ubah_saldo(int saldo_asli) {
    printf("  -> [Di dalam fungsi] Menerima salinan saldo: Rp%d\n", saldo_asli);
    saldo_asli = saldo_asli - 50000; // Dikurangi 50 ribu
    printf("  -> [Di dalam fungsi] Saldo salinan dipotong menjadi: Rp%d\n", saldo_asli);
}
```

---

## 🛠️ GUIDED PRACTICE

### Latihan 1: Tracing Memori Call by Value (25 menit)
Prediksikan keluaran (*output*) program berikut di selembar kertas tanpa menjalankannya dulu, lalu verifikasi dengan GCC:
```c
#include <stdio.h>

void misteri(int a, int b) {
    a = a * 2;
    b = b + 10;
    printf("Fungsi: a = %d, b = %d\n", a, b);
}

int main() {
    int x = 5;
    int y = 20;
    misteri(x, y);
    printf("Main  : x = %d, y = %d\n", x, y);
    return 0;
}
```

### Latihan 2: Refactoring Struktur Prototipe (30 menit)
Ambillah program yang kamu buat pada Hari 1 (program penghitung suhu/diskon). Ubah strukturnya menjadi standar industri:
1. Pindahkan seluruh implementasi fungsi ke bawah fungsi `main()`.
2. Tuliskan prototipe fungsi lengkap di atas `main()`.
3. Kompilasi dengan perintah GCC dan pastikan tidak ada peringatan `-Wimplicit-function-declaration`.

### Latihan 3: Kalkulator Pangkat Rekursif-Lookahead (35 menit)
Buatlah fungsi ber-return value: `int pangkat_tiga(int n)` dan `int pangkat_empat(int n)`.
- Syarat: Fungsi `pangkat_empat` harus memanfaatkan hasil dari pemanggilan fungsi `pangkat_tiga(n) * n`!
- Susun prototipenya dengan rapi di bagian atas program.
- Uji dengan nilai masukan $n = 3$ (hasil pangkat 3 = 27, pangkat 4 = 81).

### Latihan 4: Simulasi Level Game (40 menit)
Buat program game mini di mana pemain memiliki level dan XP:
- Prototipe: `int tambah_xp(int xp_sekarang, int xp_tambahan);`
- Prototipe: `int cek_level(int total_xp);` (Aturan: Level = total_xp / 1000).
- Di dalam `main()`, tunjukkan cara yang benar untuk memperbarui variabel `xp_pemain` menggunakan nilai kembalian fungsi:
  ```c
  // Bukan berharap fungsi mengubah variabel luar secara ajaib, tapi:
  xp_pemain = tambah_xp(xp_pemain, 350);
  ```

---

## ⚠️ KESALAHAN UMUM PEMULA

| Kasus Kesalahan | Contoh Kode Salah | Penjelasan & Perbaikan |
|---|---|---|
| **Lupa Titik Koma pada Prototipe** | `int hitung(int a, int b)` *(lupa `;`)* | Prototipe adalah pernyataan deklarasi, wajib ditutup titik koma: `int hitung(int a, int b);`. |
| **Beda Tipe di Prototipe vs Definisi** | Prototipe: `int luas(int a);`<br>Definisi: `float luas(int a) { ... }` | Kompilator akan menolak dengan error *conflicting types for 'luas'*. Tipe kembalian dan parameter harus persis sama! |
| **Mengharapkan Parameter Berubah Permanen** | `void potong(int s) { s = s - 10; }`<br>Di main: `potong(saldo);` | Karena Call by Value, nilai `saldo` di `main` tidak akan berkurang. Gunakan return value: `saldo = potong(saldo);`. |
| **Nama Variabel Tertukar Parameter** | Di main: `x = 5;`<br>Di fungsi: `printf("%d", x);` *(padahal parameter bernama `n`)* | Fungsi hanya mengenali nama parameternya sendiri (`n`), tidak tahu nama variabel `x` milik `main()`. |

---

## ✅ CHECKLIST KEBERHASILAN HARI 2
- [ ] Bisa membedakan mana parameter formal dan mana argumen aktual dengan percaya diri.
- [ ] Paham mengapa C disebut menggunakan *Call by Value* dan apa konsekuensinya pada variabel asli.
- [ ] Mampu menuliskan prototipe fungsi lengkap dengan titik koma di atas `main()`.
- [ ] Berhasil mengompilasi program dengan arsitektur: Prototipe $\rightarrow$ `main()` $\rightarrow$ Definisi fungsi.
- [ ] Mengetahui cara memperbarui variabel di `main()` secara legal menggunakan nilai balik `return`.

---

## 🔮 PREVIEW HARI 3
Di manakah variabel dilahirkan, hidup, dan menemui ajalnya? Besok kita akan menyelami **Scope (Lingkup Variabel)** dan **Lifetime**! Kita akan membongkar perbedaan variabel lokal vs variabel global, serta bahaya mengerikan dari fenomena *variable shadowing* yang sering membuat pemrogram begadang semalaman!

---

**"Memahami Call by Value adalah pintu gerbang menjadi programmer sejati. Kamu tidak lagi sekadar mengetik kode, tapi melihat aliran salinan data di dalam memori komputer." 🧠**
