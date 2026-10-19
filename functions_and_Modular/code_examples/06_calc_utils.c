/*
 * File: 06_calc_utils.c
 * Week: 05 - Functions & Modular Programming
 * Description: Implementasi modul kalkulator utilitas LABS
 *
 * Learning Points:
 * - File .c berisi badan implementasi lengkap dari prototipe di .h
 * - Wajib include header-own-self: #include "06_calc_utils.h"
 * - Setiap fungsi wajib punya return type yang sesuai prototipe
 * - Kompilasi gabungan: gcc 06_modular_calc_main.c 06_calc_utils.c -o app
 *
 * Compile (gabungan dengan main):
 *   gcc 06_modular_calc_main.c 06_calc_utils.c -o 06_modular_calc_main
 *   .\06_modular_calc_main.exe
 *
 * Attribution:
 * - Materi Hari 4 Minggu 05 LABS (Implementasi Modular & Multi-Source GCC).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>
#include "06_calc_utils.h" // 1. Sertakan kontrak header sendiri!
                      // 2. Tanpa ini, komp akan error: implicit declaration

// ============================================================
// 1. IMPLEMENTASI: hitung_subtotal
// ============================================================
// Rumus: harga_satuan dikali jumlah
// Contoh: hitung_subtotal(45000, 3) → 135000
// ============================================================
int hitung_subtotal(int harga_satuan, int jumlah) {
    return harga_satuan * jumlah;
}

// ============================================================
// 2. IMPLEMENTASI: hitung_pajak
// ============================================================
// Rumus: total_belanja dikalikan tarif PPN dibagi 100
// Contoh: hitung_pajak(135000) → 14850 (11% dari 135000)
// Perhatikan: integer division akan membuang sisa desimal, ini wajar
//           untuk kasus sekolah (dibulatkan ke bawah).
// ============================================================
int hitung_pajak(int total_belanja) {
    return total_belanja * TARIF_PAJAK_PPN / 100;
}

// ============================================================
// 3. IMPLEMENTASI: hitung_ongkos_kirim
// ============================================================
// Logika:
//   - Jika total >= MINIMAL_GRATIS_ONGKIR (100rb) → ongkir 0 (Gratis!)
//   - Jika total < 100rb → ongkir tetap Rp15.000
// ============================================================
int hitung_ongkos_kirim(int total_belanja) {
    if (total_belanja >= MINIMAL_GRATIS_ONGKIR) {
        return 0; // Ongkir GRATIS!
    } else {
        return 15000; // Tarif reguler
    }
}

// ============================================================
// 4. IMPLEMENTASI: cetak_garis_pemisah
// ============================================================
// Fungsi void: hanya melakukan aksi cetak, tidak mengembalikan nilai
// ============================================================
void cetak_garis_pemisah(void) {
    printf("----------------------------------------\n");
}