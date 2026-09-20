# Modul 3: Integrasi Perulangan dan Array (Pencarian & Nilai Ekstrem)

## 1. Pendahuluan
Setelah memahami cara menyimpan data ke dalam array dan menampilkannya, kita dapat memproses data tersebut untuk kebutuhan nyata, seperti mencari apakah suatu data ada di dalam daftar, mencari nilai tertinggi dan terendah, serta menyaring data tertentu.

---

## 2. Mencari Nilai Maksimum dan Minimum

Untuk mencari nilai tertinggi (*maksimum*) atau terendah (*minimum*) dari sekumpulan data:
1. Anggap elemen pertama (`data[0]`) sebagai nilai acuan awal (*sementara*).
2. Periksa elemen-elemen berikutnya satu per satu menggunakan perulangan.
3. Jika ditemukan nilai yang lebih besar (untuk nilai maksimum) atau lebih kecil (untuk nilai minimum), perbarui nilai acuan tersebut.

### Contoh Program: Mencari Nilai Tertinggi dan Terendah
```c
#include <stdio.h>

int main() {
    int nilai[5] = {78, 92, 65, 88, 70};

    int maks = nilai[0]; // Nilai awal mengacu pada elemen pertama
    int min = nilai[0];

    for (int i = 1; i < 5; i++) {
        if (nilai[i] > maks) {
            maks = nilai[i]; // Ganti jika ada yang lebih besar
        }
        if (nilai[i] < min) {
            min = nilai[i];  // Ganti jika ada yang lebih kecil
        }
    }

    printf("Nilai Tertinggi: %d\n", maks);
    printf("Nilai Terendah : %d\n", min);

    return 0;
}
```

---

## 3. Pencarian Data (Linear Search)

**Linear Search** adalah metode pencarian data yang paling sederhana. Konsepnya adalah memeriksa elemen array satu per satu dari awal sampai akhir hingga data yang dicari ditemukan.

Kita menggunakan variabel penanda (*flag*) untuk mencatat apakah data sudah berhasil ditemukan atau belum.

### Contoh Program: Pencarian Nomor Absen
```c
#include <stdio.h>

int main() {
    int daftar_absen[6] = {12, 5, 23, 17, 8, 30};
    int target;
    int ditemukan = 0; // 0 = belum ketemu, 1 = sudah ketemu
    int posisi = -1;

    printf("Masukkan nomor absen yang dicari: ");
    scanf("%d", &target);

    for (int i = 0; i < 6; i++) {
        if (daftar_absen[i] == target) {
            ditemukan = 1;
            posisi = i;
            break; // Berhenti mencari karena data sudah ditemukan
        }
    }

    if (ditemukan == 1) {
        printf("Nomor absen %d ditemukan pada urutan data ke-%d (indeks %d).\n", target, posisi + 1, posisi);
    } else {
        printf("Nomor absen %d tidak ditemukan di dalam daftar.\n", target);
    }

    return 0;
}
```

---

## 4. Menghitung Jumlah Kemunculan Data (Counting)

Terkadang kita perlu mengetahui berapa kali suatu angka muncul di dalam array.

```c
#include <stdio.h>

int main() {
    int hasil_lempar_dadu[10] = {6, 2, 6, 4, 6, 1, 3, 6, 5, 2};
    int cari = 6;
    int jumlah = 0;

    for (int i = 0; i < 10; i++) {
        if (hasil_lempar_dadu[i] == cari) {
            jumlah++;
        }
    }

    printf("Angka %d muncul sebanyak %d kali.\n", cari, jumlah);

    return 0;
}
```

---

## 5. Kesalahan yang Sering Terjadi

1. **Mengisi Nilai Awal Min/Maks dengan Angka Sembarangan**
   - Mengisi `int min = 0;` saat data bernilai positif semua akan menyebabkan nilai minimum selalu 0, padahal 0 bukan bagian dari data.
   - Cara paling aman adalah mengambil elemen pertama array: `int min = data[0];`.

2. **Lupa Memberikan Perintah `break` Saat Pencarian**
   - Tanpa `break`, perulangan akan tetap mengecek sisa elemen walaupun data sudah ditemukan, sehingga program bekerja lebih lambat dari yang seharusnya.

---

## 6. Latihan Mandiri
1. Buat program yang menyimpan nilai ujian 8 siswa. Tampilkan siswa mana saja yang nilainya di bawah nilai rata-rata kelas.
2. Buat program kasir yang mencari harga termahal dari daftar barang yang dibeli pelanggan.
