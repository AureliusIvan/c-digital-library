#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <time.h>

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

    return;
}


//HASH key

//Pengembalian Buku - edison

//List Buku - soon 

//Edit Buku - marcel 

//Anggota Baru - mae

char name[50];
char phoneNum[15];
char id[10]; // yg dipake cuma 8

void inputNew() {
    system("cls");
    
    printf("\n");
    printf("==========================================================\n");
    printf("                      Input New Member                    \n");
    printf("==========================================================\n");
    printf ("Nama           : "); scanf ("\n%[^\n]s", name);
    printf ("Phone number   : "); scanf ("\n%[^\n]s", phoneNum);

    // generate random id
    char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        id[i] = charset[rand() % 9];
    }

    // // check
    // printf ("Check nama     : %s\n", name);
    // printf ("Check no.telp  : %s\n", phoneNum);
    // printf ("Check ID       : ");
    // for (int i = 0; i < 8; i++) {
    //     printf ("%c", id[i]);
    // }
    // printf ("\n");

    printf ("\nData berhasil ditambahkan\n");
}

void showMember() {
    system("cls");
    printf ("\n");
    printf ("======================================================================\n");
    printf ("                           List Of Member                             \n");
    printf ("======================================================================\n\n");
    printf ("----------------------------------------------------------------------\n"
            "|                 Name                 | ID Number |   Phone Number  |\n"
            "----------------------------------------------------------------------\n"
    );

    // while (...) {
    //     printf ("| -36%s | -9%c | -15%c |\n", name, id, phoneNum);
    // }

    printf ("| %-36s | %-9s | %-15s |\n", name, id, phoneNum);
    printf ("----------------------------------------------------------------------\n\n");
}

void newMemberMenu() {
    int choice;

    while(1) {
        system("cls");
        printf("\n");
        printf("==========================================================\n");
        printf("                         New Member                       \n");
        printf("==========================================================\n");
        printf ("1. Input new member\n"
                "2. Show member list\n"
                "0. Back to menu\n"
                "Pilihan: "
        );
        scanf ("%d", &choice);

        if (choice < 0 || choice > 2) {
            printf ("Pilihan salah!\n");
            printf ("Press any key to continue...");
            getch();
        }
        else {
            switch (choice) {
                case 0 : return; break;
                case 1 : {
                    inputNew();
                    printf ("Press any key to continue...");
                    getch();
                    break;
                }
                case 2 : {
                    // fungsi show list menu
                    showMember();
                    printf ("Press any key to continue...");
                    getch();
                    break;
                }
            }
        }
    }
    

}

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


//Main
int main(){
while (1)
{
    switch (menu()){
        case '1':
            displayDataPeminjamanBuku();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            newMemberMenu();
            break;
        case '0':
            printf ("\nThank you for using this service ^-^\n\n");
            return 0;
        default:
            printf("Pilihan salah!");
            break;
    } 
}
    return 0;
}