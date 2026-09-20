/*
 * File       : 04_linear_search_sentinel.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Demonstrasi algoritma Linear Search dengan early exit
 *              dan pembacaan data stream berbasis Sentinel Value (-1).
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
 *   gcc 04_linear_search_sentinel.c -o 04_linear_search_sentinel
 *   .\04_linear_search_sentinel.exe
 */

#include <stdio.h>

#define MAX_CAPACITY 10

int main(void) {
    printf("========================================\n");
    printf("  DEMO LINEAR SEARCH & SENTINEL VALUE   \n");
    printf("========================================\n\n");

    // 1. Inisialisasi Data Array
    int data_id[MAX_CAPACITY] = {101, 204, 308, 412, 515, 620, 725, 830};
    int total_data = 8;

    printf("Daftar ID Terdaftar:\n[ ");
    for (int i = 0; i < total_data; i++) {
        printf("%d ", data_id[i]);
    }
    printf("]\n\n");

    // 2. Linear Search dengan Early Exit
    int target_cari = 412;
    int indeks_ditemukan = -1;
    int jumlah_komparasi = 0;

    printf("[1] Mencari ID: %d...\n", target_cari);
    for (int i = 0; i < total_data; i++) {
        jumlah_komparasi++;
        if (data_id[i] == target_cari) {
            indeks_ditemukan = i;
            break; // Early exit: hemat siklus CPU
        }
    }

    if (indeks_ditemukan != -1) {
        printf("    STATUS: Ditemukan pada Indeks [%d] (Komparasi: %d kali)\n\n",
               indeks_ditemukan, jumlah_komparasi);
    } else {
        printf("    STATUS: ID tidak ditemukan (Komparasi: %d kali)\n\n",
               jumlah_komparasi);
    }

    // 3. Simulasi Input Stream dengan Sentinel Value (-1)
    printf("[2] Simulasi Pembacaan Buffer dengan Sentinel (-1):\n");
    int input_stream[] = {25, 60, 88, 40, -1, 99}; // -1 adalah sentinel
    int stream_size = sizeof(input_stream) / sizeof(input_stream[0]);
    int buffer[MAX_CAPACITY];
    int count = 0;

    for (int i = 0; i < stream_size; i++) {
        if (input_stream[i] == -1) {
            printf("    -> Sentinel (-1) terdeteksi! Menghentikan pembacaan stream.\n");
            break;
        }
        buffer[count] = input_stream[i];
        count++;
    }

    printf("    Total data valid yang tersimpan: %d elemen [ ", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("]\n");

    return 0;
}
