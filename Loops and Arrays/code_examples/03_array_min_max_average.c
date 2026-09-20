/*
 * File       : 03_array_min_max_average.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Modul analitik statistik array: Akumulator (Sum & Avg),
 *              Pencarian Nilai Ekstrem (Min & Max), dan Tracking Indeks.
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
 *   gcc 03_array_min_max_average.c -o 03_array_min_max_average
 *   .\03_array_min_max_average.exe
 */

#include <stdio.h>

#define JUMLAH_DATA 6

int main(void) {
    printf("========================================\n");
    printf("  STATISTIK DATA ARRAY: SUM, AVG, MIN, MAX\n");
    printf("========================================\n\n");

    int suhu[JUMLAH_DATA] = {28, 31, 26, 35, 29, 33};
    int n = JUMLAH_DATA;

    int total = 0;
    int max_val = suhu[0];
    int min_val = suhu[0];
    int idx_max = 0;
    int idx_min = 0;

    printf("Data Pengukuran Suhu Ruangan (C):\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", suhu[i]);
        total += suhu[i]; // Akumulator

        // Evaluasi Nilai Maksimum
        if (suhu[i] > max_val) {
            max_val = suhu[i];
            idx_max = i;
        }

        // Evaluasi Nilai Minimum
        if (suhu[i] < min_val) {
            min_val = suhu[i];
            idx_min = i;
        }
    }
    printf("]\n\n");

    // Explicit casting untuk mencegah integer division truncation
    float rata_rata = (float)total / n;

    printf("--- RINGKASAN STATISTIK ---\n");
    printf("Total Akumulasi : %d C\n", total);
    printf("Rata-rata Suhu  : %.2f C\n", rata_rata);
    printf("Suhu Tertinggi  : %d C (Data ke-%d, Indeks [%d])\n", max_val, idx_max + 1, idx_max);
    printf("Suhu Terendah   : %d C (Data ke-%d, Indeks [%d])\n", min_val, idx_min + 1, idx_min);

    return 0;
}
