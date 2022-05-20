#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


//Data Peminjaman Buku  - ivan

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
}

//List Buku - soon 

//Edit Buku - marcel 

//Anggota Baru - mae

//
void display1(){
    return;
}



char menu(){//Menu awal
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
           "6. Membership"
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
            break;
        case '2':
            break;
        case '3':
            switch (menuPengembalianBuku()){
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