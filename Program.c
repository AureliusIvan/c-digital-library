#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define TABLE_SIZE 100000

typedef struct DataBuku{
    char judulBuku[100];
    char penulis[100];
    char tahunTerbit[5];
    char ISBN[20];
    char jenisBuku[10];
    int jumlahBuku;
}DataBuku;


//Data Peminjaman Buku  - ivan
void displayDataPeminjamanBuku(){
    printf("=============================================================================================================================================\n");
    printf("|                                                                  Daftar Buku                                                              |\n");
    printf("=============================================================================================================================================\n");
    printf("|                       Judul Buku                           |                  Penulis                |Tahun Terbit|    ISBN    |Jenis Buku|\n");
    printf(" A Brief Guide to Superheroes: From Superman to the Avengers\n");
    printf("==========================================================\n");
    printf("");


//Pengembalian Buku - edison

char menuPengembalianBuku(){//Menu Pengembalian Buku
    char pilihan;
    printf("\n");
    printf("==========================================================\n");
    printf("                     PENGEMBALIAN BUKU\n");
    printf("==========================================================\n");
    printf("1. Data Buku Yang Dipinjam\n"
           "2. Kembalikan Buku\n"
           "0. Exit\n"
           "Pilihan: "
    );
    scanf("%c", &pilihan);
    return pilihan;
    switch (pilihan){
                case '1':
                    break;
                case '2':
                    break;
                case '0':
                    return 0;
                default:
                    printf("Pilihan salah!");
                    break;
            } 
}

//List Buku - soon 

//Edit Buku - marcel 

//Anggota Baru - mae

//
void display1(){

    return;
}


//HASH key

//Pengembalian Buku - edison

//List Buku - soon 

//Edit Buku - marcel 

//Anggota Baru - mae

//
void display1(){
    return;
}


//
char menu(){//Menu awal
FILE *dataBUKU;
DataBuku *node, *curr;
dataBUKU = fopen("DataBuku.txt", "r");
while (!feof(dataBUKU)){
node = (DataBuku*)malloc(sizeof(DataBuku));
node->next = NULL;
}
fclose(dataBUKU);
char ch;
    char choice;
    printf("\n");
    printf("==========================================================\n");
    printf("                          MY PERPUS\n");
    printf("==========================================================\n");
    printf("1. Data Peminjaman Buku\n"
           "2. Pinjam Buku\n"
           "3. Pengembalian Buku\n"
           "4. List Data Buku\n"
           "5. Edit Data Buku\n"
           "6. Membership\n"
           "0. Exit\n"
           "Pilihan: "
    );
    scanf("%c", &choice);
    return choice;
}



int main(){//Main

while (1)
{
   switch (menu()){
        case '1':
            displayDataPeminjamanBuku();
            break;
        case '2':
            break;
        case '3':
            menuPengembalianBuku();
            break;
        case '4':
            break;
        case '0':
            return 0;
        default:
            printf("Pilihan salah!");
            break;
    } 
}
    return 0;
}