#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CELLS 30
// element to be added
struct chainNode {
    struct chainNode* next;
    int key;
};

// chain of elements
struct chainOfElements {
    struct chainNode* first;
    struct chainNode* last;
    int size;
};

// main data structure
struct Chained_hashing {
    struct chainOfElements* table;
    int size;
};

void _init_chainOfElements(struct chainOfElements* x) {
    x->first = NULL;
    x->last = NULL;
    x->size = 0;
}

void init_hashing(struct Chained_hashing* ch) {
    ch->table = (struct chainOfElements*)malloc(sizeof(struct chainOfElements) * MAX_CELLS);
    ch->size = MAX_CELLS;
    for (int i = 0; i < MAX_CELLS; i++) {
        _init_chainOfElements(&(ch->table[i]));
    }
}



void insert_to_chain(struct chainOfElements* x, int key) {
    if (x->size == 0) {  // the chain is empty
        x->first = (struct chainNode*)malloc(sizeof(struct chainNode));
        x->first->key = key;
        x->first->next = NULL;
        x->last = x->first;
    } else {
        x->last->next = (struct chainNode*)malloc(sizeof(struct chainNode));
        x->last->next->key = key;
        x->last->next->next = NULL;
        x->last = x->last->next;
    }
    x->size++;
}

void delete_from_chain(struct chainOfElements* x, int key) {
    struct chainNode* nd_prev = NULL;
    struct chainNode* nd = x->first;
    while (nd != NULL) {
        if (nd->key == key) {
            if ((nd == x->first) && (x->first == x->last))
                x->first = x->last = NULL;
            else if ((nd == x->first) && (x->first != x->last))
                x->first = x->first->next;
            else if (nd != x->last)
                nd_prev->next = nd->next;
            else {
                x->last = nd_prev;
                nd_prev->next = NULL;
            }
            x->size--;
            free(nd);
            return;
        }
        nd_prev = nd;
        nd = nd->next;
    }
}

void print_chain(struct chainOfElements* x) {
    struct chainNode* nd = x->first;
    printf("List: ");
    while (nd != NULL) {
        printf("%d\t", nd->key);
        nd = nd->next;
    }
    printf("\n");
}

int search_chain(struct chainOfElements* x, int key) {
    struct chainNode* nd = x->first;
    while (nd != NULL) {
        if (nd->key == key)
            return 1;
        nd = nd->next;
    }
    return -1;
}

struct chainNode* search_chain_node(struct chainOfElements* x, int key) {
    struct chainNode* nd = x->first;
    while (nd != NULL) {
        if (nd->key == key)
            return nd;
        nd = nd->next;
    }
    return NULL;
}

void insert_to_chained_hashing(struct Chained_hashing* ch, int key) {
    int index = key % ch->size;
    insert_to_chain(&(ch->table[index]), key);
}

void print_chained_hashing(struct Chained_hashing* ch) {
    for (int i = 0; i < ch->size; i++) {
        printf("Index %d: ", i);
        print_chain(&(ch->table[i]));
    }
}

int main() {
    struct Chained_hashing ch;
    init_hashing(&ch);
    for (int i = 0; i < MAX_CELLS; i++)
        insert_to_chained_hashing(&ch, rand() % 100);
    print_chained_hashing(&ch);
    return 0;
}

