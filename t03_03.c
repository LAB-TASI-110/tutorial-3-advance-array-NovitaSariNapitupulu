// Delimiter: Start of Code (nilai_03.c)
#include <stdio.h> // Diperlukan untuk fungsi input/output standar seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk alokasi memori dinamis (malloc, free)

/**
 * @brief Fungsi untuk membaca nilai integer ke dalam array dan mengakumulasi totalnya.
 * @param n Jumlah nilai yang akan dibaca.
 * @param scores_array Pointer ke array untuk menyimpan nilai yang dibaca.
 * @return Total dari n nilai yang dibaca. Menggunakan long long untuk menghindari overflow.
 *         Mengembalikan -1 jika terjadi error input.
 */
long long read_scores_and_calculate_total(int n, int *scores_array) {
    long long total = 0; // Inisialisasi total dengan long long
    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &scores_array[i]) != 1) {
            // Penanganan error jika input gagal
            return -1; // Menandakan error
        }
        total += scores_array[i];
    }
    return total;
}

/**
 * @brief Fungsi untuk menghitung rata-rata dari total nilai.
 * @param total_sum Jumlah total nilai.
 * @param n Jumlah data.
 * @return Rata-rata sebagai double dengan presisi desimal.
 */
double calculate_average(long long total_sum, int n) {
    if (n == 0) {
        return 0.0; // Menangani edge case jika n adalah 0
    }
    // Lakukan type casting ke double pada total_sum untuk memastikan pembagian floating-point
    return (double)total_sum / n;
}

/**
 * @brief Fungsi untuk menghitung banyaknya nilai yang di atas atau sama dengan rata-rata.
 * @param n Jumlah nilai dalam array.
 * @param scores_array Pointer ke array yang berisi nilai-nilai.
 * @param average Nilai rata-rata untuk dibandingkan.
 * @return Jumlah nilai yang lebih besar dari atau sama dengan rata-rata.
 */
int count_scores_above_average(int n, const int *scores_array, double average) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores_array[i] >= average) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Fungsi untuk menghitung rentang nilai (nilai maksimum - nilai minimum).
 * @param n Jumlah nilai dalam array.
 * @param scores_array Pointer ke array yang berisi nilai-nilai.
 * @return Rentang nilai. Jika n <= 1, mengembalikan 0.
 */
int calculate_range(int n, const int *scores_array) {
    if (n <= 1) { // Jika tidak ada atau hanya satu elemen, rentangnya 0
        return 0;
    }

    int min_val = scores_array[0];
    int max_val = scores_array[0];

    for (int i = 1; i < n; i++) { // Mulai dari elemen kedua
        if (scores_array[i] < min_val) {
            min_val = scores_array[i];
        }
        if (scores_array[i] > max_val) {
            max_val = scores_array[i];
        }
    }
    return max_val - min_val;
}

/**
 * @brief Fungsi utama program. Membaca input, menghitung total, rata-rata, jumlah nilai
 *        di atas atau sama dengan rata-rata, dan rentang nilai, lalu mencetak hasilnya.
 * @return 0 jika program berhasil.
 */
int main(void) {
    int n; // Variabel untuk menyimpan jumlah nilai
    int *scores = NULL; // Pointer untuk array dinamis yang akan menyimpan nilai-nilai

    // Membaca input n
    if (scanf("%d", &n) != 1) {
        return 1; // Exit dengan error code jika input n gagal
    }

    // Penanganan edge case n=0
    if (n == 0) {
        printf("0\n");    // Total
        printf("0.00\n"); // Rata-rata
        printf("0\n");    // Count
        printf("0\n");    // Rentang
        return 0;
    }

    // Alokasi memori dinamis untuk array scores
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori.\n");
        return 1; // Exit dengan error code jika alokasi memori gagal
    }

    // Membaca nilai dan menghitung total
    long long total_sum = read_scores_and_calculate_total(n, scores);
    if (total_sum == -1) { // Jika ada error saat membaca nilai
        free(scores); // Bebaskan memori sebelum keluar
        return 1;
    }

    // Menghitung rata-rata
    double average_val = calculate_average(total_sum, n);

    // Menghitung jumlah nilai di atas atau sama dengan rata-rata
    int above_average_count = count_scores_above_average(n, scores, average_val);

    // Menghitung rentang nilai
    int range_val = calculate_range(n, scores);

    // Mencetak total, rata-rata, count, dan rentang sesuai format yang diminta
    printf("%lld\n", total_sum);
    printf("%.2f\n", average_val);
    printf("%d\n", above_average_count);
    printf("%d\n", range_val);

    // Bebaskan memori yang dialokasikan secara dinamis
    free(scores);
    scores = NULL; // Pastikan pointer di-NULL-kan setelah dibebaskan

    return 0; // Program berhasil dieksekusi
}
// Delimiter: End of Code (nilai_03.c)
