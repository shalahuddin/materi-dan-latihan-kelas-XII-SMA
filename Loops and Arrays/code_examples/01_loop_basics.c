/*
 * File       : 01_loop_basics.c
 * Author     : Tim Pengajar Informatika LABS
 * Class      : XII LABS
 * Date       : 2026-09-20
 * Description: Demonstrasi perbandingan loop for, while, do-while,
 *              serta implementasi kontrol iterasi break dan continue.
 *
 * Attribution:
 * - Standar Kurikulum C Programming Kelas XII LABS.
 * - Referensi: Modul Pembelajaran Minggu 06 Loops & Control Flow.
 *
 * Integrity Statement:
 * Kode ini dibuat sebagai materi ajar resmi untuk siswa Kelas XII LABS.
 * Mengikuti konvensi penulisan bersih dan standar GCC MinGW.
 *
 * Compile:
 *   gcc 01_loop_basics.c -o 01_loop_basics
 *   .\01_loop_basics.exe
 */

#include <stdio.h>

int main(void) {
    printf("========================================\n");
    printf("  DEMO PERULANGAN (FOR, WHILE, DO-WHILE)\n");
    printf("========================================\n\n");

    // 1. FOR LOOP: Perulangan terhitung (Counter-controlled)
    printf("[1] FOR LOOP - Deret Kelipatan 5 (5 - 25):\n");
    for (int i = 5; i <= 25; i += 5) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 2. WHILE LOOP: Pembagian berulang berbasis kondisi
    printf("[2] WHILE LOOP - Halving Value (64 down to 2):\n");
    int val = 64;
    while (val >= 2) {
        printf("%d ", val);
        val /= 2;
    }
    printf("\n\n");

    // 3. DO-WHILE LOOP: Eksekusi minimal 1 kali (Menu/Validasi)
    printf("[3] DO-WHILE LOOP - Simulasi Validasi PIN:\n");
    int pin_rahasia = 1234;
    int input_simulasi = 1234;
    int percobaan = 0;
    do {
        percobaan++;
        printf("    Mengecek PIN percobaan ke-%d...\n", percobaan);
    } while (input_simulasi != pin_rahasia && percobaan < 3);
    printf("    Autentikasi Berhasil pada percobaan ke-%d!\n\n", percobaan);

    // 4. BREAK & CONTINUE: Kontrol aliran iterasi
    printf("[4] BREAK & CONTINUE - Filter Bilangan Ganjil (Stop di 8):\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            continue; // Lewati bilangan ganjil
        }
        if (i > 8) {
            break; // Berhenti jika lebih dari 8
        }
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
