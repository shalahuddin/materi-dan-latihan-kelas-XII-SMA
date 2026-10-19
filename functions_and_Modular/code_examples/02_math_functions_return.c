/*
 * File: 02_math_functions_return.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demo fungsi ber-return value (int, float, char)
 *
 * Learning Points:
 * - Fungsi mengembalikan satu nilai lewat return
 * - Return type int vs float vs char
 * - Nilai kembalian bisa: disimpan ke variabel, langsung dicetak,
 *   atau dipakai dalam ekspresi matematika
 * - Integer division pada rumus diskon (sisa dibuang)
 *
 * Compile:
 *   gcc 02_math_functions_return.c -o 02_math_functions_return
 *   .\02_math_functions_return.exe
 *
 * Attribution:
 * - Materi Hari 1 Minggu 05 LABS (Pengenalan Fungsi & Anatomi Dasar).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>

// ============================================================
// Fungsi ber-return INT: mengembalikan hasil kali
// ============================================================
int perkalian(int a, int b) {
    return a * b;
}

// ============================================================
// Fungsi ber-return FLOAT: konversi Reamur ke Celcius
// Rumus: Celcius = Reamur * 5 / 4
 // Hati-hati integer division: tulis 5.0f / 4.0f
// ============================================================
float reamur_ke_celcius(float suhu_reamur) {
    return suhu_reamur * 5.0f / 4.0f;
}

// ============================================================
// Fungsi ber-return FLOAT: luas lingkaran
// Rumus: phi * r * r  (phi di-hardcode 3.14159)
// ============================================================
float luas_lingkaran(float radius) {
    const float phi = 3.14159f;
    return phi * radius * radius;
}

// ============================================================
// Fungsi ber-return CHAR: menentukan kelulusan
// Mengembalikan satu karakter: 'L' (lulus) atau 'T' (tidak lulus)
// ============================================================
char status_kelulusan(int nilai_akhir) {
    if (nilai_akhir >= 75) {
        return 'L';
    }
    return 'T';
}

int main() {
    printf("=== FUNGSI BER-RETURN VALUE (INT, FLOAT, CHAR) ===\n\n");

    // --------------------------------------------------------
    // 1. INT: nilai bisa disimpan ke variabel
    // --------------------------------------------------------
    int hasil_kali = perkalian(7, 6);
    printf("1) perkalian(7, 6) disimpan ke variabel = %d\n", hasil_kali);

    // --------------------------------------------------------
    // 2. INT: bisa langsung dicetak tanpa variabel penampung
    // --------------------------------------------------------
    printf("2) perkalian(9, 9)  langsung dicetak     = %d\n", perkalian(9, 9));

    // --------------------------------------------------------
    // 3. INT: bisa dipakai dalam ekspresi matematika
    // --------------------------------------------------------
    int ekspresi = perkalian(4, 5) + 10;
    printf("3) perkalian(4, 5) + 10                 = %d\n", ekspresi);

    // --------------------------------------------------------
    // 4. FLOAT: format specifier %.2f untuk 2 angka desimal
    // --------------------------------------------------------
    printf("4) 32.0 Reamur = %.2f Celcius\n", reamur_ke_celcius(32.0f));
    printf("5)  60.0 Reamur = %.2f Celcius\n", reamur_ke_celcius(60.0f));

    // --------------------------------------------------------
    // 5. FLOAT: luas lingkaran radius 7 dan 10
    // --------------------------------------------------------
    printf("6) Luas lingkaran r=7.0  = %.2f\n", luas_lingkaran(7.0f));
    printf("7) Luas lingkaran r=10.0 = %.2f\n", luas_lingkaran(10.0f));

    // --------------------------------------------------------
    // 6. CHAR: cetak karakter status, format specifier %c
    // --------------------------------------------------------
    printf("8) Nilai 85 -> status = %c\n", status_kelulusan(85));
    printf("9) Nilai 60 -> status = %c\n", status_kelulusan(60));

    return 0;
}
