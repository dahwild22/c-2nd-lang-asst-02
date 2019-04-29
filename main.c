#include <stdio.h>
#include <stdlib.h>

// creating node strucutre
struct node {
    int data;
    struct node *next;
};

// adds new node to singly linked lists
void addNode(struct node **head, int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = value;
    newNode->next = *head;
    *head = newNode;
}

//delete_list (scans for value and deletes that node which contains the parameter)
void delete_list(struct node **head, int value) {

    struct node* tNode = *head, *prev;

    if (tNode != NULL && tNode->data == value) {
        *head = tNode->next;
        free(tNode);
        return;
    }

    while (tNode != NULL && tNode->data != value) {
        prev = tNode;
        tNode = tNode->next;
    }

    prev->next = tNode->next;

    free(tNode);
}

void traverseAndPrint(struct node *temp){

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}


int main() {
    struct node* n;

    addNode(&n, 4);
    addNode(&n, 3);
    addNode(&n, 2);
    addNode(&n, 1);
    addNode(&n, 0);

    traverseAndPrint(n);
    delete_list(&n, 2);
    printf("\n");
    traverseAndPrint(n);
    return 0;
}
