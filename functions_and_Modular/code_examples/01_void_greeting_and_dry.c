/*
 * File: 01_void_greeting_and_dry.c
 * Week: 05 - Functions & Modular Programming
 * Description: Demonstrasi fungsi void dan fungsi kalkulasi nilai berprinsip DRY
 *
 * Learning Points:
 * - Anatomi fungsi: return type, nama fungsi, parameter, body
 * - Perbedaan fungsi void (prosedur) vs fungsi ber-return value
 * - Prinsip DRY: jangan tulis ulang logika yang sama lebih dari 2 kali
 * - return statement menghentikan eksekusi fungsi seketika
 *
 * Compile:
 *   gcc 01_void_greeting_and_dry.c -o 01_void_greeting_and_dry
 *   .\01_void_greeting_and_dry.exe
 *
 * Attribution:
 * - Materi Hari 1 Minggu 05 LABS (Pengenalan Fungsi & Anatomi Dasar).
 *
 * Integrity Statement:
 * Contoh resmi instruktur untuk demonstrasi kelas.
 */

#include <stdio.h>

// ============================================================
// FUNGSI VOID: mencetak garis pembatas dekoratif
// Tidak mengembalikan nilai, murni menjalankan aksi cetak
// ============================================================
void cetak_garis(void) {
    printf("----------------------------------------\n");
}

// ============================================================
// FUNGSI VOID: mencetak header aplikasi kartu siswa
// Memanggil fungsi cetak_garis() sebanyak 2 kali (DRY!)
// ============================================================
void cetak_header(void) {
    cetak_garis();
    printf("     PORTAL AKADEMIK SMA LABS 2026      \n");
    cetak_garis();
}

// ============================================================
// FUNGSI BER-RETURN VALUE int
// Rumus: (Teori * 40%) + (Praktikum * 60%)
// Parameter formal: nilai_teori, nilai_praktikum
// ============================================================
int hitung_nilai_akhir(int nilai_teori, int nilai_praktikum) {
    int skor_akhir = (nilai_teori * 40 / 100) + (nilai_praktikum * 60 / 100);
    return skor_akhir;
}

// ============================================================
// FUNGSI VOID: mencetak laporan nilai satu siswa
// ============================================================
void cetak_laporan(int id_siswa, int teori, int praktikum, int akhir) {
    printf("Siswa %d -> Teori: %d | Prak: %d | Akhir: %d\n", id_siswa, teori, praktikum, akhir);
}

int main() {
    // Memanggil fungsi void untuk header
    cetak_header();

    // --------------------------------------------------------
    // PROSES SISWA 1: Data di dalam variabel lokal main()
    // --------------------------------------------------------
    int teori1 = 80;
    int prak1 = 90;
    int akhir1 = hitung_nilai_akhir(teori1, prak1);
    cetak_laporan(1, teori1, prak1, akhir1);

    // --------------------------------------------------------
    // PROSES SISWA 2: Logika perhitungan TIDAK ditulis ulang!
    // Cukup panggil fungsi hitung_nilai_akhir() dengan argumen berbeda
    // --------------------------------------------------------
    int teori2 = 70;
    int prak2 = 65;
    int akhir2 = hitung_nilai_akhir(teori2, prak2);
    cetak_laporan(2, teori2, prak2, akhir2);

    // --------------------------------------------------------
    // PROSES SISWA 3: Demonstrasi nilai kritis
    // --------------------------------------------------------
    int teori3 = 50;
    int prak3 = 45;
    int akhir3 = hitung_nilai_akhir(teori3, prak3);
    cetak_laporan(3, teori3, prak3, akhir3);

    cetak_garis();
    printf("Status: 3 data siswa berhasil diproses via fungsi.\n");
    printf("Prinsip DRY: rumus & layout cetak tidak ditulis ulang!\n");

    return 0;
}
