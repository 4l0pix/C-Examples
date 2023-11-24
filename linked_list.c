#include<stdio.h>
#include<stdlib.h>

/*In a linked list each node is constructed of 2 parts.
  1.Data 2.a Pointer to the next node*/
/*
------------------------------              ------------------------------
|              |             |            \ |              |             |
|     DATA     |PTR_TO_NEXT  |--------------|     DATA     |PTR_TO_NEXT  |
|              |             |            / |              |             |
------------------------------              ------------------------------
*/
//In order to create a linked list we first need to declare the stracture of the nodes
struct Node{
    int data; //1.Data
    struct Node* next; //2.Ptr to the next node
};

void displayList(struct Node* node){
    printf("List elements--->");
    while(node!=NULL){
        printf("\n%d",node->data);
        node = node->next;
    }
}

void disalloc(struct Node* node){
    struct Node* tmp; // We declare a temp value
    while (node != NULL){ // Until we reach the end of the list
        tmp = node; // We keep the node in a temporary value
        node = node->next; // We transfer the next node to our current node
        free(tmp); // And we erase the contents from the first node
    }
}

int main(){
    // Lets initialize a list of 3 nodes
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
/* Allocate memory */
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // We append the data to each node
    head->data = 0;
    first->data = 11; //we refer to 1.
    second->data = 22;
    third->data = 33;

    // We link each node to the next one
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;
    /* And if we wanted to create a circular list
     * we would do: third->next=head; */

    //In order to view the list we call a display function and we only send the first node
    displayList(head);
    disalloc(curr_node); // We dis-allocate the memory

    return 0;
}
