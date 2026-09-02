/*
 * File: 02_switch.c
 * Author: Kelas XII LABS
 * Date: 2026-08-30
 * Description: Program untuk menampilkan nama hari menggunakan switch case
 *
 * Attribution: Dapatkan dari materi pembelajaran LABS Week 04 Decision Making
 * Integrity Statement: Saya menyatakan bahwa saya tidak melakukan plagiasi dan
 * pekerjaan ini adalah hasil kerja saya sendiri sesuai dengan standar akademik LABS.
 */

#include <stdio.h>

int main() {
    int hari;

    printf("Masukkan angka 1-7 untuk hari (1=Senin): ");
    scanf("%d", &hari);

    switch (hari) {
        case 1: printf("Senin\n"); break;
        case 2: printf("Selasa\n"); break;
        case 3: printf("Rabu\n"); break;
        case 4: printf("Kamis\n"); break;
        case 5: printf("Jumat\n"); break;
        case 6: printf("Sabtu\n"); break;
        case 7: printf("Minggu\n"); break;
        default: printf("Input tidak valid!\n");
    }

    return 0;
}