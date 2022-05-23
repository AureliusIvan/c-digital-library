#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

#define TABLE_SIZE 100000

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

void inorder(DataBuku *root){
    if(root != NULL){
        inorder(root->left);
        printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, root->judulBuku, root->penulis, root->tahunTerbit, root->ISBN, root->jenisBuku);
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

    struct peminjaman *next;
}peminjaman;

DataBuku *headBook;
dataMember *headMem = NULL;

//Data Peminjaman Buku  - ivan



void searchBuku(){
    char key[100];
    printf("Buku di tengah: %s", root->judulBuku);
}


void displayDataPeminjamanBuku(){
    int counter = 1;
    printf("================================================================================================================================================================\n");
    printf("|                                                                               Daftar Buku                                                                    |\n");
    printf("================================================================================================================================================================\n");
    printf("| No |                            Judul Buku                                   |           Penulis          |Tahun Terbit|     ISBN     |       Jenis Buku     |\n");
    printf("================================================================================================================================================================\n");
    printf("================================================================================================================================================================\n");
    inorder(root);
    printf("1. Next Page\n");
    printf("2. Previous Page\n");
    printf("0. Back\n");
    printf("Pilihan: ");
    return;
}


void displayBookMenu(){
    while (1){
    char choice;
    printf("1. Cari Buku\n");
    printf("2. Daftar buku \n");
    printf("Pilihan: "); scanf("%c", &choice);
    switch (choice){
    case '1':
        searchBuku();
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

//HASH key

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
void printListBuku(){
    DataBuku *node;
    int counter = 0;
    node = headBook;
        
    printf("================================================================================================================================================================\n");
    printf("|                                                                               Daftar Buku                                                                    |\n");
    printf("================================================================================================================================================================\n");
    printf("| No |                            Judul Buku                                   |           Penulis          |Tahun Terbit|     ISBN     |       Jenis Buku     |\n");
    printf("================================================================================================================================================================\n");
    do{
        printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, node->judulBuku, node->penulis, node->tahunTerbit, node->ISBN, node->jenisBuku);   
        node = node->next;
    }
    while(node->judulBuku != NULL);
    return;
}
//Cek Stok Buku

int cekStok(char judul){
    DataBuku *node;
    do{
        if(node->judulBuku == judul){
            break;
        }
        node = node->next;
    }
    while(node->judulBuku != NULL);
    if (node->jumlahBuku == 0){
        printf("Stock Buku Habis!");
        return 0;
    } else if(node->jumlahBuku > 0){
        return 1;
    }
}

//Edit Buku - marcel 

void editBuku(){
    FILE* bukuBaru = NULL;
    FILE* buku = NULL;

    DataBuku *data;

    int i, count = 0;
    int n;
    int k;

    printf("====== Menu Edit Buku ======\n");
    printf("1. Tambah buku\n");
    printf("2. Hapus buku\n");
    printf("3. Edit info buku\n");
    printf("0. Kembali ke menu utama\n");
    printf("Pilihan: ");
    scanf("%d", &n);

    if (n == 1)
    {
        buku = fopen("FileBuku.txt", "r");
        bukuBaru = fopen("FileBuku.txt", "a");

    while (1)
    {
        count++; 
        printf("Masukkan judul buku         :  ");
        scanf(" %s", data[i].judulBuku); 
        printf("Masukkan nama author        :  ");
        scanf(" %s", data[i].penulis); 
        printf("Masukkan tahun terbit buku  :  ");
        scanf("%s", data[i].tahunTerbit); 
        printf("Masukkan ISBN buku          :  ");
        scanf("%s", data[i].ISBN); 
        printf("Masukkan tipe buku          :  ");   
        scanf("%s", data[i].jenisBuku); 

        fprintf(bukuBaru, "%s#%s#%s#%s#%s\n", 
                    data[i].judulBuku, data[i].penulis, data[i].tahunTerbit,
                    data[i].ISBN, data[i].jenisBuku
                    );
    }

            fclose(bukuBaru);
            fclose(buku);

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
    dataMember *curr = headMem;

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


// QUEUE (+ PRIORITY)

int checkMember(char *key) {
    dataMember *curr = headMem;

    while (curr != NULL) {
        if (strcmpi(curr->name, key) == 0) {
            system ("cls");
            printf ("==========================================================\n");
            printf ("                          Pinjam Buku                     \n");
            printf ("==========================================================\n");
            printf ("Nama peminjam  : %s\n", curr->name);
            return 1;
        }
        
        curr = curr->next;
    }
}

peminjaman *newBorrower (char *nama, char *judul, int prior) {
    peminjaman *node = (peminjaman*) malloc(sizeof(peminjaman));
    
    strcpy (node->who, nama);
    strcpy (node->what, judul);
    node->priority = prior;
    node->next = NULL;

    return node;
}

void enqueueNewBorrower (peminjaman **headBorrow, char *nama, char *judul, int prior) {
    peminjaman *start = (*headBorrow);

    //create new node
    peminjaman* node = newBorrower(nama, judul, prior);

    // Jika priority head lebih kecil dibanding new node,
    // insert node sebelum head, terus ganti head nodenya
    if ((*headBorrow)->priority > prior) {
        // insert node sebelum head
        node->next = *headBorrow;
        (*headBorrow) = node;
    }
    else {
        while (start->next != NULL && start->next->priority < prior) {
            start = start->next;
        }

        node->next = start->next;
        start->next = node;
    }
}

void dequeueBorrower (peminjaman **headBorrow) {
    peminjaman *temp = *headBorrow;
    (*headBorrow) = (*headBorrow)->next;
    free(temp);
}

void peekBorrower (peminjaman *headBorrow) {
    dataMember *currMem = headMem;
    DataBuku *currBook = headBook;

    printf ("-----------------------------------------------------------\n");

    while (currMem != NULL) {
        if (strcmpi(currMem->name, headBorrow->who) == 0) {
            printf ("\nNama         : %s\n", currMem->name);
            printf ("ID           : %s\n", currMem->id);
            printf ("No. Telp     : %s\n", currMem->phoneNum);
            break;
        }
        currMem = currMem->next;
    }

    while (currBook != NULL) {
        if (strcmpi(currBook->judulBuku, headBorrow->what) == 0) {
            printf ("\nJudul Buku   : %s\n", currBook->judulBuku);
            printf ("ISBN         : %s\n", currBook->ISBN);
            printf ("Author       : %s\n", currBook->penulis);
            printf ("Year         : %s\n", currBook->tahunTerbit);
            printf ("Type         : %s\n", currBook->jenisBuku);
            break;
        }
        //currBook = currBook->next;
    }

    // cari curr di database Member dan Book yg sama kyk nama and judul buku
    printf ("Priority           : %d\n", headBorrow->priority);
}

int isEmptyBorrower (peminjaman **headBorrow) {
    if(*headBorrow == NULL) 
        return 1;
    else 
        return 0;
}

void borrowMenu(int borrower) {
    peminjaman *headBorrow;
    char nama[45], judul[100];
    int pilih, prior;

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
        // belom bikin algoritma utk nge-check apakah bukunya ada ato ga (nantinya kl tersedia, perlu liat stock juga)
        printf ("Judul buku     : "); 
        scanf (" %[^\n]s", judul);

        // if jenis bukunya ... -> priority nya berapa, nanti tentuinnya otomatis
        // tapi sementara dibikin manual dulu
        printf ("Priority       : ");
        scanf ("%d", &prior);

        cekStok(judul);

        if (borrower == 0) {
            headBorrow = newBorrower(nama, judul, prior);
        }
        else {
            enqueueNewBorrower(&headBorrow, nama, judul, prior);
        }

        // data bisa masuk, tapi kalo di print dia langsung ilang lagi
        // harusnya nanti kalo udah ada yg balikin baru di dequeue (?)
        peminjaman *curr = headBorrow;
        while (!isEmptyBorrower(&curr)) {
            peekBorrower(curr);
            dequeueBorrower(&curr);
        }

        borrower = 1;
        printf ("\nData berhasil ditambahkan\n");
        printf ("Press any key to continue...");
        getch();
    }
    // kl ada
    // kl ini data pertama, head = newNode(nama, judul);
    // kl bukan data pertama, langsung enqueue (&head, nama, judul);


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
    char choice;
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
            "0. Exit\n"
            "Pilihan: "
    );
    scanf("%c", &choice);
    return choice;
}



//test doang
void testDoang(){
    int count = 1;
    while (1)
    {
        printf("%d",count);
        sleep(1);
        system("cls");
        count++;
    }
    
    printf("");
    return;
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
    int borrower = 0;

    char ch;
    while (1)
    {
        switch (menu()){
            case '1':
                displayBookMenu();
                break;
            case '2':
                // testDoang();
                borrowMenu(borrower);
                break;
            case '3':
                menuPengembalianBuku();
                break;
            case '4':
                printListBuku();
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
return 0;
}