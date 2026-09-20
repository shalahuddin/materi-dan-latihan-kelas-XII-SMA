/*
 * File       : 06_matrix_2d_basics.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Demonstrasi deklarasi Array 2D (Matriks), traversal nested loop,
 *              penjumlahan total baris (siswa) dan rata-rata kolom (mata pelajaran).
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
 *   gcc 06_matrix_2d_basics.c -o 06_matrix_2d_basics
 *   .\06_matrix_2d_basics.exe
 */

#include <stdio.h>

#define JUMLAH_SISWA 3
#define JUMLAH_MAPEL 3

int main(void) {
    printf("========================================\n");
    printf("     DEMO PENGOLAHAN ARRAY 2D (MATRIKS) \n");
    printf("========================================\n\n");

    // Matriks Nilai: Baris = Siswa, Kolom = Mapel (Matematika, Fisika, Informatika)
    int nilai[JUMLAH_SISWA][JUMLAH_MAPEL] = {
        {85, 90, 95}, // Siswa 1 (Budi)
        {78, 82, 88}, // Siswa 2 (Siti)
        {92, 85, 90}  // Siswa 3 (Anton)
    };

    char *nama_siswa[JUMLAH_SISWA] = {"Budi", "Siti", "Anton"};

    printf("Tabel Rekapitulasi Nilai Siswa:\n");
    printf("%-10s %-8s %-8s %-8s %-8s %-10s\n", "Nama", "Mat", "Fis", "Inf", "Total", "Rata-rata");
    printf("----------------------------------------------------------\n");

    // 1. Agregasi per Baris (Total dan Rata-rata per Siswa)
    for (int i = 0; i < JUMLAH_SISWA; i++) {
        int total_siswa = 0;
        printf("%-10s ", nama_siswa[i]);
        for (int j = 0; j < JUMLAH_MAPEL; j++) {
            printf("%-8d ", nilai[i][j]);
            total_siswa += nilai[i][j];
        }
        float avg_siswa = (float)total_siswa / JUMLAH_MAPEL;
        printf("%-8d %-10.2f\n", total_siswa, avg_siswa);
    }
    printf("----------------------------------------------------------\n");

    // 2. Agregasi per Kolom (Rata-rata per Mata Pelajaran)
    printf("%-10s ", "Rerata Mapel");
    for (int j = 0; j < JUMLAH_MAPEL; j++) {
        int total_mapel = 0;
        for (int i = 0; i < JUMLAH_SISWA; i++) {
            total_mapel += nilai[i][j];
        }
        float avg_mapel = (float)total_mapel / JUMLAH_SISWA;
        printf("%-8.1f ", avg_mapel);
    }
    printf("\n\n");

    // 3. Bukti Row-Major Order di Memori
    printf("Representasi Memori Row-Major Order (Alamat berurutan linier):\n");
    for (int i = 0; i < JUMLAH_SISWA; i++) {
        for (int j = 0; j < JUMLAH_MAPEL; j++) {
            printf("  nilai[%d][%d] (%d) @ %p\n", i, j, nilai[i][j], (void *)&nilai[i][j]);
        }
    }

    return 0;
}
