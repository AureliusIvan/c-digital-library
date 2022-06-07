#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

int counter = 1;
// bikin tree sesuai abjad judul
typedef struct DataBuku
{
    char judulBuku[100]; // sejauh ini paling panjang 71 char
    char penulis[100];
    char tahunTerbit[5];
    char ISBN[20];
    char jenisBuku[20];
    int jumlahBuku;
    struct DataBuku *right, *left;
} DataBuku;

typedef struct dataMember
{
    char name[45];
    char phoneNum[15];
    char id[10];
    int denda;

    struct dataMember *next, *prev;
} dataMember;

typedef struct peminjaman
{
    char what[100];
    char who[45];
    int priority;

    struct peminjaman *next, *prev;
} peminjaman;

DataBuku *root = NULL;
DataBuku *headBook;
dataMember *headMem = NULL;
peminjaman *headBorrow = NULL;
int countbookamount;
///////

DataBuku *newBookNode(char data[100], char data2[100], char data3[5], char data4[20], char data5[20], int data6)
{
    DataBuku *temp = (DataBuku *)malloc(sizeof(DataBuku));
    strcpy(temp->judulBuku, data);
    strcpy(temp->penulis, data2);
    strcpy(temp->tahunTerbit, data3);
    strcpy(temp->ISBN, data4);
    strcpy(temp->jenisBuku, data5);
    temp->jumlahBuku = data6;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(DataBuku *root, int upperpagging, int lowerpagging)
{
    if (root != NULL)
    {
        
        inorder(root->left, upperpagging, lowerpagging);
        if (counter <= upperpagging && counter >= lowerpagging)
        {
            printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, root->judulBuku, root->penulis, root->tahunTerbit, root->ISBN, root->jenisBuku);
        }
        counter++;
        inorder(root->right, upperpagging, lowerpagging);
    }
}

DataBuku *insert(DataBuku *node, char key[100],
                 char a[100],
                 char b[5],
                 char c[20],
                 char d[20],
                 int e)
{
    if (node == NULL)
    {
        return newBookNode(key, a, b, c, d, e);
    }
    if (strcmpi(key, node->judulBuku) < 0)
        node->left = insert(node->left, key, a, b, c, d, e);
    else if (strcmpi(key, node->judulBuku) > 0)
    {
        node->right = insert(node->right, key, a, b, c, d, e);
    }

    return node;
}

// Data Peminjaman Buku  - ivan

void searchBuku(DataBuku *root, char key[100])
{
    if (root != NULL)
    {
        searchBuku(root->left, key);
        char *ret = strstr(strlwr(root->judulBuku), strlwr(key));
        if (ret)
        {
            printf("|%-4d|%-73s|%-28s|%-12s|%-14s|%-22s|\n", counter, root->judulBuku, root->penulis, root->tahunTerbit, root->ISBN, root->jenisBuku);
            counter++;
        }
        searchBuku(root->right, key);
    }
}

void displaySearchBuku()
{
    char key[100];
    counter = 1;
    printf("\n");
    printf("Masukan Keyword Judul: ");
    scanf("\n%s", key);
    searchBuku(root, key);
    getch();
}

void displayDataPeminjamanBuku()
{
    counter = 1;
    int upperpagging = 50;
    int lowerpagging = 0;
    char choice;
    while (1)
    {
        printf(" _______    __    __ __     ____   _    __   ___  _       |  * | _______   __       _____ __   _ ___      ___ _ __   _    _      \n"
               "||  __  |__|  |  /  |  |__ | || |-| |__|  | |   |||       |  * |||  __  |_|  |__   /  / /|  |_| |   |__ _|   | |  | | |__| |      \n"
               "|| |__| |  |  | / / |  |  || || | | |  |  |-|   |||       |  * ||| |__| | |  |  | /  / / |  | | |   |  | |   | |  |-| |  | |     \n"
               "||      |  |  |/ /  |  |  ||    | | |  |  | |   |||       |  * |||      | |  |  |/  / /  |  | | |   |  | |   | |  | | |  | |     \n"
               "||______|  |  |_/   |  |  ||    | | |  |  | |   |||____   |  * |||      | |  |  |__/_/   |  | | |   |  | |   | |  | | |  | |     \n");
        printf("================================================================================================================================================================\n");
        printf("|                                                                               Daftar Buku                                                                    |\n");
        printf("================================================================================================================================================================\n");
        printf("| No |                            Judul Buku                                   |           Penulis          |Tahun Terbit|     ISBN     |       Jenis Buku     |\n");
        printf("================================================================================================================================================================\n");
        inorder(root, upperpagging, lowerpagging);
        printf("================================================================================================================================================================\n");
        printf("\n");
        printf("MENU \n");
        printf("1. Prev\n");
        printf("2. Next\n");
        printf("0. Back\n");
        printf("Pilihan: ");
        scanf("\n%c", &choice);
        switch (choice)
        {
        case '1':
            counter = 0;
            upperpagging = upperpagging - 50;
            if (upperpagging < 50)
            {
                upperpagging = 50;
            }
            lowerpagging = upperpagging - 50;
        case '2':
            counter = 0;
            lowerpagging = lowerpagging + 50;
            if (lowerpagging < 0)
            {
                lowerpagging = 0;
            }
            upperpagging = upperpagging + 50;
            if (upperpagging > countbookamount)
            {
                upperpagging = countbookamount;
            }
        default:
            break;
        }
    }
}

