/*
 * File: 03_ternary.c
 * Author: Kelas XII LABS
 * Date: 2026-08-30
 * Description: Program untuk menentukan status lulus menggunakan operator ternary
 *
 * Attribution: Dapatkan dari materi pembelajaran LABS Week 04 Decision Making
 * Integrity Statement: Saya menyatakan bahwa saya tidak melakukan plagiasi dan
 * pekerjaan ini adalah hasil kerja saya sendiri sesuai dengan standar akademik LABS.
 */

#include <stdio.h>

int main() {
    int nilai;

    printf("Masukkan nilai (0-100): ");
    scanf("%d", &nilai);

    // Menggunakan operator ternary untuk menentukan status lulus
    const char *status = (nilai >= 60) ? "Lulus" : "Tidak Lulus";

    printf("Nilai Anda: %d\n", nilai);
    printf("Status: %s\n", status);

    // Contoh nested ternary untuk grade
    const char *grade = (nilai >= 80) ? "A" :
                        (nilai >= 70) ? "B" :
                        (nilai >= 60) ? "C" :
                        (nilai >= 50) ? "D" : "E";

    printf("Grade: %s\n", grade);

    return 0;
}