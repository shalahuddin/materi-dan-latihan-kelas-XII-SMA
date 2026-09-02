/*
 * File: 04_nested.c
 * Author: Kelas XII LABS
 * Date: 2026-08-30
 * Description: Program yang menggabungkan if-else dan switch untuk memproses dua angka.
 *              Jika kedua angka positif, menampilkan operasi aritmatika berdasarkan pilihan switch.
 *              Jika salah satu angka negatif, program berhenti dengan pesan error.
 *
 * Attribution: Dapatkan dari materi pembelajaran LABS Week 04 Decision Making
 * Integrity Statement: Saya menyatakan bahwa saya tidak melakukan plagiasi dan
 * pekerjaan ini adalah hasil kerja saya sendiri sesuai dengan standar akademik LABS.
 */

#include <stdio.h>

int main() {
    int a, b, pilihan;

    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);

    // Guard clause: jika salah satu angka negatif, tampilkan pesan dan keluar
    if (a < 0 || b < 0) {
        printf("Tidak dapat proses: ada angka negatif.\n");
        return 0;
    }

    // Kedua angka positif, tampilkan menu operasi
    printf("\nPilih operasi:\n");
    printf("1. Penjumblahan (+)\n");
    printf("2. Pengurangan (-)\n");
    printf("3. Perkalian (*)\n");
    printf("4. Pembagian (/)\n");
    printf("Masukkan pilihan (1-4): ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case 2:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case 3:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case 4:
            if (b != 0) {
                printf("%d / %d = %.2f\n", a, b, (float)a / b);
            } else {
                printf("Error: Pembagian dengan nol!\n");
            }
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }

    return 0;
}