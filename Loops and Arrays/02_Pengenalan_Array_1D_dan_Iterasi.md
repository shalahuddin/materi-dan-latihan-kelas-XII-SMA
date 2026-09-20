# Modul 2: Pengenalan Array Satu Dimensi

## 1. Pendahuluan
Sebelumnya, jika kita ingin menyimpan 5 nilai ujian siswa, kita harus membuat 5 variabel berbeda:
```c
int nilai1 = 80;
int nilai2 = 75;
int nilai3 = 90;
int nilai4 = 85;
int nilai5 = 95;
```
Cara ini tidak praktis jika data yang harus disimpan berjumlah puluhan atau ratusan. Untuk mengelola kumpulan data dengan tipe yang sama, bahasa C menyediakan struktur data bernama **Array**.

**Array** adalah variabel yang dapat menyimpan sekumpulan nilai dengan tipe data yang sama di dalam satu deret memori yang berurutan.

---

## 2. Deklarasi dan Inisialisasi Array

### A. Deklarasi (Membuat Ruang Simpan)
Untuk membuat array, tentukan tipe data, nama array, dan jumlah elemen di dalam tanda kurung siku `[]`.

```c
int nilai[5]; // Menyiapkan wadah untuk 5 bilangan bulat
```

### B. Inisialisasi (Memberikan Nilai Awal)
Kita bisa langsung mengisi nilai saat membuat array:

```c
int nilai[5] = {80, 75, 90, 85, 95};
```

Jika ukurannya tidak ditulis, compiler akan menghitung otomatis jumlah datanya:
```c
int nilai[] = {80, 75, 90, 85, 95}; // Otomatis berukuran 5
```

---

## 3. Sistem Indeks Array (Dimulai dari 0)
Elemen array diakses menggunakan nomor urut yang disebut **indeks**. Dalam bahasa C, indeks selalu dimulai dari **0**, bukan 1.

Jika kita punya `int nilai[5] = {80, 75, 90, 85, 95};`:

| Indeks | Nilai | Cara Akses |
|:------:|:-----:|:-----------|
| 0 | 80 | `nilai[0]` |
| 1 | 75 | `nilai[1]` |
| 2 | 90 | `nilai[2]` |
| 3 | 85 | `nilai[3]` |
| 4 | 95 | `nilai[4]` |

> **Catatan Penting**: Untuk array berukuran $N$, indeks yang sah adalah dari $0$ sampai $N - 1$. Indeks $N$ tidak boleh diakses karena berada di luar memori yang dipesan.

---

## 4. Membaca dan Menampilkan Array dengan Perulangan
Karena indeks array berupa angka berurutan (0, 1, 2, ...), kita dapat menggunakan perulangan `for` untuk memproses seluruh isi array dengan mudah.

### Contoh Program: Input dan Output Data Array
```c
#include <stdio.h>

int main() {
    int skor[5];

    // 1. Mengisi data ke dalam array
    printf("--- Input Nilai 5 Siswa ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Masukkan nilai siswa ke-%d: ", i + 1);
        scanf("%d", &skor[i]); // Perhatikan: pakai &skor[i]
    }

    // 2. Menampilkan kembali data array
    printf("\n--- Daftar Nilai Siswa ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Siswa %d: %d\n", i + 1, skor[i]);
    }

    return 0;
}
```

---

## 5. Menghitung Jumlah dan Rata-rata Elemen Array
Salah satu penggunaan umum array adalah menjumlahkan seluruh elemennya menggunakan variabel penampung (*akumulator*).

```c
#include <stdio.h>

int main() {
    int data[4] = {10, 20, 30, 40};
    int total = 0; // Wajib diberi nilai awal 0

    for (int i = 0; i < 4; i++) {
        total += data[i]; // total = total + data[i]
    }

    float rata_rata = (float)total / 4;

    printf("Total nilai: %d\n", total);
    printf("Rata-rata: %.2f\n", rata_rata);

    return 0;
}
```

---

## 6. Kesalahan yang Sering Terjadi

1. **Mengakses Indeks di Luar Batas (Array Index Out of Bounds)**
   ```c
   int angka[5] = {1, 2, 3, 4, 5};
   printf("%d\n", angka[5]); // Salah: indeks maksimal adalah 4
   ```
   Bahasa C tidak memberi peringatan error saat kompilasi jika indeks melebihi batas, tetapi program bisa menghasilkan angka acak (*garbage value*) atau mendadak berhenti (*crash*).

2. **Lupa Memberi Nilai Awal pada Akumulator**
   ```c
   int total; // Belum bernilai 0, berisi data acak memori
   for (int i = 0; i < 5; i++) {
       total += nilai[i]; // Hasil penjumlahan akan salah
   }
   ```

3. **Lupa Tanda `&` pada `scanf` Array**
   ```c
   scanf("%d", nilai[i]);  // Salah: menyebabkan program crash
   scanf("%d", &nilai[i]); // Benar: memberikan alamat elemen ke-i
   ```

---

## 7. Latihan Mandiri
1. Buat program yang meminta pengguna memasukkan 6 angka, kemudian tampilkan angka-angka tersebut dalam urutan terbalik (dari indeks terakhir ke indeks pertama).
2. Buat program yang menyimpan harga 5 barang belanjaan, lalu hitung total belanjaan dan rata-rata harga barang.
