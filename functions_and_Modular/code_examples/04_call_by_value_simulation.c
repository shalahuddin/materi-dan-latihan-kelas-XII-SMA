/*
 * File: 04_call_by_value_simulation.c
 * Week: 05 - Functions & Modular Programming
 * Description: Simulasi mekanisme Call by Value dan isolasi memori
 *
 * Learning Points:
 * - C SELALA menyalin nilai (copy of value), bukan variabel asli
 * - Variabel lokal fungsi "matian" setelah fungsi selesai (stack pop)
 * - Mencoba tukar nilai di fungsi = tidak berubah di main() (probak!)
 * - Diagram memori: setiap fungsi punya stack frame sendiri
 *
 * Compile:
 *   gcc 04_call_by_value_simulation.c -o 04_call_by_value_simulation
 *   .\04_call_by_value_simulation.exe
 *
 * Attribution:
 * - Materi Hari 2 Minggu 05 LABS (Call by Value & Prototipe Fungsi).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>

// ============================================================
// FUNGSI EXPERIMEN: Mencoba mengubah nilai parameter
// Argumen dikirim seolah-olah itu adalah fotokopi lembar kerja,
// bukan lembar asli yang diletakkan di meja utama.
// ============================================================
void uji_tukar(int a, int b) {
    int temp = a;
    a = b;      // Mengubah salinan lokal 'a'
    b = temp;   // Mengubah salinan lokal 'b'

    printf("[DI DALAM FUNGSI] a = %d, b = %d\n", a, b);
    printf("[DI DALAM FUNGSI] Alamat a di dalam: %p\n", (void *)&a);
    printf("[DI DALAM FUNGSI] Alamat b di dalam: %p\n", (void *)&b);
}

// ============================================================
// FUNGSI EXPERIMEN: Mencoba mengubah variabel global
// ⚠️ WARNING: Variabel global berbahaya di proyek besar!
// ============================================================
int skor_global = 100; // Variabel global yang bisa diakses siapa saja

void ubah_skor_global(void) {
    skor_global = 0;  // Ini memang Mengubah variabel LUAR!
    printf("[DI DALAM FUNGSI] skor_global berhasil di-set menjadi 0\n");
}

// ============================================================
// FUNGSI UTAMA: main()
// ============================================================
int main() {
    printf("=== SIMULASI CALL BY VALUE: Isolasi Memori ===\n\n");

    // ==========================================================
    // 1. Eksperimen Tukar Nilai (Swap Trap)
    // ==========================================================
    int x = 10;
    int y = 20;

    printf("--- BEFORE: nilai asli di main() ---\n");
    printf("x = %d, y = %d\n\n", x, y);

    printf("--- MEMELEPUK FUNGSI uji_tukar(x, y) ---\n");
    uji_tukar(x, y);

    printf("--- AFTER: nilai asli di main() (setelah fungsi selesai) ---\n");
    printf("x = %d, y = %d\n\n", x, y);

    // ==========================================================
    // 2. Analisis & Pembuktian
    // ==========================================================
    printf("KESIMPULAN ANALISIS:\n");
    printf("1. Di dalam fungsi uji_tukar, variabel 'a' dan 'b' hanyalah\n");
    printf("   salinan (copy) dari nilai x dan y. Mereka hidup di alamat\n");
    printf("   memori terpisah (lihat %p dan %p di atas).\n\n");
    printf("2. Begitu fungsi selesai dieksekusi, stack frame 'uji_tukar'\n");
    printf("   langsung 'pop' dari memori. Variabel 'a' dan 'b' menghilang!\n\n");
    printf("3. Variabel asli 'x' dan 'y' di main() tidak terkena apa-apa.\n");
    printf("   Ini adalah alasan C disebut 'Call by Value'.\n\n");
    printf("4. Untuk BENYAKAR mengubah variabel luar, kita butuh POINTER\n");
    printf("   (akan dipelajari di Semester Genap) atau RETURN VALUE.\n\n");

    // ==========================================================
    // 2. Eksperimen Ubah Global (Side Effect)
    // ==========================================================
    printf("--- BEFORE: skor_global di main() ---\n");
    printf("skor_global = %d\n\n", skor_global);

    printf("--- MEMELEPUK FUNGSI ubah_skor_global() ---\n");
    ubah_skor_global();

    printf("--- AFTER: skor_global di main() (setelah fungsi selesai) ---\n");
    printf("skor_global = %d\n\n", skor_global);

    printf("CATATAN: Fungsi 'ubah_skor_global' berhasil mengubah nilai\n");
    printf("variabel luar karena skor_global adalah global (file scope).\n");
    printf("Ini adalah 'side effect' yang sering menyebabkan bug di proyek besar.\n\n");

    return 0;
}