#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


void display1(){
    return;
}



char menu(){//Menu awal
    char choice;
    printf("\n");
    printf("==========================================================\n");
    printf("                          MY PERPUS\n");
    printf("==========================================================\n");
    printf("1. Peminjaman\n"
           "2. Cari Buku\n"
           "3. Edit Data\n"
           "4. Tambah Keanggotaan\n"
           "5. Exit\n"
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
        default:
            break;
    } 
}
    return 0;
}