# Modul 4: Perulangan Bersarang (Nested Loop) dan Array Dua Dimensi

## 1. Pendahuluan
Pada modul sebelumnya, kita telah mempelajari perulangan tunggal dan array satu dimensi. Dalam penerapannya, sering kali kita menghadapi struktur data yang memiliki bentuk baris dan kolom (tabel/matriks) atau membutuhkan perulangan di dalam perulangan lain (*nested loop*).

---

## 2. Perulangan Bersarang (Nested Loop)
*Nested loop* adalah struktur perulangan di mana sebuah loop berada di dalam badan loop lainnya.

- **Loop Luar (Outer Loop)**: Mengontrol perpindahan baris / kelompok iterasi.
- **Loop Dalam (Inner Loop)**: Menyelesaikan seluruh putarannya untuk setiap satu putaran loop luar.

### Contoh Program: Menampilkan Pola Bintang Sederhana
```c
#include <stdio.h>

int main() {
    int baris = 4;
    int kolom = 5;

    for (int i = 1; i <= baris; i++) {
        for (int j = 1; j <= kolom; j++) {
            printf("* ");
        }
        printf("\n"); // Pindah baris setelah inner loop selesai
    }

    return 0;
}
```

### Output:
```text
* * * * * 
* * * * * 
* * * * * 
* * * * * 
```

---

## 3. Pola Segitiga Bintang
Dengan mengatur batas perulangan dalam agar bergantung pada nilai variabel perulangan luar, kita dapat membentuk pola bertingkat.

```c
#include <stdio.h>

int main() {
    int tinggi = 5;

    for (int i = 1; i <= tinggi; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
```

### Output:
```text
* 
* * 
* * * 
* * * * 
* * * * * 
```

---

## 4. Pengenalan Array Dua Dimensi (Matriks)
Array dua dimensi adalah kumpulan data yang disusun dalam bentuk tabel yang terdiri atas **baris** dan **kolom**.

### Deklarasi dan Inisialisasi
```c
int matriks[2][3] = {
    {10, 20, 30}, // Baris 0
    {40, 50, 60}  // Baris 1
};
```

### Cara Akses Elemen: `nama_array[indeks_baris][indeks_kolom]`
- `matriks[0][0]` bernilai `10`
- `matriks[0][2]` bernilai `30`
- `matriks[1][1]` bernilai `50`

---

## 5. Input dan Output Matriks dengan Nested Loop

```c
#include <stdio.h>

int main() {
    int nilai[2][3];

    // 1. Membaca input nilai
    printf("--- Input Nilai Tabel (2 Baris, 3 Kolom) ---\n");
    for (int b = 0; b < 2; b++) {
        for (int k = 0; k < 3; k++) {
            printf("Nilai [%d][%d]: ", b, k);
            scanf("%d", &nilai[b][k]);
        }
    }

    // 2. Menampilkan bentuk tabel
    printf("\n--- Tampilan Tabel ---\n");
    for (int b = 0; b < 2; b++) {
        for (int k = 0; k < 3; k++) {
            printf("%4d ", nilai[b][k]);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 6. Kesalahan yang Sering Terjadi

1. **Tertukar Antara Indeks Baris dan Kolom**
   - Indeks pertama selalu **baris**, indeks kedua selalu **kolom** (`matriks[baris][kolom]`).

2. **Lupa Memberikan Pindah Baris (`\n`)**
   - Jika lupa menaruh `printf("\n");` di luar perulangan dalam, tampilan tabel/matriks akan dicetak memanjang ke samping dalam satu baris.

3. **Menggunakan Variabel Counter yang Sama**
   - Jangan menggunakan nama variabel yang sama untuk loop luar dan loop dalam (misal keduanya menggunakan `i`), karena nilai variabel akan saling bertabrakan dan merusak alur perulangan.

---

## 7. Latihan Mandiri
1. Buat program yang mencetak tabel perkalian 1 sampai 5 dalam format baris dan kolom.
2. Buat program yang menjumlahkan seluruh angka yang ada di dalam sebuah matriks ukuran 2x2.
