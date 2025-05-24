#include <stdio.h>

int main() {

    int tabungan = 0;
    char makanan[50], rumah[50], lainnya[50];
    int pilih, sisa;
    int hargaMakanan, hargaRumah, hargaLainnya;
    char kategori[50] = "Belum ada pengeluaran";
    int totalMakanan = 0, totalRumah = 0, totalLainnya = 0;
    int totalPengeluaran = 0;
    int countMakanan = 0, countRumah = 0, countLainnya = 0;

    //ini tampilan paling atas tabungannya//
    printf("==============TABUNGAN=============\n");
    printf("Selamat datang di aplikasi tabungan\n");

    //nah kalo ini bagian input uang tabungannya//
    printf("Masukin uang yang kamu punya yaa\n");
    scanf("%d", &tabungan);
    printf("Uang kamu sekarang ada Rp%d\n", tabungan);

    //Menggunakan do while supaya program bisa diulang//
    do {
        //yang di bawah ini adalah menu utama tabungannya//
        printf("\nKamu lagi mau apa nih?\n");
        printf("1. Makanan\n");
        printf("2. Rumah\n");
        printf("3. Lainnya\n");
        printf("0. Keluar\n");
        printf("Pilih menu yang kamu mau\n");
        scanf("%d", &pilih);

        //kita pakai switch case untuk menu pilihan//
        switch (pilih) {
        case 1:
            //ini adalah pilihan untuk makanan//
            printf("Kamu lagi mau makan apa?\n");
            scanf(" %[^\n]", makanan);
            printf("Emang harganya berapa sih?\n");
            scanf("%d", &hargaMakanan);
            getchar();
            sisa = tabungan - hargaMakanan;
            //kita pakai if else buat ngecek uangnya cukup atau engga//
            if (hargaMakanan <= tabungan) {
                printf("Asikkk, uang kamu cukup, ayo pergi beli %s!\n", makanan);
                tabungan = sisa;
                printf("Uang kamu sekarang sisa Rp%d\n", tabungan);
                totalMakanan += hargaMakanan;
                totalPengeluaran += hargaMakanan;
                countMakanan++;
            } else {
                printf("Yahh uang kamu ga cukup nih\n");
                printf("Soalnya uang kamu cuma Rp%d doang\n", tabungan);
            }
            break; //break menandakan case 1 udah selesai//

        case 2:
            //ini adalah pilihan untuk rumah//
            printf("Kamu mau beli kebutuhan rumah apa?\n");
            scanf(" %[^\n]", rumah);
            printf("Emang harganya berapa sih?\n");
            scanf("%d", &hargaRumah);
            getchar();
            sisa = tabungan - hargaRumah;
            //kita pakai if else buat ngecek uangnya cukup atau engga//
            if (hargaRumah <= tabungan) {
                printf("Asikkk, uang kamu cukup, yuk kita beli %s sekarang!\n", rumah);
                tabungan = sisa;
                printf("Uang kamu sekarang sisa Rp%d\n", tabungan);
                totalRumah += hargaRumah;
                totalPengeluaran += hargaRumah;
                countRumah++;
            } else {
                printf("Yahh uang kamu ga cukup nih\n");
                printf("Soalnya uang kamu cuma Rp%d doang\n", tabungan);
            }
            break; //break menandakan case 2 udah selesai//

        case 3:
            //ini adalah pilihan untuk keinginan kamu lainnya/
            printf("Kamu mau beli apa?\n");
            scanf(" %[^\n]", lainnya);
            printf("Harganya berapa sih?\n");
            scanf("%d", &hargaLainnya);
            getchar();
            sisa = tabungan - hargaLainnya;
            //kita pakai if else buat ngecek uangnya cukup atau engga//
            if (hargaLainnya <= tabungan) {
                printf("Asikkk, uang kamu cukup, yuk kita cari %s sekarang!\n", lainnya);
                tabungan = sisa;
                printf("Uang kamu sekarang sisa Rp%d\n", tabungan);
                totalLainnya += hargaLainnya;
                totalPengeluaran += hargaLainnya;
                countLainnya++;
            } else {
                printf("Yahh uang kamu ga cukup nih\n");
                printf("Soalnya uang kamu cuma Rp%d doang\n", tabungan);
            }
            break; //break menandakan case 3 udah selesai//

        case 0:
            //oh iya, case 0 ini diapakai untuk keluar dari program lhoo//
            printf("Terima kasih sudah menggunakan aplikasi ini!\n");
            break;

        default:
            //kamu cuma boleh pilih angka 0-3 aja, kalo selain itu ga boleh yaa//
            printf("Pilihan kamu ga valid, coba lagi gih\n");
            break;
        }
    } while (pilih != 0); //selagi kamu ga pilih 0, maka while ini bakalan terus jalan//

//nah untuk ngecek kategori pengeluaran paling sering, kita pakai conditional statement//
//count juga dipakai buat ngitung seberapa banyak menu atau kategori yang kita pilih//
//kalo sprintf dipake buat nyimpen teks ke dalam sebuah string//

int max = countMakanan;
    if (countRumah > max) {
        max = countRumah;
    } 
    if (countLainnya > max) {
        max = countLainnya;
    }

if (max == 0) {
        sprintf(kategori, "Kamu belum ada pengeluaran nih, uang kamu masih utuh");
    } else {
        kategori[0] = '\0'; // reset string kosong
        int pertama = 1;

        if (countMakanan == max) {
            sprintf(kategori, "%s%s", kategori, "Makanan");
            pertama = 0;
        }
        if (countRumah == max) {
            sprintf(kategori, "%s%s%s", kategori, pertama ? "" : ", ", "Rumah");
            pertama = 0;
        }
        if (countLainnya == max) {
            sprintf(kategori, "%s%s%s", kategori, pertama ? "" : ", ", "Lainnya");
        }
    }
    
// Nah ini buat nampilin rangkuman pengeluaran kamu//
// Di sinni kita juga pakai if else apabila pilihnya langsung//
if (totalPengeluaran == 0) {
    printf("\nKamu belum beli apapun nih, uang kamu masih utuh, yaitu sebesar Rp%d\n", tabungan);
} else {
    printf("\n==== Ringkasan Pengeluaran Kamu ====\n");
    printf("Pengeluaran kamu saat ini sebesar Rp%d\n", totalPengeluaran);
    printf("Dan kamu paling banyak ngabisin uang di %s\n", kategori);
    printf("Sisa uang kamu sekarang tinggal Rp%d, yuk semangat nabung lagi!\n", tabungan);
}
}