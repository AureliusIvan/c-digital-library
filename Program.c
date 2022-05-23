#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define TABLE_SIZE 100000

// bikin tree sesuai abjad judul
typedef struct DataBuku{
    char judulBuku[100]; // sejauh ini paling panjang 71 char
    char penulis[100];
    char tahunTerbit[5];
    char ISBN[20];
    char jenisBuku[20];
    int jumlahBuku;
    struct DataBuku *right, *left;
}DataBuku;

DataBuku *root = NULL; 
int counter = 1;

DataBuku *newBookNode(char data[100],char data2[100],char data3[5],char data4[20], char data5[20]){
    DataBuku *temp = (DataBuku*)malloc(sizeof(DataBuku));
    strcpy(temp->judulBuku, data);
    strcpy(temp->penulis, data2);
    strcpy(temp->tahunTerbit, data3);
    strcpy(temp->ISBN, data4);
    strcpy(temp->jenisBuku, data5);
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(DataBuku *goot){
    if(root != NULL){
        inorder(root->left);
        printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter,root->judulBuku, root->penulis, root->tahunTerbit, root->ISBN, root->jenisBuku);
        counter++;
        inorder(root->right);
    }
}

DataBuku *insert(DataBuku *node, char key[100],     
    char a[100],
    char b[5],
    char c[20],
    char d[20]){
    if(node == NULL){
        return newBookNode(key, a,b,c,d);
    }
    if(strcmpi(key, node->judulBuku)<0)
        node->left = insert(node->left, key, a,b,c,d);
    else if(strcmpi(key, node->judulBuku)>0){
        node->right = insert(node->right, key, a,b,c,d);
    }

    return node;
}

typedef struct dataMember {
    char name[45];
    char phoneNum[15];
    char id[10];
    int denda;

    struct dataMember *next;
}dataMember;

typedef struct peminjaman {
    char what[100];
    char who[45];
    int priority;

    struct peminjaman *next, *prev;
}peminjaman;

DataBuku *headBook;
dataMember *headMem = NULL;
peminjaman *headBorrow = NULL;

//Data Peminjaman Buku  - ivan

void searchBuku(DataBuku *root, char key[100]){
    if(root != NULL){
        searchBuku(root->left, key);
        char *ret = strstr(strlwr(root->judulBuku), strlwr(key));
        if(ret){
        printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, root->judulBuku, root->penulis, root->tahunTerbit, root->ISBN, root->jenisBuku);
        counter++;
        }
        searchBuku(root->right, key);
        
    }
}

void displaySearchBuku(){
    char key[100];
    counter = 1;
    printf("\n");
    printf("Masukan Key: ");
    scanf("%s",key);
    searchBuku(root, key);
}

void displayDataPeminjamanBuku(){
    counter = 1;
    printf("================================================================================================================================================================\n");
    printf("|                                                                               Daftar Buku                                                                    |\n");
    printf("================================================================================================================================================================\n");
    printf("| No |                            Judul Buku                                   |           Penulis          |Tahun Terbit|     ISBN     |       Jenis Buku     |\n");
    printf("================================================================================================================================================================\n");
    printf("================================================================================================================================================================\n");
    inorder(root);
    printf("1. Next Page\n");
    printf("2. Previous Page\n");
    printf("0. Back to menu\n");
    printf("Pilihan: ");
    return;
}

void displayBookMenu(){
    while (1){
    char choice;
    printf("1. Cari Buku\n");
    printf("2. Daftar buku \n");
    printf("Pilihan: "); scanf("\n%c", &choice);
    switch (choice){
    case '1':
        displaySearchBuku();
        break;
    case '2':
        displayDataPeminjamanBuku();
    case '0':
        return;
    default:
        break;
    }
    }
}

