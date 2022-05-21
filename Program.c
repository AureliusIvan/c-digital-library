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
    struct DataBuku *next, *prev;
}DataBuku;


DataBuku *head;

//Data Peminjaman Buku  - ivan
void displayDataPeminjamanBuku(){
    DataBuku *curr;
    curr = head;
    int counter = 1;
    printf("================================================================================================================================================================\n");
    printf("|                                                                               Daftar Buku                                                                    |\n");
    printf("================================================================================================================================================================\n");
    printf("| No |                            Judul Buku                                   |           Penulis          |Tahun Terbit|     ISBN     |       Jenis Buku     |\n");
    printf("================================================================================================================================================================\n");
    while (curr->next != NULL){
        printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, curr->judulBuku, curr->penulis, curr->tahunTerbit, curr->ISBN, curr->jenisBuku);
        curr = curr->next;
        counter++;
    }
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
           "6. Membership\n"
           "0. Exit\n"
           "Pilihan: "
    );
    scanf("%c", &choice);
    return choice;
}



int main(){//Main
FILE *dataBUKU;
DataBuku *node, *curr;
dataBUKU = fopen("FileBuku.txt", "r");
while (!feof(dataBUKU)){
node = (DataBuku*)malloc(sizeof(DataBuku));
node->next = NULL;
fscanf(dataBUKU, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", node->judulBuku, node->penulis, node->tahunTerbit, node->ISBN, node->jenisBuku);
curr = head;
if(head == NULL){
        head = node;
    }
    else{
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
        node->prev = curr;
    }
}
fclose(dataBUKU);
char ch;
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
        case '0':
            return 0;
        default:
            printf("Pilihan salah!");
            break;
    } 
}
    return 0;
}