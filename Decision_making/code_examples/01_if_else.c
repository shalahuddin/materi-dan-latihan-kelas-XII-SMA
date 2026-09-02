/*
 * File: 01_if_else.c
 * Author: Kelas XII LABS
 * Date: 2026-08-30
 * Description: Program untuk menentukan kategori bilangan (positif, negatif, nol) menggunakan if-else
 *
 * Attribution: Dapatkan dari materi pembelajaran LABS Week 04 Decision Making
 * Integrity Statement: Saya menyatakan bahwa saya tidak melakukan plagiasi dan
 * pekerjaan ini adalah hasil kerja saya sendiri sesuai dengan standar akademik LABS.
 */

#include <stdio.h>

int main() {
    int angka;

    printf("Masukkan sebuah angka: ");
    scanf("%d", &angka);

    if (angka > 0) {
        printf("Positif\n");
    } else if (angka < 0) {
        printf("Negatif\n");
    } else {
        printf("Nol\n");
    }

    return 0;
}