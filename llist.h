// llist.h

#ifndef LLIST_H
#define LLIST_H

typedef struct node node;
struct node {
    int value;
    struct node *next;
};

void llist_insert_head(node **head, node *n);
node *llist_delete_head(node **head);
void llist_insert_tail(node **head, node *n);
void llist_print(node *head);
void llist_free(node **head);

node *node_alloc(int value);
void node_free(node *n);

#endif
