#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char * argv[])
{
    Node * head = NULL;
    bool status = true;
    while (status)
    {
        int response = 0;
        printf("1:Insert head\n");
        printf("2:Insert tail\n");
        printf("3:Delete a node\n");
        printf("4:Delete all nodes\n");
        printf("5:Display\n");
        printf("0:Exit\n\n");
        scanf("%d", &response);
        switch (response)
        {
            case 0:
                status = false;
                break;
            case 1:
                printf("What value?\n");
                scanf("%d", &response);
                head = List_insert(head, response);
                break;
            case 2:
                printf("What value?\n");
                scanf("%d", &response);
                List_insert_last(head, response);
                break;
            case 3:
                printf("What value?\n");
                scanf("%d", &response);
                head = List_delete(head, response);
                break;
            case 4:
                List_destroy(head);
                head = NULL;
                break;
            case 5:
                List_print(head);
                break;
            default:
                printf("Not an option\n");
                break;
        }
        printf("\n");
    }
    
    
    return EXIT_SUCCESS;
}