void displayBookMenu()
{
    while (1)
    {
        system("cls");
        char choice;
        printf("\n");
        printf("=============================\n");
        printf("    Menu List Data Buku \n");
        printf("=============================\n");
        printf("1. Cari Buku\n");
        printf("2. Daftar buku \n");
        printf("Pilihan: ");
        scanf("\n%c", &choice);
        switch (choice)
        {
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

void defaultPeminjaman()
{
    FILE *defaultBorrower = fopen("DataPeminjaman.txt", "r");

    char temp1[50];
    char temp2[50];

    while (!feof(defaultBorrower))
    {
        peminjaman *node = (struct peminjaman *)malloc(sizeof(peminjaman));
        peminjaman *curr;

        fscanf(defaultBorrower, "%[^#]#%[^#]#%[^#]#%[^\n]\n", node->who, temp1, node->what, temp2);

        node->next = NULL;
        node->prev = NULL;
        curr = headBorrow;

        if (headBorrow == NULL)
        {
            headBorrow = node;
            headBorrow->prev = NULL;
        }

        else
        {
            while (curr != NULL && curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = node;
            node->prev = curr;
            node->next = NULL;
        }
    }

    fclose(defaultBorrower);
}

// Cek Member & Title valid ga

DataBuku *searchBookBook(DataBuku *root, char *key)
{
    if (root == NULL || (strcmpi(root->judulBuku, key) == 0))
        return root;

    if (strcmpi(root->judulBuku, key) < 0)
        return searchBookBook(root->right, key);

    return searchBookBook(root->left, key);
}

bool checkBook(DataBuku *root, char *key)
{
    if (root == NULL)
        return false;

    if (strcmpi(root->judulBuku, key) == 0)
        return true;

    bool res1 = checkBook(root->left, key);
    if (res1)
        return true;

    bool res2 = checkBook(root->right, key);

    return res2;
}

int cekStok(char *judul, DataBuku *root)
{
    DataBuku *treeRoot = root;

    // kl ada bukunya
    if (checkBook(root, judul))
    {
        DataBuku *toCheck = searchBookBook(treeRoot, judul);

        if (toCheck->jumlahBuku == 0)
        {
            printf("Stock buku habis!\n");
            return 0;
        }
        else
            return 1;
    }

    // kl gaada
    else
        printf("Buku tidak tersedia\n");
}

int checkMember(char *key)
{
    dataMember *curr = headMem;

    while (curr != NULL)
    {
        if (stricmp(curr->name, key) == 0)
        {
            return 1;
        }

        curr = curr->next;
    }
}

void displayPeminjaman()
{
    int urutan = 1;
    int pilih;
    peminjaman *curr = headBorrow;
    dataMember *currMem = headMem;
    DataBuku *currBook = root;

    if (headBorrow == NULL)
    {
        printf("\nNo Data in Database\n");
        getch();
        return;
    }

    while (curr != NULL)
    {
        system("cls");
        printf("    ___________                                 \n"
               "    |___________|            ________________    \n"
               "   (____________)           |    PLEASE    |    \n"
               "  |______________|___       |  RETURN IT   |    \n"
               "   [_________________]__    |   ON TIME!   |    \n"
               "  |_____________________|   |______________|    \n"
               " (______________________)          ||           \n");
        printf("==========================================================\n");
        printf("                     Data Peminjaman Buku                 \n");
        printf("==========================================================\n");

        // gabisa prev
        // data kedua, etc ga nampilin informasi orang yang pinjem buku, cuma bukunya

        printf("\nData - %d\n", urutan);
        while (currMem != NULL)
        {
            if (strcmpi(currMem->name, curr->who) == 0)
            {
                printf("Nama         : %s\n", currMem->name);
                printf("ID           : %s\n", currMem->id);
                printf("No. Telp     : %s\n", currMem->phoneNum);
                break;
            }
            currMem = currMem->next;
        }

        DataBuku *toPrint = searchBookBook(currBook, curr->what);
        printf("Judul Buku   : %s\n", toPrint->judulBuku);
        printf("ISBN         : %s\n", toPrint->ISBN);
        printf("Author       : %s\n", toPrint->penulis);
        printf("Year         : %s\n", toPrint->tahunTerbit);
        printf("Type         : %s\n", toPrint->jenisBuku);

        int pilih;
        printf("----------------------------------------------------------\n");
        printf("Menu :\n");
        printf("1. Next\n");
        printf("2. Prev\n");
        printf("0. Back to menu\n");
        printf("Pilihan : ");
        scanf("\n%d", &pilih);
        printf("\n");

        switch (pilih)
        {
        case 1:
        { // NEXT DATA
            if (curr->next == NULL)
            {
                printf("\nNo more data ahead\n");
                printf("Press any key to continue ...\n");
                getch();
            }
            else
            {
                curr = curr->next;
                urutan++;
            }
            system("cls");
            break;
        }
        case 2:
        { // NEXT DATA
            if (curr->prev == NULL)
            {
                printf("\nNo previous data\n");
                printf("Press any key to continue ...\n");
                getch();
            }
            else
            {
                curr = curr->prev;
                urutan--;
            }
            system("cls");
            break;
        }
        default:
            return;
        }
    }
}

void inputNew()
{
    char idT[10]; // yg dipake cuma 8

    dataMember *curr;
    dataMember *node = (struct dataMember *)malloc(sizeof(dataMember));

    system("cls");
    printf("\n");
    printf("==========================================================\n");
    printf("             _________________________\n"
           "            |  _____                  | \n"
           "            | |  O  |   New Member__  | \n"
           "            | |__n__|   ____________  | \n"
           "            |                         | \n"
           "            |  *****                  | \n"
           "            |_________________________| \n");
    printf("==========================================================\n");

    printf("Nama           : ");
    scanf("\n%[^\n]s", node->name);
    printf("Phone number   : ");
    scanf("\n%[^\n]s", node->phoneNum);
    node->denda = 0;

    // generate random id
    char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        idT[i] = charset[rand() % 9];
    }
    strcpy(node->id, idT);

    FILE *insertData = fopen("DataMember.txt", "a");
    fprintf(insertData, "%s#%s#%s#%d\n", node->name, node->phoneNum, node->id, node->denda);
    fclose(insertData);

    node->next = NULL;
    curr = headMem;

    while (curr != NULL && curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;

    // // check
    // printf ("Check nama     : %s\n", node->name);
    // printf ("Check no.telp  : %s\n", node->phoneNum);
    // printf ("Check ID       : %s", node->id);
    // printf ("\n");

    printf("\nData berhasil ditambahkan\n");
    printf("Press any key to continue...");
    getch();
}

// HASH key

// Menu Turnitin
typedef struct data
{
    char nama[45];
    char topik[100];
    struct data *next;
} DATA;

DATA *headQueue;

void dequeue()
{
    if (headQueue != NULL)
    {
        DATA *hapus = headQueue;
        printf("test");
        headQueue = (headQueue)->next;
        free(hapus);
    }
    else
    {
        printf("data masih kosong\n");
        getch();
    }
    return;
}

void checkQueueTurnitin()
{
    system("cls");
    char choice, persentage[3];
    char charset[] = "0123456789";
    printf("===============================\n");
    printf("Antrian Paling depan Sekarang:\n");
    printf("===============================\n");
    if (headQueue != NULL)
    {
        printf("Nama: %s\n", headQueue->nama);
        printf("Topik: %s\n", headQueue->topik);
    }
    else
    {
        printf("Antrian sekarang kosong\n");
        printf("Press anything to continue....\n");
        getchar();
        return;
    }
    printf("-----------------------------------\n");
    printf("1. Pindai Plagiarasime Sekarang \n");
    printf("0. Keluar\n");
    scanf("%c", choice);
    switch (choice)
    {
    case '1':
        dequeue();
        break;
    case '2':
        return;
    default:
        break;
    }
}
void enqueue(DATA **tail, DATA peminjam)
{
    DATA *node = (DATA *)malloc(sizeof(DATA));
    strcpy(node->nama, peminjam.nama);
    strcpy(node->topik, peminjam.topik);
    node->next = NULL;
    if (headQueue == NULL)
        headQueue = node;
    else
        (*tail)->next = node;
    *tail = node;
    return;
}

void daftarTurnitin(DATA **head, DATA **tail)
{
    DATA peminjam;
    char nama[45], topik[100];
    int pilih;
    fflush(stdin);
    printf("Nama Peminjam   : ");
    scanf("%[^\n]", nama);
    fflush(stdin);
    if (!checkMember(nama))
    {
        while (1)
        {
            printf("\nMember tidak ditemukan. Daftar member terlebih dahulu\n");
            printf("1. Daftar Member\n"
                   "0. Return\n"
                   "Pilihan: ");
            scanf("%d", &pilih);

            if (pilih < 0 || pilih > 1)
            {
                printf("Pilihan salah!\nPress any key to continue");
                getch();
            }

            else if (pilih == 0)
                return;

            else if (pilih == 1)
                inputNew();
            return;
        }
    }
    else
    {
        fflush(stdin);
        printf("Topik            : ");
        scanf("%[^\n]", topik);
        strcpy(peminjam.nama, nama);
        strcpy(peminjam.topik, topik);
        enqueue(tail, peminjam);
    }
}

void menuTurnitin()
{
    system("cls");
    DATA *head, *tail;
    head = tail = NULL;
    int pilihan;
    system("cls");
    printf("\n");
    printf("   ______________________                              \n"
           "    | ___                |                             \n"
           "    |  ________________  |       ______   _____        \n"
           "    |  ________________  |  /   |      | |     |       \n"
           "    |  ________________  | <    |      | |     | () /  \n"
           "    |  ________________  |       ______  |     |   /   \n"
           "    |  ________________  |      |      | |     |  / () \n"
           "    |  ________________  |      |      | |     |       \n"
           "    |___________________ |       ______   _____        \n");
    printf("==========================================================\n");
    printf("                          TURNITIN\n");
    printf("==========================================================\n");
    printf("1. Daftar Turnitin\n"
           "2. Cek Queue\n"
           "3. Pindai Plagiarisme\n"
           "0. Exit\n"
           "Pilihan: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    switch (pilihan)
    {
    case 1:
        daftarTurnitin(&head, &tail);
        break;
    case 2:
        checkQueueTurnitin();
        break;
    case 3:
        dequeue();
        printf("Berhasil Pindai Plagiarisme!\n");
        break;
    case 0:
        printf("\nThank you for using this service ^-^\n\n");
        return;
    default:
        printf("Pilihan salah!");
        break;
    }
    return;
}

/* int isempty(DATA *head){
   if(head == NULL) return 1;
   else return 0;
}
DATA front(DATA *head){
    return head; //HEAD !ISEMPTY
} */
// Menu Pengembalian Buku

void returnBook()
{
    DataBuku *treeRoot = root;
    char nama[45];
    char judul[100];

    system("cls");
    printf("\n");
    printf(" ______________________                                         \n"
           "|  __________________  |                 ___________            \n"
           "| |    ---           | |  /   ___   _   |___________|           \n"
           "| | O  ____________  | | <   |   |_| | (____________)           \n"
           "| | n  ____________  | |     |   | | ||______________|___       \n"
           "| |__________________| |     |   | | |[_________________]__     \n"
           "|______________________|     |   | | |_____________________|    \n"
           "           |||               |   | | (______________________)__ \n"
           "          _|||_              |   | | |________________________| \n ");
    printf("==========================================================\n");
    printf("                     PENGEMBALIAN BUKU                    \n");
    printf("==========================================================\n");
    fflush(stdin);

    printf("Nama Peminjam   : ");
    scanf("%[^\n]", nama);
    fflush(stdin);
    printf("Judul Buku      : ");
    scanf("%[^\n]", judul);
    fflush(stdin);

    // check nama
    if (checkMember(nama) && checkBook(treeRoot, judul))
    {
        DataBuku *toRestock = searchBookBook(treeRoot, judul);
        toRestock->jumlahBuku += 1;

        dataMember *currMem = headMem;
        while (currMem != NULL)
        {
            if (strcmpi(currMem->name, nama) == 0)
            {
                free(currMem);
                break;
            }
            currMem = currMem->next;
        }

        FILE *delBorrower = fopen("DataPeminjaman.txt", "a");
        peminjaman *curr = headBorrow;
        while (curr != NULL)
        {
            fprintf(delBorrower, "%s#%s#%s#%s\n", currMem->name, currMem->id, toRestock->judulBuku, toRestock->ISBN);
            curr = curr->next;
        }
        fclose(delBorrower);
        free(currMem);
        printf("%s", currMem->name);
        printf("\nPengembalian buku berhasil\n");
    }

    else
    {
        printf("\nData peminjaman buku tidak tersedia\nSilahkan periksa ulang data");
    }

    printf("Press any key to continue...");
    getch();
}

void menuPengembalianBuku()
{
    int pilihan;
    printf("\n");
    printf(" ______________________                                         \n"
           "|  __________________  |                 ___________            \n"
           "| |    ---           | |  /   ___   _   |___________|           \n"
           "| | O  ____________  | | <   |   |_| | (____________)           \n"
           "| | n  ____________  | |     |   | | ||______________|___       \n"
           "| |__________________| |     |   | | |[_________________]__     \n"
           "|______________________|     |   | | |_____________________|    \n"
           "           |||               |   | | (______________________)__ \n"
           "          _|||_              |   | | |________________________| \n ");
    printf("==========================================================\n");
    printf("                     PENGEMBALIAN BUKU                    \n");
    printf("==========================================================\n");

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

// List Buku - soon

// Edit Buku - marcel

void tambahBuku()
{
    char choice;
    char judulBuku[100];
    char penulis[100];
    char tahunTerbit[5];
    char ISBN[20];
    char jenisBuku[20];
    int jumlahBuku;

    system("cls");
    printf("               ___________               \n"
           "    ___   _   |___________|              \n"
           "   |   |_| | (____________)              \n"
           "   |   | | ||______________|___          \n"
           "   |   | | |[_________________]__       \n"
           "   |   | | |_____________________|      \n"
           "   |   | | (______________________)     \n");
    printf("==========================================================\n");
    printf("                       Menu Edit Buku                     \n");
    printf("==========================================================\n");

    printf("Masukan Judul Buku      : ");
    scanf(" %[^\n]", judulBuku);
    printf("Masukan Penulis Buku    : ");
    scanf(" %[^\n]", penulis);
    printf("Masukan Tahun Terbit    : ");
    scanf(" %[^\n]", tahunTerbit);
    printf("Masukan ISBN            : ");
    scanf(" %[^\n]", ISBN);
    printf("Masukan Jenis Buku      : ");
    scanf(" %[^\n]", jenisBuku);
    printf("Masukan Jumlah Buku     : ");
    scanf("%d", &jumlahBuku);

    root = insert(root, judulBuku, penulis, tahunTerbit, ISBN, jenisBuku, jumlahBuku);

    FILE *data;
    data = fopen("FileBuku.txt", "a");
    fprintf(data, "%s#%s#%s#%s#%s#%d\n", judulBuku, penulis, tahunTerbit, ISBN, jenisBuku, jumlahBuku);
    fclose(data);

    printf("Data berhasil dimasukan!\n");
    printf("Press any key to continue\n");
    getchar();
    return;
}

void search(DataBuku *cur, char key[100], DataBuku *parent)
{
    while (cur != NULL && (strcmp(cur->judulBuku, key) != 0))
    {
        parent = cur;
        if ((strcmp(cur->judulBuku, key) != 0) > 0)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

DataBuku *findMinimum(DataBuku *cur)
{
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

void deleteNode(DataBuku *root, char key[100])
{
    DataBuku *parent = NULL;
    DataBuku *cur = root;

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
        DataBuku *succ = findMinimum(cur->right);

        char val[100];
        strcpy(val, succ->judulBuku);

        deleteNode(root, succ->judulBuku);
        strcpy(cur->judulBuku, val);
    }
    else
    {
        DataBuku *child = (cur->left) ? cur->left : cur->right;
        if (cur != root)
        {
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

// beda cara delete yg 2 di bawah ini
DataBuku *successor(DataBuku *node)
{
    DataBuku *curr = node;

    // cari anak paling kiri
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;

    return curr;
}

DataBuku *delete (DataBuku *treeRoot, char *key)
{
    if (strcmpi(key, treeRoot->judulBuku) < 0)
        treeRoot->left = delete (treeRoot->left, key);

    else if (strcmpi(key, treeRoot->judulBuku) > 0)
        treeRoot->left = delete (treeRoot->left, key);

    else
    {
        if (treeRoot->left == NULL)
        {
            DataBuku *temp = treeRoot->right;
            free(treeRoot);
            return temp;
        }
        else if (treeRoot->right == NULL)
        {
            DataBuku *temp = treeRoot->left;
            free(treeRoot);
            return temp;
        }

        // jika node memiliki 2 anak
        DataBuku *temp = successor(treeRoot->right);

        // letakan inorder successornya di posisi node yang bakal di delete

        strcpy(treeRoot->judulBuku, temp->judulBuku);
        strcpy(treeRoot->penulis, temp->penulis);
        strcpy(treeRoot->tahunTerbit, temp->tahunTerbit);
        strcpy(treeRoot->ISBN, temp->ISBN);
        strcpy(treeRoot->jenisBuku, temp->jenisBuku);
        treeRoot->jumlahBuku = temp->jumlahBuku;

        treeRoot->right = delete (treeRoot->right, temp->judulBuku);
    }
    return treeRoot;
}

void hapusBuku()
{
    char key[100];

    system("cls");
    printf("               ___________               \n"
           "    ___   _   |___________|              \n"
           "   |   |_| | (____________)              \n"
           "   |   | | ||______________|___          \n"
           "   |   | | |[_________________]__       \n"
           "   |   | | |_____________________|      \n"
           "   |   | | (______________________)     \n");
    printf("==========================================================\n");
    printf("                         Hapus Buku                       \n");
    printf("==========================================================\n");
    printf("Judul Buku : ");
    scanf(" %[^\n]", key);

    DataBuku *treeRoot = root;
    DataBuku *temp = searchBookBook(treeRoot, key);

    if (temp != NULL)
    {
        root = delete (treeRoot, key);
        displayDataPeminjamanBuku(root);
        printf("\n\nPenghapusan Sukses\n");
    }
    else
    {
        printf("Data buku tidak ditemukan\n");
    }

    // deleteNode(root, key);
    getch();
    return;
}

void editBuku()
{
    while (1)
    {
        char choice;

        system("cls");
        printf("               ___________               \n"
               "    ___   _   |___________|              \n"
               "   |   |_| | (____________)              \n"
               "   |   | | ||______________|___          \n"
               "   |   | | |[_________________]__       \n"
               "   |   | | |_____________________|      \n"
               "   |   | | (______________________)     \n");
        printf("==========================================================\n");
        printf("                       Menu Edit Buku                     \n");
        printf("==========================================================\n");
        printf("1. Tambah buku\n");
        printf("2. Hapus buku\n");
        printf("0. Back to menu\n");
        printf("Pilihan: ");
        scanf("\n%c", &choice);
        switch (choice)
        {
        case '1':
            tambahBuku();
            break;
        case '2':
            hapusBuku();
            break;
        case '0':
            return;
        default:
            break;
        }
    }
}

// Anggota Baru - mae

void defaultMember()
{
    FILE *defaultMem = fopen("DataMember.txt", "r");

    while (!feof(defaultMem))
    {
        dataMember *node = (struct dataMember *)malloc(sizeof(dataMember));
        dataMember *curr;

        fscanf(defaultMem, "%[^#]#%[^#]#%[^#]#%[^\n]\n", node->name, node->phoneNum, node->id, &node->denda);

        node->next = NULL;
        curr = headMem;

        if (headMem == NULL)
        {
            headMem = node;
        }

        else
        {
            while (curr != NULL && curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = node;
            node->prev = curr;
        }
    }

    fclose(defaultMem);
}

void showMember()
{
    dataMember *kepala = headMem;
    // dataMember *tail = headMem;
    // while (tail != NULL && tail != NULL) {
    //     tail = tail->next;
    // }

    // quickSort(kepala, tail);
    // quickSort (&kepala);

    system("cls");
    printf("\n");
    printf("    ______________________                                   \n"
           "   |  __________________  |     _________________________    \n"
           "   | |    ---           | |  / |  _____                  |   \n"
           "   | | O  ____________  | | <  | |  O  |   ____________  |   \n"
           "   | | n  ____________  | |    | |__n__|   ____________  |   \n"
           "   | |__________________| |    |                         |   \n"
           "   |______________________|    |  *****                  |   \n"
           "             |||               |_________________________|   \n"
           "            _|||_                                            \n ");
    printf("===========================================================================\n");
    printf("                              List Of Member                               \n");
    printf("===========================================================================\n\n");
    printf("---------------------------------------------------------------------------\n"
           "| No. |                 Name                 |  Phone Number  | ID Number |\n"
           "---------------------------------------------------------------------------\n");

    int count = 1;
    dataMember *curr = headMem;
    while (curr != NULL)
    {
        // quickSort(curr, 0, total);
        printf("| %-3d | %-36s | %-14s | %-9s |\n", count, curr->name, curr->phoneNum, curr->id);
        count += 1;
        curr = curr->next;
    }

    printf("---------------------------------------------------------------------------\n\n");
    printf("\nPress any key to continue...");
    getch();
}

void searchMember()
{
    dataMember *curr = headMem;
    char key[45], *ret;
    printf("\nInput keyword: ");
    scanf(" %[^\n]s", key);
    system("cls");
    printf("\n");
    printf("    ______________________                                   \n"
           "   |  __________________  |     _________________________    \n"
           "   | |    ---           | |  / |  _____                  |   \n"
           "   | | O  ____________  | | <  | |  O  |   ____________  |   \n"
           "   | | n  ____________  | |    | |__n__|   ____________  |   \n"
           "   | |__________________| |    |                         |   \n"
           "   |______________________|    |  *****                  |   \n"
           "             |||               |_________________________|   \n"
           "            _|||_                                            \n ");
    printf("===========================================================================\n");
    printf("                              List Of Member                               \n");
    printf("===========================================================================\n\n");
    printf("---------------------------------------------------------------------------\n"
           "| No. |                 Name                 |  Phone Number  | ID Number |\n"
           "---------------------------------------------------------------------------\n");

    int count = 1;
    while (curr != NULL)
    {
        char compare[45];
        strcpy(compare, curr->name);

        ret = strstr(strlwr(compare), strlwr(key));
        if (ret)
        {
            printf("| %-3d | %-36s | %-14s | %-9s |\n", count, curr->name, curr->phoneNum, curr->id);
            count += 1;
        }

        curr = curr->next;
    }

    printf("---------------------------------------------------------------------------\n\n");
    // printf ("\nPress any key to continue...");
    // getch();
    return; // error :)
}

void newMemberMenu()
{
    int choice;

    while (1)
    {
        system("cls");
        printf("\n");
        printf("    ______________________                                   \n"
               "   |  __________________  |     _________________________    \n"
               "   | |    ---           | |  / |  _____                  |   \n"
               "   | | O  ____________  | | <  | |  O  |   ____________  |   \n"
               "   | | n  ____________  | |    | |__n__|   ____________  |   \n"
               "   | |__________________| |    |                         |   \n"
               "   |______________________|    |  *****                  |   \n"
               "             |||               |_________________________|   \n"
               "            _|||_                                            \n ");
        printf("==========================================================\n");
        printf("                         New Member                       \n");
        printf("==========================================================\n");
        printf("1. Input new member\n"
               "2. Show member list\n"
               "3. Search member\n"
               "0. Back to menu\n"
               "Pilihan: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 3)
        {
            printf("Pilihan salah!\n");
            printf("Press any key to continue...");
            getch();
        }
        else
        {
            switch (choice)
            {
            case 0:
                return;
                break;
            case 1:
            {
                inputNew();
                break;
            }
            case 2:
            {
                showMember();
                break;
            }
            case 3:
            {
                searchMember();
                printf("Press any key to continue...");
                getch();
                break;
            }
            }
        }
    }
}

// Input data peminjaman baru

peminjaman *newBorrower(char *nama, char *judul)
{
    peminjaman *node = (peminjaman *)malloc(sizeof(peminjaman));
    peminjaman *curr;

    strcpy(node->who, nama);
    strcpy(node->what, judul);

    node->next = NULL;
    node->prev = NULL;
    curr = headBorrow;

    if (headBorrow == NULL)
    {
        headBorrow = node;
        headBorrow->prev = NULL;
    }

    else
    {
        while (curr != NULL && curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = node;
        node->prev = curr;
        node->next = NULL;
    }
}

void peekBorrower(peminjaman *curr)
{
    dataMember *currMem = headMem;
    DataBuku *treeRoot = root;

    time_t t;
    time(&t);

    system("cls");
    printf("    ___________                                 \n"
           "   |___________|            ________________    \n"
           "   (____________)           |    PLEASE    |    \n"
           "  |______________|___       |  RETURN IT   |    \n"
           "   [_________________]__    |   ON TIME!   |    \n"
           "  |_____________________|   |______________|    \n"
           " (______________________)          ||           \n");
    printf("==========================================================\n");
    printf("                   Data Peminjaman Baru                   \n");
    printf("==========================================================\n");

    printf("\nWaktu Peminjaman : %s", ctime(&t));
    printf("----------------------------------------------------------\n");

    while (currMem != NULL)
    {
        if (strcmpi(currMem->name, curr->who) == 0)
        {
            printf("Nama         : %s\n", currMem->name);
            printf("ID           : %s\n", currMem->id);
            printf("No. Telp     : %s\n", currMem->phoneNum);
            break;
        }
        currMem = currMem->next;
    }

    DataBuku *toPrint = searchBookBook(treeRoot, curr->what);
    printf("Judul Buku   : %s\n", toPrint->judulBuku);
    printf("ISBN         : %s\n", toPrint->ISBN);
    printf("Author       : %s\n", toPrint->penulis);
    printf("Year         : %s\n", toPrint->tahunTerbit);
    printf("Type         : %s\n", toPrint->jenisBuku);
    toPrint->jumlahBuku -= 1;

    FILE *insertBorrow = fopen("DataPeminjaman.txt", "a");
    fprintf(insertBorrow, "%s#%s#%s#%s\n", currMem->name, currMem->id, toPrint->judulBuku, toPrint->ISBN);
    fclose(insertBorrow);
    return;
}

void borrowMenu()
{
    peminjaman *headBorrow;
    char nama[45], judul[100];
    char pilih;

    system("cls");
    printf("    ___________                                 \n"
           "   |___________|            ________________    \n"
           "   (____________)           |    PLEASE    |    \n"
           "  |______________|___       |  RETURN IT   |    \n"
           "   [_________________]__    |   ON TIME!   |    \n"
           "  |_____________________|   |______________|    \n"
           " (______________________)          ||           \n");
    printf("==========================================================\n");
    printf("                          Pinjam Buku                     \n");
    printf("==========================================================\n");

    // check nama
    printf("Nama peminjam  : ");
    scanf(" %[^\n]s", nama);

    if (!checkMember(nama))
    {
        printf("\nMember tidak ditemukan. Silhkan daftarkan member terlebih dahulu\n");
        printf("Mungkin maksud anda : \n");
        printf("---------------------------------------------------------------------------\n");
        while (1)
        {
            dataMember *curr = headMem;
            char *ret;
            int count = 1;
            while (curr != NULL)
            {
                char compare[45];
                strcpy(compare, curr->name);

                ret = strstr(strlwr(compare), strlwr(nama));
                if (ret)
                {
                    printf("| %-3d | %-36s | %-14s | %-9s |\n", count, curr->name, curr->phoneNum, curr->id);
                    count += 1;
                }

                curr = curr->next;
            }
            printf("---------------------------------------------------------------------------\n");
            printf("1. Daftar Member\n"
                   "2. Cari Lagi\n"
                   "0. Return\n"
                   "Pilihan: ");
            scanf("\n%c", &pilih);
            switch (pilih)
            {
            case '1':
                inputNew();
                break;
            case '2':
                break;
            case '0':
                return;
            default:
                break;
            }
        }
    }

    else
    {
        printf("Judul buku     : ");
        scanf(" %[^\n]s", judul);

        DataBuku *treeRoot = root;

        // if (cekStok(judul, treeRoot)) {
        peminjaman *curr = newBorrower(nama, judul);
        peekBorrower(curr);
        ;
        printf("\nData berhasil ditambahkan\n");
        // }

        printf("Press any key to continue...");
        getch();
    }
}

//
void display1()
{
    return;
}

char menu()
{
    char ch;
    int choice;
    system("cls");
    printf("\n");
    time_t t;
    time(&t);
    printf("-----------------------------------------------------------\n");
    printf("   Waktu Sistem : %s", ctime(&t));
    printf("-----------------------------------------------------------\n");
    printf(" _______    __       __     ____   _    __   ___  _      \n"
           "||  __  |__|  |  /- |  |__ | || |-| |__|  | |   |||      \n"
           "|| |__| |  |  | / / |  |  || || | | |  |  |-|   |||      \n"
           "||      |  |  |/ /  |  |  || *  | | |  |  | |   |||      \n"
           "||______|  |  |_/   |  |  || *  | | |  |  | |   |||____  \n");
    printf("==========================================================\n");
    printf("                        MY PERPUS\n");
    printf("==========================================================\n");
    printf("1. Pinjam Buku\n"
           "2. Pengembalian Buku\n"
           "3. Data Peminjaman Buku\n"
           "4. List Data Buku\n"
           "5. Edit Data Buku\n"
           "6. Membership\n"
           "7. Turnitin\n"
           "0. Exit\n"
           "Pilihan: ");
    scanf("%c", &choice);
    return choice;
}

int main()
{ // Main
    countbookamount = 0;
    FILE *dataBUKU;
    DataBuku *node, *curr;
    dataBUKU = fopen("FileBuku.txt", "r");
    while (!feof(dataBUKU))
    {
        char judulBuku[100];
        char penulis[100];
        char tahunTerbit[5];
        char ISBN[20];
        char jenisBuku[20];
        int jumlahBuku;
        fscanf(dataBUKU, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", judulBuku, penulis, tahunTerbit, ISBN, jenisBuku, &jumlahBuku);
        root = insert(root, judulBuku, penulis, tahunTerbit, ISBN, jenisBuku, jumlahBuku);
        countbookamount++;
    }
    fclose(dataBUKU);
    defaultMember();
    // defaultPeminjaman();

    char ch;
    while (1)
    {
        switch (menu())
        {
        case '1':
            borrowMenu();
            break;
        case '2':
            menuPengembalianBuku();
            break;
        case '3':
            displayPeminjaman();
            break;
        case '4':
            displayBookMenu();
            break;
        case '5':
            editBuku();
            break;
        case '6':
            newMemberMenu();
            break;
        case '7':
            menuTurnitin();
            break;
        case '0':
            printf("\nThank you for using this service ^-^\n\n");
            return 0;
        default:
            printf("Pilihan salah!");
            break;
        }
    }
    return 0;
}