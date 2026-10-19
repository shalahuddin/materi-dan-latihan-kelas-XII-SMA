/*
 * File: 06_calc_utils.h
 * Week: 05 - Functions & Modular Programming
 * Description: File header kontrak modul kalkulator utilitas LABS
 *
 * Learning Points:
 * - #ifndef / #define / #endif (Include Guard) mencegah double inclusion
 * - Prototipe fungsi hanya (tidak ada badan implementasi { ... })
 * - #define konstanta publik bisa diakses dari file utama
 * - Gunakan tanda " "... (ganda kutip) untuk header lokal, bukan <...>
 *
 * Compile catatan:
 *   - File ini HANYA dibaca oleh preprosesor saat #include
 *   - Implementasi fungsi SELALU berada di file .c yang sesuai
 *
 * Attribution:
 * - Materi Hari 4 Minggu 05 LABS (Header File & Modularitas).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#ifndef CALC_UTILS_H
#define CALC_UTILS_H

// ============================================================
// KONSTANTA PUBLIK (bisa juga dipakai di file main via #include)
// ============================================================
#define TARIF_PAJAK_PPN 11      // Persentase PPN tetap
#define MINIMAL_GRATIS_ONGKIR 100000 // Batas ongkir gratis

// ============================================================
// PROTOTIPE FUNGSI (Daftar Kontrak Fungsi)
// Tidak ada badan fungsi { ... } di sini!
// ============================================================

// Menghitung subtotal: harga_satuan * jumlah
int hitung_subtotal(int harga_satuan, int jumlah);

// Menghitung nominal pajak dari total belanja
int hitung_pajak(int total_belanja);

// Menghitung ongkos kirim berdasarkan total belanja
int hitung_ongkos_kirim(int total_belanja);

// Mencetak garis pembatas decorative
void cetak_garis_pemisah(void);

#endif // CALC_UTILS_H