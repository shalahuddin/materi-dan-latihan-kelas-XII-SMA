/*
 * File       : 02_array_basics.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Demonstrasi deklarasi, inisialisasi, input dinamis,
 *              traversal forward/reverse, dan alamat memori kontigu array 1D.
 *
 * Attribution:
 * - Standar Kurikulum C Programming Kelas XII LABS.
 * - Referensi: Modul Pembelajaran Minggu 06 Loops and Arrays.
 *
 * Integrity Statement:
 * Kode ini dibuat sebagai materi ajar resmi untuk siswa Kelas XII LABS.
 * Mengikuti konvensi penulisan bersih dan standar GCC MinGW.
 *
 * Compile:
 *   gcc 02_array_basics.c -o 02_array_basics
 *   .\02_array_basics.exe
 */

#include <stdio.h>

#define MAX_ITEMS 5

int main(void) {
    printf("========================================\n");
    printf("     DEMO DASAR ARRAY 1 DIMENSI        \n");
    printf("========================================\n\n");

    // Inisialisasi eksplisit
    int nilai[MAX_ITEMS] = {85, 92, 78, 90, 88};
    int n = sizeof(nilai) / sizeof(nilai[0]);

    // 1. Traversal Maju (Forward Traversal)
    printf("[1] Traversal Maju Nilai Siswa:\n");
    for (int i = 0; i < n; i++) {
        printf("    Indeks [%d] -> Nilai: %d\n", i, nilai[i]);
    }
    printf("\n");

    // 2. Traversal Mundur (Reverse Traversal)
    printf("[2] Traversal Mundur:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("    Indeks [%d] -> Nilai: %d\n", i, nilai[i]);
    }
    printf("\n");

    // 3. Modifikasi Nilai In-Place
    printf("[3] Modifikasi Nilai (+5 Poin Bonus, Cap Maks 100):\n");
    for (int i = 0; i < n; i++) {
        nilai[i] += 5;
        if (nilai[i] > 100) {
            nilai[i] = 100;
        }
        printf("    Indeks [%d] -> Nilai Baru: %d\n", i, nilai[i]);
    }
    printf("\n");

    // 4. Bukti Memori Kontigu (Contiguous Memory Addresses)
    printf("[4] Alamat Memori (Setiap int = %u byte):\n", (unsigned int)sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("    &nilai[%d] = %p (Isi: %d)\n", i, (void *)&nilai[i], nilai[i]);
    }

    return 0;
}
