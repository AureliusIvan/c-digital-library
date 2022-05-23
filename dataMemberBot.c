#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    char phoneNum[15]; // 13 digit aja
    char id[10]; // 8 digit

    while (1) {
        printf ("Nama : "); scanf ("\n%[^\n]s", name);

        char charset[] = "0123456789";
        srand(time(NULL));

        phoneNum[0] = '0';
        phoneNum[1] = '8';

        for (int i = 2; i < 13; i++) {
            phoneNum[i] = charset[rand() % 9];
        }

        for (int i = 0; i < 8; i++) {
            id[i] = charset[rand() % 9];
        }

        // printf ("%s#%s#%s\n", name, phoneNum, id);

        FILE *insertData = fopen("DataMember.txt", "a");
        fprintf (insertData, "%s#%s#%s#0\n", name, phoneNum, id);
        fclose(insertData);
    }

    // stop with ctrl + c
}