/*
 * File: 03_prototype_and_order.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi prototipe fungsi dan urutan kompilasi C
 *
 * Learning Points:
 * - Prototipe fungsi di atas main() menyelamatkan dari warning kompilator
 * - Urutan standar industri: prototipe → main → definisi fungsi
 * - "Implicit declaration" error saat prototipe lupa
 * - Compilasi multi-source: gcc file1.c file2.c -o program
 *
 * Compile (single file):
 *   gcc 03_prototype_and_order.c -o 03_prototype_and_order
 *   .\03_prototype_and_order.exe
 *
 * Compile (multi-file example):
 *   gcc 03_prototype_and_order.c utils.c -o 03_full_demo
 *
 * Attribution:
 * - Materi Hari 2 Minggu 05 LABS (Parameter, Argumen, dan Call by Value).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>

// ============================================================
// 1. PROTOTIPE FUNGSI (Deklarasi di BARIS ATAS)
// ==========================================================
// Jika PROTOTIPE INI DILUPUS (diletakkan di bawah main()),
// kompilator akan menampilkan warning:
//   warning: implicit declaration of function 'hitung'
// Kata kunci: Prototipe selalu diakhiri dengan titik koma ";"

int hitung_kali(int a, int b);

// Prototipe untuk fungsi void
void cetak_pesan(void);

// ============================================================
// 2. FUNGSI UTAMA: main()
// ============================================================
int main() {
    printf("=== PROTOTIPE FUNGSI & URUTAN KOMPILASI ===\n\n");

    // Memanggil hitung_kali() sebelum definisinya ada di bawah
    // Tapi karena ada prototipe di atas, kompilator tahu argumen & tipe datanya
    int hasil = hitung_kali(5, 8);
    printf("Hasil hitung_kali(5, 8) = %d\n\n", hasil);

    // Memanggil cetak_pesan() juga sudah terdeklarasi prototipenya
    cetak_pesan();

    printf("\nProgram berjalan tanpa warning implicit declaration.\n");
    return 0;
}

// ============================================================
// 3. DEFINISI / IMPLEMENTASI FUNGSI (DIBAWAH main())
// ============================================================
// Urutan ini (prototipe → main → definisi) adalah best practice
// standar industri untuk menjaga kode rapi dan kompilasi lancar.

// Implementasi fungsi hitung_kali
int hitung_kali(int a, int b) {
    return a * b;
}

// Implementasi fungsi cetak_pesan
void cetak_pesan(void) {
    printf("Program ini menggunakan prototipe fungsi di atas main().\n");
    printf("Ini adalah best practice arsitektur C.\n");
}