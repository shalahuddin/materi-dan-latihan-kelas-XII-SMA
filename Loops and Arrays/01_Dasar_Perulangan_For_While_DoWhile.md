# Modul 1: Dasar Perulangan (for, while, do-while)

## 1. Pendahuluan
Dalam pemrograman, sering kali kita perlu menjalankan perintah yang sama berkali-kali. Menulis kode yang sama berulang kali tidak efisien dan membuat kode sulit diperbaiki. Untuk mengatasi hal ini, kita menggunakan perulangan (*loop*).

Setiap perulangan dalam bahasa C membutuhkan tiga komponen utama:
1. **Inisialisasi**: Menentukan nilai awal variabel penghitung (*counter*).
2. **Kondisi**: Syarat perulangan terus berjalan. Jika kondisi bernilai benar (1), blok kode dijalankan. Jika salah (0), perulangan berhenti.
3. **Pembaruan (Update)**: Mengubah nilai variabel penghitung di setiap putaran agar perulangan tidak berjalan selamanya (*infinite loop*).

---

## 2. Struktur Perulangan `for`
Perulangan `for` digunakan saat kita sudah tahu berapa kali perulangan akan dijalankan.

### Sintaks
```c
for (inisialisasi; kondisi; pembaruan) {
    // Kode yang akan diulang
}
```

### Contoh Program
```c
#include <stdio.h>

int main() {
    // Mencetak angka 1 sampai 5
    for (int i = 1; i <= 5; i++) {
        printf("Angka ke-%d\n", i);
    }
    return 0;
}
```

### Penjelasan Alur Eksekusi
1. `int i = 1` dijalankan pertama kali.
2. Kondisi `i <= 5` dicek (1 <= 5 benar).
3. `printf("Angka ke-%d\n", i)` dijalankan.
4. `i++` dijalankan sehingga nilai `i` menjadi 2.
5. Langkah 2–4 diulang sampai `i = 6` (kondisi salah, perulangan berhenti).

---

## 3. Struktur Perulangan `while`
Perulangan `while` digunakan ketika jumlah perulangan belum pasti dan bergantung pada suatu kondisi yang dicek di awal.

### Sintaks
```c
inisialisasi;
while (kondisi) {
    // Kode yang akan diulang
    pembaruan;
}
```

### Contoh Program
```c
#include <stdio.h>

int main() {
    int energi = 100;

    while (energi > 0) {
        printf("Mobil berjalan... Sisa baterai: %d%%\n", energi);
        energi -= 25; // Mengurangi energi setiap putaran
    }
    printf("Baterai habis, mobil berhenti.\n");
    return 0;
}
```

---

## 4. Struktur Perulangan `do-while`
Perulangan `do-while` mirip dengan `while`, tetapi kondisinya dicek di akhir. Artinya, blok kode pasti dijalankan minimal satu kali meskipun kondisi sejak awal salah.

### Sintaks
```c
inisialisasi;
do {
    // Kode yang akan diulang
    pembaruan;
} while (kondisi);
```

### Contoh Program (Validasi Input)
```c
#include <stdio.h>

int main() {
    int nilai;

    do {
        printf("Masukkan nilai ujian (0 - 100): ");
        scanf("%d", &nilai);

        if (nilai < 0 || nilai > 100) {
            printf("Input tidak valid! Silakan ulangi.\n");
        }
    } while (nilai < 0 || nilai > 100);

    printf("Nilai yang Anda masukkan: %d\n", nilai);
    return 0;
}
```

---

## 5. Pengendali Perulangan: `break` dan `continue`

- **`break`**: Menghentikan perulangan secara paksa dan langsung keluar dari blok loop.
- **`continue`**: Melewati sisa perintah pada putaran saat ini dan langsung melompat ke putaran berikutnya.

### Contoh `break`
```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            printf("Perulangan berhenti di angka %d\n", i);
            break;
        }
        printf("%d ", i);
    }
    // Output: 1 2 3 4 Perulangan berhenti di angka 5
    return 0;
}
```

### Contoh `continue`
```c
#include <stdio.h>

int main() {
    // Mencetak hanya angka ganjil (melewati angka genap)
    for (int i = 1; i <= 6; i++) {
        if (i % 2 == 0) {
            continue; // Lewati angka genap
        }
        printf("%d ", i);
    }
    // Output: 1 3 5
    return 0;
}
```

---

## 6. Kesalahan yang Sering Terjadi

1. **Lupa Memberikan Pembaruan (Infinite Loop)**
   ```c
   int i = 1;
   while (i <= 5) {
       printf("%d\n", i);
       // Lupa menulis i++, nilai i selalu 1 dan program tidak pernah berhenti
   }
   ```

2. **Menaruh Titik Koma Setelah Header Loop**
   ```c
   // Salah: Titik koma mengakhiri loop sebelum blok dijalankan
   for (int i = 0; i < 5; i++); 
   {
       printf("Halo\n"); // Hanya dicetak 1 kali setelah loop selesai
   }
   ```

3. **Salah Kondisi Berhenti (Off-by-One)**
   - Jika ingin mengulang 5 kali dari angka 1, gunakan `i <= 5` atau `i < 6`.
   - Menulis `for (int i = 1; i < 5; i++)` hanya akan berputar 4 kali (1, 2, 3, 4).

---

## 7. Latihan Mandiri
1. Buat program yang mencetak tabel perkalian 7 dari `7 x 1 = 7` sampai `7 x 10 = 70` menggunakan perulangan `for`.
2. Buat program hitung mundur peluncuran roket dari angka 10 sampai 1, lalu cetak `"Meluncur!"` di akhir menggunakan perulangan `while`.
3. Buat program menu sederhana dengan pilihan 1 (Lihat Saldo), 2 (Tarik Tunai), dan 3 (Keluar). Program terus menampilkan menu sampai pengguna memilih angka 3.
