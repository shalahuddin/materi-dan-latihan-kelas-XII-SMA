# Hari 5: Review, Quiz 3, & Praktikum Mandiri
## Smart Calculator — Semua Operator Bekerja Sama

---

## 🎯 TUJUAN PEMBELAJARAN
Setelah pembelajaran hari ini, kamu diharapkan dapat:
1. Mengulang semua operator Minggu 03: aritmatika, modulo, relasional, logika, assignment gabungan, casting.
2. Menyelesaikan **Quiz 3** dengan jujur dan tepat waktu.
3. Menyelesaikan praktikum **"Smart Calculator"** di environment lokal.
4. Mengumpulkan bukti `git log` beserta source code yang ber-header lengkap.
5. Memahami bayangan materi Minggu 04 (`if`, `else`, `switch`).

---

## 💡 REVIEW KILAT MINGGU 03

### 1. Operator Aritmatika & Modulo
```c
int a = 10, b = 3;
printf("%d\n", a + b);   // 13
printf("%d\n", a - b);   // 7
printf("%d\n", a * b);   // 30
printf("%d\n", a / b);   // 3   (integer division!)
printf("%d\n", a % b);   // 1   (sisa bagi)
```
* `int / int` = int, desimal dibuang
* `%` = sisa bagi (genap/ganjil, kelipatan, sisa uang)
* Precedence: `()` → `* / %` → `+ -`

### 2. Operator Relasional
* `== != < > <= >=` → hasil **`0` (false) atau `1` (true)**
* `=` assignment, `==` perbandingan — jangan tertukar!
* Hati-hati membandingkan float dengan `==`

### 3. Operator Assignment Gabungan
```c
int skor = 100;
skor += 50;   // 150
skor *= 2;    // 300
skor %= 100;  // 0
```

### 4. Operator Logika
* `&&` AND (semua harus 1), `||` OR (cukup satu 1), `!` NOT (membalik)
* Non-zero = true, nol = false
* **Short-circuit**: `0 && (…)` dan `1 || (…)` tidak mengevaluasi bagian kanan

### 5. Casting
```c
printf("%.2f\n", (float)7 / 2);    // 3.50 (cast sebelum bagi)
printf("%d\n", (int)3.9);          // 3 (memotong, bukan membulatkan)
```
* Casting tidak mengubah variabel asli
* Konversi implisit: `int` otomatis jadi `float` saat bertemu `float`

---

## 📝 QUIZ 3 — PREVIEW

* **Durasi**: 20 menit
* **Jumlah**: 9 soal singkat + 1 soal koding mini
* **Sifat**: Individu, closed-notebook (kecuali instruktur bilang lain)

### Kisi-kisi
1. Hasil ekspresi aritmatika (integer division)
2. Hasil operator modulo `%`
3. Prioritas operasi (precedence)
4. Hasil perbandingan relasional (`0`/`1`)
5. Membedakan `=` vs `==`
6. Hasil ekspresi logika `&& || !`
7. Short-circuit evaluation
8. Hasil casting `(float)7/2` vs `(float)(7/2)`
9. Assignment gabungan `+= *=`
10. **Koding mini**: program 8–12 baris memakai minimal **3 jenis operator** (misal aritmatika + relasional + casting) dan menampilkan hasilnya

> 🧠 **Soal HOTS** = soal yang menuntut **menganalisis, mengevaluasi, dan menciptakan** — bukan sekadar hafalan. Quiz 3 memuat beberapa soal model HOTS: menelusuri eksekusi, membandingkan pendekatan, dan menulis program. Kumpulan lengkap: **`Soal_HOTS_Minggu03_Operator.md`**

### Contoh Soal Latihan (bukan soal asli)

**Soal LOTS — pemahaman**
**Soal A**  
Berapa hasil dari `17 % 5`?  
a) 2   b) 3   c) 3.4   d) 12

**Soal B**  
Apa output `printf("%d\n", 5 == 5);`?  
a) `5`   b) `1`   c) `0`   d) `true`