void defaultPeminjaman() {
    FILE *defaultBorrower = fopen("DataPeminjaman.txt", "r");

    char temp1[50];
    char temp2[50];

    while(!feof(defaultBorrower)) {
        peminjaman *node = (struct peminjaman*) malloc(sizeof(peminjaman));
        peminjaman *curr;

        fscanf (defaultBorrower, "%[^#]#%[^#]#%[^#]#%[^\n]\n", node->who, temp1, node->what, temp2);
        
        node->next = NULL;
        node->prev = NULL;
        curr = headBorrow;

        if (headBorrow == NULL) {
            headBorrow = node;
            headBorrow->prev = NULL;
        }

        else {
            while (curr != NULL && curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
            node->prev = curr;
            node->next = NULL;
        }
    }

    fclose(defaultBorrower);

//Menu Pengembalian Buku
/*
char menuPengembalianBuku(){
    int pilihan;
    printf("\n");
    printf("==========================================================\n");
    printf("                     PENGEMBALIAN BUKU\n");
    printf("==========================================================\n");
    printf("1. Data Buku Yang Dipinjam\n"
           "2. Kembalikan Buku\n"
           "0. Exit\n"
           "Pilihan: "
    );
    scanf("%d", &pilihan);
    fflush(stdin);
    switch (pilihan){
                case 1:
                    system("cls");
                    printf ("=================================================================================================\n");
                    printf ("                                               List Of Member                               \n");
                    printf ("=================================================================================================\n\n");
                    printf ("-------------------------------------------------------------------------------------------------\n"
                            "| No. |                 Name                 |         Judul Buku          |      Priority      |\n"
                            "-------------------------------------------------------------------------------------------------\n"
                    );
                    break;
                case 2:
                    char nama[30];
                    char judul[30];
                    printf("\n");
                    printf("==========================================================\n");
                    printf("                     PENGEMBALIAN BUKU\n");
                    printf("==========================================================\n");
                    printf("Nama            : "); scanf("%[^\n]", &nama);
                    fflush(stdin);
                    printf("Judul Buku      : "); scanf("%[^\n]", &judul);
                    fflush(stdin);
                    printf("%s, %s\n", nama, judul);
                    break;
                case 0:
                    return 0;
                default:
                    printf("hmm");
                    break;
            } 
}
*/


// Cek Member & Title valid ga

DataBuku *searchBookBook (DataBuku *root, char *key){
    if (root == NULL || (strcmpi (root->judulBuku, key) == 0))
        return root;
    
    if (strcmpi (root->judulBuku, key) < 0)
        return searchBookBook(root->right, key);
    
    return searchBookBook(root->left, key);
}

bool checkBook (DataBuku *root, char *key){
    if (root == NULL)
        return false;
    
    if (strcmpi (root->judulBuku, key) == 0)
        return true;
    
    bool res1 = checkBook (root->left, key);
    if (res1) 
        return true;

    bool res2 = checkBook (root->right, key);
    
    return res2;
}

int cekStok(char *judul, DataBuku *root){
    DataBuku *treeRoot = root;

    // kl ada bukunya
    if (checkBook (root, judul)) {
        DataBuku *toCheck = searchBookBook(treeRoot, judul);

        if (toCheck->jumlahBuku == 0) {
            printf ("Stock buku habis!\n");
            return 0;
        }
        else   
            return 1;

    }

    // kl gaada
    else
        printf ("Buku tidak tersedia\n");
}

int checkMember(char *key) {
    dataMember *curr = headMem;

    while (curr != NULL) {
        if (stricmp(curr->name, key) == 0) {
            return 1;
        }
        
        curr = curr->next;
    }
}


void displayPeminjaman() {
    int urutan = 1;
    int pilih;
    peminjaman *curr = headBorrow;
    dataMember *currMem = headMem;
    DataBuku *currBook = root;

    if (headBorrow == NULL) {
        printf ("\nNo Data in Database\n");
        return;
    }

    while (curr != NULL) {
        system("cls");
        printf ("==========================================================\n");
        printf ("                     Data Peminjaman Buku                 \n");
        printf ("==========================================================\n");

        // gabisa prev
        // data kedua, etc ga nampilin informasi orang yang pinjem buku, cuma bukunya

        printf ("\nData - %d\n", urutan);
        while (currMem != NULL) {
            if (strcmpi(currMem->name, curr->who) == 0) {
                printf ("Nama         : %s\n", currMem->name);
                printf ("ID           : %s\n", currMem->id);
                printf ("No. Telp     : %s\n", currMem->phoneNum);
                break;
            }
            currMem = currMem->next;
        }

        DataBuku *toPrint = searchBookBook(currBook, curr->what);
        printf ("Judul Buku   : %s\n", toPrint->judulBuku);
        printf ("ISBN         : %s\n", toPrint->ISBN);
        printf ("Author       : %s\n", toPrint->penulis);
        printf ("Year         : %s\n", toPrint->tahunTerbit);
        printf ("Type         : %s\n", toPrint->jenisBuku);
        
        int pilih;
        printf ("----------------------------------------------------------\n");
        printf("Menu :\n");
        printf("1. Next\n");
        printf("2. Prev\n");
        printf("0. Back to menu\n");
        printf("Pilihan : "); scanf ("%d", &pilih);
        printf("\n");

        switch (pilih) {
            case 1: { //NEXT DATA
                if (curr->next == NULL) {
                    printf ("\nNo more data ahead\n");
                    printf ("Press any key to continue ...\n");
                    getch();
                }
                else {
                    curr = curr->next; 
                    urutan ++;
                }
                system ("cls");
                break;    
            }
            case 2: { //NEXT DATA
                if (curr->prev == NULL) {
                    printf ("\nNo previous data\n");
                    printf ("Press any key to continue ...\n");
                    getch();
                }
                else {
                    curr = curr->prev; 
                    urutan --;
                }
                system ("cls");
                break;    
            }
            default: return;
        }
    }
}

//HASH key

//Menu Turnitin

void menuTurnitin(){
    int pilihan;
    printf("\n");
    printf("==========================================================\n");
    printf("                     TURN IT IN\n");
    printf("==========================================================\n");
    printf("1. Daftar Turn It In\n"
           "2. Cek Queue\n"
           "0. Exit\n"
           "Pilihan: "
    );
    scanf("%d", &pilihan);
    fflush(stdin);
    switch (pilihan){
        case 1:
            break;
        case 2:
            break;
        case 0:
            printf ("\nThank you for using this service ^-^\n\n");
            return;
        default:
            printf("Pilihan salah!");
            break;
    }
    return;
}

//Menu Pengembalian Buku

void returnBook() {
    DataBuku *treeRoot = root;

    char nama[45];
    char judul[100];

    system ("cls");
    printf("\n");
    printf("==========================================================\n");
    printf("                     PENGEMBALIAN BUKU                    \n");
    printf("==========================================================\n");
    fflush(stdin);
    printf("Nama Peminjam   : "); scanf("%[^\n]", nama);
    fflush(stdin);
    printf("Judul Buku      : "); scanf("%[^\n]", judul);
    fflush(stdin);

    //check nama
    if (checkMember(nama) && checkBook(treeRoot, judul)) {
        DataBuku *toRestock = searchBookBook(treeRoot, judul);
        toRestock->jumlahBuku += 1;

        dataMember *currMem = headMem;
        while (currMem != NULL) {
            if (strcmpi(currMem->name, nama) == 0) {
                break;
            }
            currMem = currMem->next;
        }

        FILE *delBorrower = fopen("DataPeminjaman.txt", "w");
        peminjaman *curr = headBorrow;
        while (curr != NULL) {
            fprintf (delBorrower, "%s#%s#%s#%s#hehe\n", currMem->name, currMem->id, toRestock->judulBuku, toRestock->ISBN);
            curr = curr->next;
        }
        fclose(delBorrower);
        printf ("\nPengembalian buku berhasil\n");
    }
    
    else {
        printf ("\nData peminjaman buku tidak tersedia\nSilahkan periksa ulang data");
    }

    printf ("Press any key to continue...");
    getch();
}

void menuPengembalianBuku() {
    int pilihan;
    printf ("\n");
    printf ("==========================================================\n");
    printf ("                     PENGEMBALIAN BUKU                    \n");
    printf ("==========================================================\n");

    returnBook();

    // printf ("1. Data Buku Yang Dipinjam\n"
    //         "2. Kembalikan Buku\n"
    //         "0. Exit\n"
    //         "Pilihan: "
    // );
    // scanf("%d", &pilihan);
    // fflush(stdin);

    // switch (pilihan){
    //     case 1:
    //         system("cls");
    //         printf ("=================================================================================================\n");
    //         printf ("                                           List Peminjam Buku                                    \n");
    //         printf ("=================================================================================================\n\n");
    //         printf ("-------------------------------------------------------------------------------------------------\n"
    //                 "| No. |                 Name                 |                              Judul Buku                             |    ID    |\n"
    //                 "-------------------------------------------------------------------------------------------------\n"
    //         );
    //         break;
    //     case 2:
    //         returnBook();
    //         break;
    //     case 0:
    //         return;
    //     default:
    //         printf("hmm");
    //         break;
    // } 
}

//List Buku - soon 


//Edit Buku - marcel 


void tambahBuku(){
    char choice;
    char judulBuku[100];
    char penulis[100];
    char tahunTerbit[5];
    char ISBN[20];
    char jenisBuku[20];
    int jumlahBuku;
    printf("Masukan Judul Buku: ");
    scanf("%s",judulBuku);
    printf("Masukan Penulis Buku: ");
    scanf("\n%s",penulis);
    printf("Masukan Tahun Terbit: ");
    scanf("\n%s", tahunTerbit);
    printf("Masukan ISBN: ");
    scanf("\n%s", ISBN);
    printf("Masukan Jenis Buku: ");
    scanf("\n%s", jenisBuku);
    printf("Masukan Jumlah Buku: ");
    root = insert(root, judulBuku, penulis, tahunTerbit, ISBN, jenisBuku);
    FILE *data;
    data = fopen("FileBuku.txt", "a");
    fprintf(data,"\n%s#%s#%s#%s#%s",judulBuku,penulis,tahunTerbit, ISBN, jenisBuku);
    fclose(data);
    printf("data berhasil dimasukan!");
    getchar();
    return;
}



void search(DataBuku *cur, char key[100], DataBuku *parent)  
{  
    while (cur != NULL && (strcmp(cur->judulBuku,key)!= 0))  
    {  
        parent = cur;  
        if ((strcmp(cur->judulBuku,key)!= 0)>0)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
}  

  
DataBuku* findMinimum(DataBuku* cur)  {  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  



void deleteNode(DataBuku *root, char key[100] )  
{  
    DataBuku* parent = NULL;  
    DataBuku* cur = root;  
  
    search(cur, key, parent);  
    if (cur == NULL)  
        return;  
    if (cur->left == NULL && cur->right == NULL)  
    {  
        if (cur != root)  
        {  
            if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        DataBuku* succ  = findMinimum(cur->right);  
  
        char val[100];  
        strcpy(val,succ->judulBuku);  
  
        deleteNode(root, succ->judulBuku);  
        strcpy(cur->judulBuku,val);  
    }  
    else  
    {  
        DataBuku* child = (cur->left)? cur->left: cur->right;  
        if (cur != root)  {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
  
        else  
            root = child;  
        free(cur);  
    }  
}  

void hapusBuku(){
    char key[100];
    printf("Judul Buku yang ingin di hapus: ");
    scanf("%s", key);
    deleteNode(root, key);
    printf("Penghapusan Sukses\n");
    return;
}

void editBuku(){
    while (1){
    char choice;
    printf("====== Menu Edit Buku ======\n");
    printf("1. Tambah buku\n");
    printf("2. Hapus buku\n");
    printf("3. Edit info buku\n");
    printf("0. Kembali ke menu utama\n");
    printf("Pilihan: ");
    scanf("\n%c", &choice);
    switch (choice){
    case '1':
        tambahBuku();
        break;
    case '2':
        hapusBuku();
        break;
    case '3':
        break;
    case '0':
        return;
    default:
        break;
    }
    }
}

// Anggota Baru - mae

void defaultMember() {
    FILE *defaultMem = fopen("DataMember.txt", "r");

    while(!feof(defaultMem)) {
        dataMember *node = (struct dataMember*) malloc(sizeof(dataMember));
        dataMember *curr;

        fscanf (defaultMem, "%[^#]#%[^#]#%[^#]#%[^\n]\n", node->name, node->phoneNum, node->id, &node->denda);
        
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
}

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
    node->denda = 0;

    // generate random id
    char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        idT[i] = charset[rand() % 9];
    }
    strcpy (node->id, idT);

    FILE *insertData = fopen("DataMember.txt", "a");
    fprintf (insertData, "%s#%s#%s#%d\n", node->name, node->phoneNum, node->id, node->denda);
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
    printf ("Press any key to continue...");
    getch();
}

void showMember() {
    dataMember *kepala = headMem;
    // dataMember *tail = headMem;
    // while (tail != NULL && tail != NULL) {
    //     tail = tail->next;
    // }

    // quickSort(kepala, tail);
    // quickSort (&kepala);

    system("cls");
    printf ("\n");
    printf ("===========================================================================\n");
    printf ("                              List Of Member                               \n");
    printf ("===========================================================================\n\n");
    printf ("---------------------------------------------------------------------------\n"
            "| No. |                 Name                 |  Phone Number  | ID Number |\n"
            "---------------------------------------------------------------------------\n"
    );

    int count = 1;
    dataMember *curr = headMem;
    while (curr != NULL) {
        // quickSort(curr, 0, total);
        printf ("| %-3d | %-36s | %-14s | %-9s |\n", count, curr->name, curr->phoneNum, curr->id);
        count += 1;
        curr = curr->next;
    }

    printf ("---------------------------------------------------------------------------\n\n");
    printf ("\nPress any key to continue...");
    getch();
}

void searchMember() {
    dataMember *curr = headMem;

    char key[20], *ret;
    printf ("\nInput keyword: "); scanf (" %[^\n]s", key);

    system("cls");
    printf ("\n");
    printf ("===========================================================================\n");
    printf ("                              List Of Member                               \n");
    printf ("===========================================================================\n\n");
    printf ("---------------------------------------------------------------------------\n"
            "| No. |                 Name                 |  Phone Number  | ID Number |\n"
            "---------------------------------------------------------------------------\n"
    );

    int count = 1;
    while (curr != NULL) {
        char *compare; 
        strcpy (compare, curr->name);

        ret = strstr(strlwr(compare), strlwr(key));
        if (ret) {
            printf ("| %-3d | %-36s | %-14s | %-9s |\n", count, curr->name, curr->phoneNum, curr->id);
            count += 1;
        }
        
        curr = curr->next;
    }

    printf ("---------------------------------------------------------------------------\n\n");
    printf ("\nPress any key to continue..."); getch();
    return; //error :)
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
                "3. Search member\n"
                "0. Back to menu\n"
                "Pilihan: "
        );
        scanf ("%d", &choice);

        if (choice < 0 || choice > 3) {
            printf ("Pilihan salah!\n");
            printf ("Press any key to continue...");
            getch();
        }
        else {
            switch (choice) {
                case 0 : return; break;
                case 1 : {
                    inputNew();
                    break;
                }
                case 2 : {
                    showMember();
                    break;
                }
                case 3 : {
                    searchMember();
                    break;
                }
            }
        }
    }
    

}


// Input data peminjaman baru

peminjaman *newBorrower (char *nama, char *judul) {
    peminjaman *node = (peminjaman*) malloc(sizeof(peminjaman));
    peminjaman *curr;
    
    strcpy (node->who, nama);
    strcpy (node->what, judul);

    node->next = NULL;
    node->prev = NULL;
    curr = headBorrow;

    if (headBorrow == NULL) {
        headBorrow = node;
        headBorrow->prev = NULL;
    }

    else {
        while (curr != NULL && curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
        node->prev = curr;
        node->next = NULL;
    }
}

void peekBorrower (peminjaman *curr) {
    dataMember *currMem = headMem;
    DataBuku *treeRoot = root;

    time_t t;
    time(&t);

    system ("cls");
    printf ("==========================================================\n");
    printf ("                   Data Peminjaman Baru                   \n");
    printf ("==========================================================\n");

    printf ("\nWaktu Peminjaman : %s", ctime(&t));
    printf ("----------------------------------------------------------\n");

    while (currMem != NULL) {
        if (strcmpi(currMem->name, curr->who) == 0) {
            printf ("Nama         : %s\n", currMem->name);
            printf ("ID           : %s\n", currMem->id);
            printf ("No. Telp     : %s\n", currMem->phoneNum);
            break;
        }
        currMem = currMem->next;
    }

    DataBuku *toPrint = searchBookBook(treeRoot, curr->what);
    printf ("Judul Buku   : %s\n", toPrint->judulBuku);
    printf ("ISBN         : %s\n", toPrint->ISBN);
    printf ("Author       : %s\n", toPrint->penulis);
    printf ("Year         : %s\n", toPrint->tahunTerbit);
    printf ("Type         : %s\n", toPrint->jenisBuku);
    toPrint->jumlahBuku -= 1;

    FILE *insertBorrow = fopen("DataPeminjaman.txt", "a");
    fprintf (insertBorrow, "%s#%s#%s#%s\n", currMem->name, currMem->id, toPrint->judulBuku, toPrint->ISBN);
    fclose(insertBorrow);
}

void borrowMenu() {
    peminjaman *headBorrow;
    char nama[45], judul[100];
    int pilih;

    system ("cls");
    printf ("==========================================================\n");
    printf ("                          Pinjam Buku                     \n");
    printf ("==========================================================\n");

    //check nama
    printf ("Nama peminjam  : "); scanf (" %[^\n]s", nama);
    if (!checkMember(nama)) {
        while(1) {
            printf ("\nMember tidak ditemukan. Daftar member terlebih dahulu\n");
            printf ("1. Daftar Member\n"
                    "0. Return\n"
                    "Pilihan: "
            );
            scanf ("%d", &pilih);

            if (pilih < 0 || pilih > 1) {
                printf ("Pilihan salah!\nPress any key to continue");
                getch();
            }

            else if (pilih == 0)
                return;
            
            else if (pilih == 1)
                inputNew();
                return;
        }
    }

    else {
        printf ("Judul buku     : "); 
        scanf (" %[^\n]s", judul);

        DataBuku *treeRoot = root;
        
        // if (cekStok(judul, treeRoot)) {
            peminjaman *curr = newBorrower(nama, judul);
            peekBorrower(curr);
;
            printf ("\nData berhasil ditambahkan\n");
        // }

        printf ("Press any key to continue...");
        getch();
    }
}

//
void display1(){
    return;
}

char menu(){//Menu awal
// FILE *dataBUKU;
// DataBuku *node, *curr;
// dataBUKU = fopen("DataBuku.txt", "r");
// while (!feof(dataBUKU)){
// node = (DataBuku*)malloc(sizeof(DataBuku));
// node->next = NULL;
// }
// fclose(dataBUKU);

    char ch;
    int choice;
    // system ("cls");
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
            "7. Turn It In\n"
            "0. Exit\n"
            "Pilihan: "
    );
    scanf("%d", &choice);
    return choice;
}



int main(){//Main
    FILE *dataBUKU;
    DataBuku *node, *curr;
    dataBUKU = fopen("FileBuku.txt", "r");
    while (!feof(dataBUKU)){
        char judulBuku[100];
        char penulis[100];
        char tahunTerbit[5];
        char ISBN[20];
        char jenisBuku[20];
        int jumlahBuku;
        fscanf(dataBUKU, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", judulBuku, penulis, tahunTerbit, ISBN, jenisBuku);
        root = insert(root, judulBuku, penulis, tahunTerbit, ISBN, jenisBuku );
    }
    fclose(dataBUKU);
    defaultMember();
    defaultPeminjaman();

    char ch;
    while (1)
    {
        switch (menu()){
            case 1:
                displayPeminjaman();
                // displayBookMenu();
                break;
            case 2:
                // testDoang();
                borrowMenu();
                break;
            case 3:
                menuPengembalianBuku();
                break;
            case 4:
                displayBookMenu();
                break;
            case 5:
                editBuku();
                break;
            case 6:
                newMemberMenu();
                break;
            case 7:
                menuTurnitin();
                break;
            case 0:
                printf ("\nThank you for using this service ^-^\n\n");
                return 0;
            default:
                printf("Pilihan salah!");
                break;
        } 
    }
return 0;
}