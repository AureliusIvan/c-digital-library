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

void editBuku(){
    FILE* buku;
    FILE* bukuBaru;

    DataBuku *data;

    int i, count = 0;
    int n;
    int k;

    buku = fopen("FileBuku.txt", "r");

    printf("====== Menu Edit Buku ======");
    printf("1. Tambah buku\n");
    printf("2. Hapus buku\n");
    printf("3. Edit info buku\n");
    printf("0. Kembali ke menu utama\n");
    printf("Pilihan: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("Masukkan jumlah buku yang ingin ditambahkan   :  ");
        scanf("%d", &k);

        for (i = 0; i < k; i++)
        {
            printf("Masukkan judul buku              :  \n");
            scanf("%s", data[i].judulBuku);
            printf("Masukkan nama author             :  \n");
            scanf("%s", data[i].penulis);
            printf("Masukkan tahun terbit buku       :  \n");
            scanf("%s", data[i].tahunTerbit);
            printf("Masukkan ISBN buku               :  \n");
            scanf("%s", data[i].ISBN);
            printf("Masukkan tipe buku               :  \n");   
            scanf("%s", data[i].jenisBuku);

            bukuBaru = fopen("FileBuku.txt", "a");


            // fprintf(bukuBaru, "%s#%s#%s#%s#%s", );

            fclose(bukuBaru);
            fclose(buku);
        }
        
      

    }
    else if(n == 2)
    {
        char judul[100];
        int i, j;

        DataBuku *temp;

        printf("Masukkan judul buku yang ingin dihapus: ");
        scanf("%c", judul);

        for (i = 0; i < count; i++)
        {
            if (strcmp(data[i].judulBuku, judul)==0)
            {
                system("cls");
                printf("\nBuku dengan judul %s akan dihapus.", data[i].judulBuku);
                for (j = i; j < count - 1; j++)
                    data = data+1;

                    count--;
                    return;
            }
            
        }
        
    }
    else if(n == 3)
    {

    }
}


// //Anggota Baru - mae

typedef struct dataMember {
    char name[45];
    char phoneNum[15];
    char id[10];

    struct dataMember *next;
}dataMember;

// masih global, nanti pindahin aja
dataMember *headMem = NULL;

void inputNew() {
    char idT[10]; // yg dipake cuma 8

    dataMember *curr;
    dataMember *node = (struct dataMember*) malloc(sizeof(dataMember));
    
    system("cls"); printf("\n");
    printf("==========================================================\n");
    printf("                      Input New Member                    \n");
    printf("==========================================================\n");
    
    printf ("Nama           : "); 
    scanf ("\n%[^\n]s", node->name);
    printf ("Phone number   : "); 
    scanf ("\n%[^\n]s", node->phoneNum); 

    // generate random id
    char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        idT[i] = charset[rand() % 9];
    }
    strcpy (node->id, idT);

    FILE *insertData = fopen("DataMember.txt", "a");
    fprintf (insertData, "%s#%s#%s\n", node->name, node->phoneNum, node->id);
    fclose(insertData);

    node->next = NULL;
    curr = headMem;

    while (curr != NULL && curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;

    // // check
    // printf ("Check nama     : %s\n", node->name);
    // printf ("Check no.telp  : %s\n", node->phoneNum);
    // printf ("Check ID       : %s", node->id);
    // printf ("\n");

    printf ("\nData berhasil ditambahkan\n");
}

void showMember() {
    dataMember *curr = headMem;

    system("cls");
    printf ("\n");
    printf ("=====================================================================\n");
    printf ("                           List Of Member                            \n");
    printf ("=====================================================================\n\n");
    printf ("---------------------------------------------------------------------\n"
            "|                 Name                 | ID Number |  Phone Number  |\n"
            "---------------------------------------------------------------------\n"
    );

    FILE *defaultMem = fopen("DataMember.txt", "r");

    while(!feof(defaultMem)) {
        dataMember *node = (struct dataMember*) malloc(sizeof(dataMember));
        dataMember *curr;

        fscanf (defaultMem, "%[^#]#%[^#]#%[^\n]\n", node->name, node->phoneNum, node->id);
        printf ("| %-36s | %-9s | %-14s |\n", node->name, node->id, node->phoneNum);
        
        node->next = NULL;
        curr = headMem;

        if (headMem == NULL) {
            headMem = node;
        }
        else {
            while (curr != NULL && curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    fclose(defaultMem);
    printf ("---------------------------------------------------------------------\n\n");
}

void newMemberMenu() {
    // defaultMember();
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
            // displayDataPeminjamanBuku();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            editBuku();
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
}