**Soal C**  
Agar `7 / 2` menghasilkan `3.5`, tulis…  
a) `7 / 2`   b) `(int)7 / 2`   c) `(float)7 / 2`   d) `7.0 / 2` (pilih yang benar — bisa lebih dari satu)

**Soal D**  
`int x = 5; x += 3; x *= 2;` → nilai akhir `x`?  
a) 11   b) 13   c) 16   d) 10

**Soal HOTS — menganalisis & mengevaluasi**
**Soal E (Analisis C4)**  
```c
int x = 5, y = 0, hitung = 0;
int r1 = (x > 3) && (y = x);   // apa yang terjadi pada y?
int r2 = (y != 0) || (hitung++); // apakah hitung bertambah?
printf("%d %d %d\n", r1, r2, hitung);
```
a) `1 1 0`   b) `1 1 1`   c) `0 1 0`   d) `1 0 1`  
*(Jawaban: a — `(x>3)` benar sehingga `y` menjadi 5; karena `y!=0` benar, `hitung++` dilewati short-circuit)*

**Soal F (Evaluasi C5)**  
Rumus `(tahun % 4 == 0)` saja dipakai untuk mengecek tahun kabisat. Tahun **manakah** yang membuat rumus ini SALAH?  
a) 2000   b) 2024   c) 1900   d) 1996  
*(Jawaban: c — 1900 habis dibagi 4 tapi bukan kabisat, karena habis dibagi 100 tanpa habis dibagi 400)*

**Soal G (Mencipta C6 — koding mini)**  
Buat program yang menerima detik (mis. `3661`) dan menampilkan `1 jam 1 menit 1 detik`, memakai `/` dan `%` serta minimal satu operator relasional atau logika.

---

## 🛠️ PRAKTIKUM MINGGUAN: "SMART CALCULATOR"

Baca spesifikasi lengkap di:  
**`Praktikum_Minggu_03_Smart_Calculator.md`**

### Ringkasan 3 Program
1. **`smart_calc.c`**  
   Kalkulator aritmatika lengkap: operasi dasar, hasil bagi bulat, sisa bagi, rata-rata — memakai variabel + operator.
2. **`decision_maker.c`**  
   Program pengambilan keputusan dengan relasional + logika (syarat ikut lomba / cek kelulusan / diskon).
3. **`unit_converter.c`**  
   Konverter satuan (suhu / jarak / uang) memakai operator, casting, dan assignment gabungan.

### Bukti tambahan
* Project di folder Git
* Minimal **2 commit** bermakna
* Salin output `git log --oneline` ke README atau file `GIT_LOG.txt`

### Syarat teknis
* Diutamakan compile di **lokal** (GCC + VS Code)
* OnlineGDB hanya jika ada kendala hardware (lampirkan catatan alasan)
* Semua file lolos compile tanpa error

---

## 📤 PANDUAN PENGUMPULAN
1. Pastikan ketiga `.c` + README (+ `GIT_LOG.txt`) rapi di folder `minggu03`
2. Commit terakhir sebelum submit
3. Kumpulkan sesuai instruksi guru:
   * ZIP folder project, **atau**
   * Link share (jika diminta) + screenshot `git log` + bukti compile lokal
4. Nama arsip (contoh): `BudiSantoso_Minggu03_SmartCalculator.zip`

---

## 🔮 SNEAK PEEK MINGGU 04: DECISION MAKING

Minggu depan programmu tidak hanya **menghitung** — tapi **memilih**:
```c
int nilai = 85;

if (nilai >= 75) {
    printf("LULUS! 🎉\n");
} else {
    printf("Remedial... 💪\n");
}
```
* `if`, `else if`, `else` — program berjalan di satu dari beberapa jalur
* `switch` — banyak pilihan sekaligus
* Semua operator Minggu 03 menjadi **syarat** di dalam `if`

---

## ✅ CHECKLIST SEBELUM PULANG
- [ ] Quiz dikumpulkan
- [ ] 3 program praktikum compile sukses
- [ ] Header + atribusi lengkap
- [ ] `git log` menunjukkan ≥ 2 commit
- [ ] File sudah di-submit sesuai format

---

**Variabel menyimpan data, operator mengolahnya, dan kamu mengendalikannya. 🧮**
