/*
 * File: 05_local_global_shadowing.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi scope variabel, lifetime, dan shadowing
 *
 * Learning Points:
 * - Variabel Lokal: hidup di dalam kurung kurawal {}, mati keluar
 * - Variabel Global: hidup seluruh file, diakses dari mana saja
 * - Variable Shadowing: variabel lokal menutupi global di wilayahnya
 * - Lateral move: variabel lokal tidak bisa diakses dari luar fungsinya
 *
 * Compile:
 *   gcc 05_local_global_shadowing.c -o 05_local_global_shadowing
 *   .\05_local_global_shadowing.exe
 *
 * Attribution:
 * - Materi Hari 3 Minggu 05 LABS (Scope Variabel, Lokal vs Global, Lifetime).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>

// ============================================================
// 1. VARIABEL GLOBAL: Dapat diakses dari mana saja di file ini
// ============================================================
int angka_glob = 100; // Diakses siapa saja, keseluruhan file ini

// ============================================================
// 2. PROTOTIPE FUNGSI
// ============================================================
void demo_shadowing(void);
void demo_block_scope(void);

int main() {
    printf("=== DEMO SCOPE & LIFETIME VARIABEL ===\n\n");

    // --------------------------------------------------------
    // A. Akses variabel global dari main()
    // --------------------------------------------------------
    printf("1. Dari main(): angka_glob = %d\n", angka_glob);

    // --------------------------------------------------------
    // B. Panggil fungsi demonstrasi shadowing
    // --------------------------------------------------------
    printf("\n2. Memanggil demo_shadowing()...\n");
    demo_shadowing();

    // --------------------------------------------------------
    // C. Cek variabel global setelah fungsi selesai
    // --------------------------------------------------------
    printf("\n3. Kembali ke main(): angka_glob = %d (masih 100)\n\n", angka_glob);

    // --------------------------------------------------------
    // D. Uji blok scope (variabel dalam kurung kurawal)
    // --------------------------------------------------------
    printf("4. MENCUMAK Blok Scope (variabel dalam kurung kurawal):\n");
    demo_block_scope();

    // --------------------------------------------------------
    // E. Coba akses variabel lokal dari blok di luar blok
    // --------------------------------------------------------
    // printf("%d", variabel_dalam_blok); // Akan error! Variabel tersebut sudah mati.

    printf("\n5. Kesimpulan: Variabel di dalam blok {} mati saat } selesai.\n\n");

    return 0;
}

// ============================================================
// FUNGSI: demo_shadowing - Variable Shadowing
// ============================================================
void demo_shadowing(void) {
    // Variabel Lokal dengan nama persis sama dengan global
    int angka_glob = 5; // Lokal menyembunyikan (shadowing) global!

    printf("   -> Di dalam fungsi: angka_glob (lokal) = %d\n", angka_glob);
    printf("   -> Variabel global sebenarnya masih 100, tapi tidak terlihat.\n");

    // Catatan: Jika kita menulis di sini `angka_glob = 50;`,
    // maka variabel lokal ini yang diubah, bukan global 100.
}

// ============================================================
// FUNGSI: demo_block_scope - Variabel dalam blok kurung kurawal
// ============================================================
void demo_block_scope(void) {
    int x = 10; // Variabel lokal di level fungsi

    {
        // Blok kurung kurawal nested (didalam fungsi)
        int y = 20; // Variabel lokal di level blok ini
        printf("   -> Di dalam nested block: x = %d, y = %d\n", x, y);

        // y hanya bisa diakses di sini di dalam blok ini
        // Begitu tutup blok ini (}, y mati!)
    }

    // printf("%d", y); // ERROR KOMPILASI: y sudah mati (out of scope)!
    printf("   -> Setelah blok tertutup: x = %d (x masih hidup, fungsi belum selesai)\n", x);
}