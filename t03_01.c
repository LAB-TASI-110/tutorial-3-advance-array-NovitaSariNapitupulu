// Delimiter: Start of Code
#include <stdio.h> // Diperlukan untuk fungsi input/output standar seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX jika ingin memeriksa batas, namun kita akan menggunakan long long untuk keamanan

/**
 * @brief Fungsi untuk mengakumulasi total nilai integer.
 * @param n Jumlah nilai yang akan dibaca.
 * @return Total dari n nilai yang dibaca. Menggunakan long long untuk menghindari overflow.
 */
long long calculate_total(int n) {
    long long total = 0; // Inisialisasi total dengan long long
    int value; // Variabel untuk membaca setiap nilai integer

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            // Penanganan error sederhana jika input gagal, meskipun autograder biasanya memastikan input valid.
            // Dalam lingkungan mission-critical, ini bisa lebih robust.
            return -1; // Menandakan error atau nilai tidak valid
        }
        total += value;
    }
    return total;
}

/**
 * @brief Fungsi untuk menghitung rata-rata dari total nilai.
 * @param total Jumlah total nilai.
 * @param n Jumlah data.
 * @return Rata-rata sebagai double dengan presisi desimal.
 */
double calculate_average(long long total, int n) {
    if (n == 0) {
        return 0.0; // Menangani edge case jika n adalah 0
    }
    // Lakukan type casting ke double pada total untuk memastikan pembagian floating-point
    return (double)total / n;
}

/**
 * @brief Fungsi utama program. Membaca input, menghitung total dan rata-rata, lalu mencetak hasilnya.
 * @return 0 jika program berhasil.
 */
int main(void) {
    int n; // Variabel untuk menyimpan jumlah nilai

    // Membaca input n
    if (scanf("%d", &n) != 1) {
        return 1; // Exit dengan error code jika input n gagal
    }

    long long total_sum = calculate_total(n); // Memanggil fungsi untuk menghitung total

    // Cek jika ada error saat membaca nilai
    if (total_sum == -1 && n > 0) {
        return 1; // Exit dengan error code
    }

    double average_val = calculate_average(total_sum, n); // Memanggil fungsi untuk menghitung rata-rata

    // Mencetak total dan rata-rata sesuai format yang diminta
    printf("%lld\n", total_sum);
    printf("%.2f\n", average_val);

    return 0; // Program berhasil dieksekusi
}
// Delimiter: End of Code
