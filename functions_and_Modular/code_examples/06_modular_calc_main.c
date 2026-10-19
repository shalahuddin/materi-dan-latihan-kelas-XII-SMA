/*
 * File: 06_modular_calc_main.c
 * Week: 05 - Functions & Modular Programming
 * Description: Program utama (driver) untuk mengonsumsi modul kalkulator
 *            berstruktur 3 file (header + implementasi + main).
 *
 * Learning Points:
 * - Cukup #include header .h, bukan .c!
 * - Kompilasi gabungan: gcc main.c utils.c -o program
 * - Pemisahan tanggung jawab: main hanya mengatur alur, utils berisi logika
 * - Header guard mencegah redefinisi saat include berulang
 *
 * Compile:
 *   gcc 06_modular_calc_main.c 06_calc_utils.c -o 06_modular_calc_main
 *   .\06_modular_calc_main.exe
 *
 * Attribution:
 * - Materi Hari 4 Minggu 05 LABS (Modularitas, Header File, & Multi-Source GCC).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>
#include "06_calc_utils.h" // Cukup include header, jangan include .c!

int main() {
    printf("=== APLIKASI KASIR MODULAR SMA LABS ===\n\n");

    // --------------------------------------------------------
    // DATA INPUT (bisa dari user, hardcoded, atau file)
    // --------------------------------------------------------
    int harga_buku = 45000;
    int jumlah_beli = 3;

    // --------------------------------------------------------
    // PEMANGILAN FUNGSI-MODUL (dari file utils)
    // --------------------------------------------------------
    int subtotal = hitung_subtotal(harga_buku, jumlah_beli);
    int pajak = hitung_pajak(subtotal);
    int ongkir = hitung_ongkos_kirim(subtotal);
    int grand_total = subtotal + pajak + ongkir;

    // --------------------------------------------------------
    // OUTPUT: Laporan rapi pakai fungsi cetak_garis dari utils
    // --------------------------------------------------------
    cetak_garis_pemisah();
    printf("     INVOICE PENJUALAN BARANG      \n");
    cetak_garis_pemisah();

    printf("Item        : Buku Pemrograman C\n");
    printf("Harga Satuan: Rp%d\n", harga_buku);
    printf("Jumlah      : %d pcs\n", jumlah_beli);
    cetak_garis_pemisah();

    printf("Subtotal    : Rp%d\n", subtotal);
    printf("PPN (%d%%)   : Rp%d\n", 11, pajak); // Bisa juga pake #define dari header
    printf("Ongkir      : Rp%d\n", ongkir);
    cetak_garis_pemisah();

    printf("GRAND TOTAL : Rp%d\n", grand_total);
    cetak_garis_pemisah();

    printf("Terima kasih sudah berbelanja di LABS! 🎓\n\n");

    return 0;
}