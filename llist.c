#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [args]\n", argv[0]);
        exit(1);
    }

    node* head = NULL;

    int currentArg = 1;
    while (currentArg < argc)
    {
        char* arg = argv[currentArg];
        if (strcmp(arg, "ih") == 0)
        {
            currentArg++;

            int value = atoi(argv[currentArg]);

            printf("llist_insert_head(%d)\n", value);
        }
        else if (strcmp(arg, "it") == 0)
        {
            currentArg++;

            int value = atoi(argv[currentArg]);
            printf("llist_insert_tail(%d)\n", value);
        }
        else if (strcmp(arg, "dh") == 0)
        {
            printf("llist_delete_head()\n");
        }
        else if (strcmp(arg, "f") == 0)
        {
            printf("llist_free()\n");
        }
        else if (strcmp(arg, "p") == 0)
        {
            llist_print(head);
        }
        else
        {
            printf("Invalid argument: %s\n", arg);
            exit(1);
        }

        currentArg++;
    }

    node_free(head);

    return 0;
}

void llist_print(node* head)
{
    if (head == NULL)
    {
        printf("[empty]\n");

        return;
    }
    
    node* current = head;
    while (current != NULL)
    {
        if (current != head)
        {
            printf(" -> ");
        }

        printf("%d\n", current->value);

        current = current->next;
    }

    return;
}

node* node_alloc(int value)
{
    node* node = malloc(sizeof(node));
    node->value = value;
    node->next = NULL;

    return node;
}

void node_free(node* n)
{
    free(n);
    n = NULL;

    return;
}
