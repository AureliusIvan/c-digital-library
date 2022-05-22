#include <stdio.h>
#include <stdlib.h>

typedef struct lendingList {
    int data;
    int priority;

    struct lendingList* next;
} lendingList;

// create new node
lendingList* newNode (int d, int p) {
    lendingList* temp = (lendingList*) malloc(sizeof(lendingList));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// return value at head
void peek (lendingList** head) {
    printf  ("number: %d     priority: %d\n", (*head)->data, (*head)->priority);
}

// remove element with the highest priority from the list 
// (makin kecil angkanya, prioritasnya lebih tinggi)
void pop (lendingList** head) {
    lendingList *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push (lendingList** head, int d, int p) {
    lendingList* start = (*head);

    //create new node
    lendingList* temp = newNode(d, p);

    // Jika priority head lebih kecil dibanding new node,
    // insert node sebelum head, terus ganti head nodenya
    if ((*head)->priority > p) {
        // insert node sebelum head
        temp->next = *head;
        (*head) = temp;
    }
    else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty (lendingList** head) {
    return (*head) == NULL;
}

int main() {
    lendingList *head;
    int d, p;

    for (int i = 0; i < 3; i++) {
        printf ("Data       : "); scanf ("%d", &d);
        printf ("Priority   : "); scanf ("%d", &p);

        if (i == 0) {
            head = newNode(d, p);
        }
        else {
            push (&head, d, p);
        }
    }


    while (!isEmpty(&head)) {
        peek(&head);
        pop(&head);
    }

    return 0;
}