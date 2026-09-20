/*
 * File       : 05_nested_loop_patterns.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Demonstrasi nested loop untuk membangun berbagai
 *              pola visual (persegi, segitiga bertingkat, dan piramida).
 *
 * Attribution:
 * - Standar Kurikulum C Programming Kelas XII LABS.
 * - Referensi: Modul Pembelajaran Minggu 06 Loops & Arrays.
 *
 * Integrity Statement:
 * Kode ini dibuat sebagai materi ajar resmi untuk siswa Kelas XII LABS.
 * Mengikuti konvensi penulisan bersih dan standar GCC MinGW.
 *
 * Compile:
 *   gcc 05_nested_loop_patterns.c -o 05_nested_loop_patterns
 *   .\05_nested_loop_patterns.exe
 */

#include <stdio.h>

int main(void) {
    printf("========================================\n");
    printf("     DEMO NESTED LOOP: POLA VISUAL     \n");
    printf("========================================\n\n");

    int n = 5;

    // 1. Pola Persegi Bintang (4 Baris x 6 Kolom)
    printf("[1] Pola Grid Persegi (4x6):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    // 2. Pola Segitiga Siku-Siku Angka
    printf("[2] Pola Segitiga Angka Bertingkat:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");

    // 3. Pola Segitiga Terbalik Bintang
    printf("[3] Pola Segitiga Terbalik:\n");
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    // 4. Pola Papan Catur / Checkerboard (Alternating Pattern)
    printf("[4] Pola Papan Catur (5x5):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) % 2 == 0) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}
