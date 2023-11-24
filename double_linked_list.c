#include<stdio.h>
#include<stdlib.h>

/*In a linked list each node is constructed of 3 parts.
  1.Data 2.a Pointer to the next node 3.a Pointer to the previous node*/

//In order to create a linked list we first need to declare the stracture of the nodes
struct Node{
    int data; //1.Data
    struct Node* next; //2.Ptr to the next node
    struct Node* prev; //3. Ptr to the next node
};

void displayList(struct Node* node){
    printf("List elements--->");
    while (node!=NULL) {
        printf("%d ", node->data);
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
    //We initialize two major nodes in the list the Head and the Tail
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *curr_node;
    //CAUTION! WE ENTER OUR ELEMENTS FROM BACK TO THE FRONT
    while(1){

        // We ask for data input
        printf("Enter a non-negative number--->");
        int num;
        scanf("%d",&num);
        if (num<0){ // If a negative number is inserted the input ends
            break;
        }
        //We allocate space for a new node
        curr_node = (struct Node*)malloc(sizeof(struct Node)); // We allocate memory for the current node
        curr_node->data = num; // We append the data to the node
        curr_node->prev = tail; // And the previous node is the tail (if the list is not empty)
        if (head == NULL){
            head = curr_node; // If the list is empty then the new node is the head of the list
        }else{
            tail->next = curr_node; // If the list is not empty then the node we just added is the next after the tail
        }
        tail = curr_node; // And since the new data is always inserted by the back, each new node becomes the tail
    }

    displayList(head); // We display the list
    disalloc(curr_node); // We dis-allocate the memory
    return 0;
}

