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
            node* node = node_alloc(value);
            llist_insert_head(&head, node);
        }
        else if (strcmp(arg, "it") == 0)
        {
            currentArg++;

            int value = atoi(argv[currentArg]);
            node* node = node_alloc(value);
            llist_insert_tail(&head, node);
        }
        else if (strcmp(arg, "dh") == 0)
        {
            node* node = llist_delete_head(&head);
            if(node != NULL)
            {
                node_free(node);
            }
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

void llist_insert_head(node** head, node* n)
{
    n->next = *head;
    *head = n;

    return;
}

node* llist_delete_head(node** head)
{
    node* current = *head;
    if (current != NULL)
    {
        *head = current->next;
    }

    return current;
}

void llist_insert_tail(node** head, node* n)
{
    if (*head == NULL)
    {
        *head = n;

        return;
    }

    node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = n;

    return;
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

        printf("%d", current->value);

        current = current->next;
    }

    printf("\n");

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
