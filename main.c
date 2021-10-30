#include <stdio.h>
#include <stdlib.h>


struct DoublyList {
    struct DoublyList* next;
    struct DoublyList* prev;
    int data;

};

struct DoublyList *head, *tail= NULL;



void addNodeAtTail(int data){
    struct DoublyList* newNode = (struct DoublyList*)malloc(sizeof(struct DoublyList));
    newNode->data = data;

    if (head == NULL) {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;

    } else {

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
    }
}



void addNodeAtHead(int data){
    struct DoublyList* newNode = (struct DoublyList*)malloc(sizeof(struct DoublyList));
    newNode->data = data;

    if (head == NULL) {
        head = tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;


    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;
    }

}


void printNode () {
    struct DoublyList *temp = head;

    if (head == NULL){
        printf("Node is empty\n");
        return;
    }

    printf("Hello, World\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }


}

void addNodeAtIndexTwo(int data) {
    struct DoublyList *newNode = (struct DoublyList*)malloc(sizeof(struct DoublyList));
    newNode->data = data;

    if (head == NULL) {
        printf("Empty node \n");
        return;
    }

    struct DoublyList *currentNode = head;
    int counter = 0;
    while (currentNode != NULL) {

        if (counter == 1) {
            currentNode->next->prev = newNode;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            newNode->prev = currentNode;
            return;

        }

        currentNode = currentNode->next;
        counter++;
    }


}

void freeNode(int index) {

    struct DoublyList *block = head;
    int counter = 0;


    while (block != NULL) {
        if (counter == index){
            break;
        }
        block = block->next;
        counter++;
    }


// head
    if (block->prev == NULL) {
        head = block->next;
        head->prev = NULL;
        free(block);
        return;
    }

    // tail
    if (block->next == NULL) {
        tail = block->prev;
        tail->next = NULL;
        free(block);
        return;
    }


    if (block->next != NULL && block->prev != NULL) {
        block->prev->next = block->next;
        block->next->prev = block->prev;
        free(block);
        return;
    }





    //    if (block->prev != NULL) {
//        block->prev->next = block->next;
//    }
//    if (block->next != NULL) {
//        block->next->prev = block->prev;
//    }
//
//   // block->next->prev = block->prev;
//
//    free(block);

}


int main() {

    addNodeAtTail(1);
    addNodeAtTail(2);
    addNodeAtTail(3);
    //printNode();
    addNodeAtHead(4);
    addNodeAtHead(5);
    addNodeAtHead(6);

    addNodeAtIndexTwo(0);
    addNodeAtIndexTwo(2);
    addNodeAtIndexTwo(9);



    printNode();

    freeNode(8);

//    struct DoublyList *aux = head->next;
//    freeNode(0);
//    head = aux;

    printf("\n");
    printNode();


    return 0;
}
