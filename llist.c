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
            printf("llist_print()\n");
        }
        else
        {
            printf("Invalid argument: %s\n", arg);
            exit(1);
        }

        currentArg++;
    }   
}
