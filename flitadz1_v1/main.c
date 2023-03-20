#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct Node {
    char *item;
    struct Node *next;
} Node;

void push(Node **head, char *newElement) {
    Node *set = malloc(sizeof(Node));
    set->item = malloc(200 * sizeof(char));
    strcpy(set->item, newElement);
    set->next = *head;
    *head = set;
}

int uniqueItem(Node *set, char *item) {
    bool work = true;

    for (Node *head = set; head != NULL; head = head->next) {
        if (strcmp(item, head->item) == 0) {
            work = false;
            printf("Unique item is already in array!\n");
            break;
        }
    }
    return work;
}

char *pop(Node **head) {
    Node *set = *head;
    char *result = set->item;
    *head = set->next;
    free(set);

    return result;
}

void printArr(Node *set) {
    while (set) {
        printf("%s ", set->item);
        set = set->next;
    }
    printf("\n");
}

int main() {
    Node *firstArr = NULL;
    Node *secondArr = NULL;
    char *item[200];

    printf("Fill symbols in first array\nEnter '/' to stop filling.\n");
    scanf("%s", &item);
    while (strcmp(item, "/")) {
        if (uniqueItem(firstArr, item))
            push(&firstArr, item);
        scanf("%s", &item);
    }

    printf("Fill symbols in second array\nEnter '/' to stop filling.\n");
    scanf("%s", &item);
    while (strcmp(item, "/")) {
        if (uniqueItem(secondArr, item)) push(&secondArr, item);
        scanf("%s", &item);
    }

    int operation, arrayNumber;
    bool work = true;
    while (work == true) {
        printf("Choose:\n1. Add items\n2. Delete last item\n3. Show the array\n0. Exit\n");
        scanf("%d", &operation);

        if (operation != 0) {
            printf("First(1) or Second(2) array?\n");
            scanf("%d", &arrayNumber);
        }

        switch (operation) {
            case 1:
                if (arrayNumber == 1) {
                    printf("Enter '/' to stop filling\n");
                    scanf("%s", &item);
                    while (strcmp(item, "/")) {
                        if (uniqueItem(firstArr, item)) push(&firstArr, item);
                        scanf("%s", &item);
                    }
                } else if (arrayNumber == 2) {
                    printf("Enter '/' to stop filling\n");
                    scanf("%s", &item);
                    while (strcmp(item, "/")) {
                        if (uniqueItem(secondArr, item)) push(&secondArr, item);
                        scanf("%s", &item);
                    }
                } else {
                    printf("Wrong chose of array. You must choose 1 or 2");
                }
                break;
            case 2:
                if (arrayNumber == 1) {
                    pop(&firstArr);
                } else if (arrayNumber == 2) {
                    pop(&secondArr);
                } else {
                    printf("Wrong chose of array\n");
                }
                break;
            case 3:
                if (arrayNumber == 1) {
                    printArr(firstArr);
                } else if (arrayNumber == 2) {
                    printArr(secondArr);
                } else {
                    printf("Wrong chose of array\n");
                }
                break;
            case 0:
                work = false;
                break;
            default:
                printf("Wrong operation. Theres no such an option as %d", operation);
                break;
        }
    }

    return 0;
}