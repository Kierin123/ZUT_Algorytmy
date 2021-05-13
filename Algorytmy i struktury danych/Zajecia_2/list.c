#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    Node *next;
    int elem;
};

struct List
{
    Node *head;
};

List *create_list(void)
{
    List *list = malloc(sizeof(List));
    list->head = NULL;

    //printf("List ptr: %p , list head: %p \n\n", (void *)list, (void *)list->head);

    return list;
}

void destroy_list(List **list)
{
    clear_list(*list);

    free(*list);
}

void clear_list(List *list)
{
    int listSize = count_elements(list);

    for (int i = listSize - 1; i >= 0; i--)
    {
        remove_nth_element(list, i);
    }
}

int count_elements(List *list)
{
    Node *lastNode = list->head;
    int count = 0;
    if (list == NULL || lastNode == NULL)
    {
        return 0;
    }
    else
    {
        count++;
        //  printf("COUNTING: Head: %p Next: %p Elem: %d \n", (void *)list->head, (void *)list->head->next, list->head->elem);
    }

    while (lastNode->next != NULL)
    {
        count++;
        lastNode = lastNode->next;
        //  printf("COUNTING: Head: %p Next: %p Elem: %d \n", (void *)list->head, (void *)list->head->next, list->head->elem);
    }

    return count;
}

void append_to_list(List *list, int elem)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *lastNode = list->head;

    //printf("%d Head: %p \n", a, (void *)list->head);

    newNode->next = NULL;
    newNode->elem = elem;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    //printf("%d Last: %p \n", a, (void *)lastNode);
    //printf("%d Head: %p \n", a, (void *)list->head);
}

int get_nth_element(List *list, int index)
{
    Node *lastNode = list->head;

    for (int i = 0; i < index; i++)
    {
        lastNode = lastNode->next;
    }

    return lastNode->elem;
}

void remove_nth_element(List *list, int index)
{
    Node *tempNode = list->head;
    Node *lastNode = list->head;

    //Exception for list[0] element.
    //Assign list->head address by the adress of list[1] element.
    //For any other element from the list it works by shifting
    //*lastNode to reach the index element.
    if (index == 0)
    {
        list->head = list->head->next;
    }
    else
    {
        for (int i = 0; i < (index - 1); i++)
        {
            tempNode = tempNode->next;
        }

        for (int i = 0; i < index; i++)
        {
            lastNode = lastNode->next;
        }

        tempNode->next = lastNode->next;
    }
    //Free allocated memory for the indicated Node by *lastNode
    free(lastNode);
}

void insert_to_list(List *list, int elem, int index)
{
    if (index > count_elements(list))
    {
        printf("Wrong index! Cannot add element.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *lastNode = list->head;

    newNode->elem = elem;

    if (index == 0)
    {
        newNode->next = lastNode->next;
        list->head = newNode;
        return;
    }
    for (int i = 0; i < (index - 1); i++)
    {
        lastNode = lastNode->next;
    }

    newNode->next = lastNode->next;
    lastNode->next = newNode;
}

void sort_list(List *list)
{
    // ____ Variables init ____
    // j - (1) loop iterator
    // i - (2) loop iterator
    // p - algorithm stop flag
    // lastNode - element [j-1] - variable to work with sorting on the linked list element. 
    //                            Variable pointing the element before the nextNode.
    // nextNode - element [j] - variable to work with sorting on the linked list element. 
    Node *lastNode = NULL;
    Node *nextNode = list->head;

    int p = 0, i = 0, j = 0;
    int arr_size = count_elements(list);

    // First loop (1)
    for (j = arr_size - 1; j >= 1; j--)
    {
        p = 1;
        lastNode = NULL;
        nextNode = list->head;

        // Second loop (2)
        for (i = 1; i <= j; i++)
        {
            lastNode = nextNode;
            nextNode = nextNode->next;
            if (lastNode->elem > nextNode->elem)
            {
                // Solution without using temporary variable
                lastNode->elem ^= nextNode->elem;
                nextNode->elem ^= lastNode->elem;
                lastNode->elem ^= nextNode->elem;
                p = 0;
            }
        }
        if (p == 1)
        {
            break;
        }
    }
}

void reverse_list(List *list)
{
    /*
        In this function we use 3 temporary variables to remember 3 elements in series.
        It is presented on the diagram below. 

(1) step  temp=NULL  last        next        ____        ____
       list.head--->|head|   -->|head|   -->|head|   -->|head|
                    |next|---   |next|---   |next|---   |next|---> NULL


(2) step             temp        last        next        ____
       list.head--->|head|<--   |head|      |head|   -->|head|
            NULL<---|next|   ---|next|      |next|---   |next|---> NULL

        To reverse elements we running algorithm in loop until nextNode->next differ then NULL
        During this itaration we replace the adresses from the field "next" to reverse the direction of the list.
        At the last 
    */
    Node *tempNode = NULL;              
    Node *nextNode = list->head->next;
    Node *lastNode = list->head;

    lastNode->next = NULL;

    while (nextNode->next != NULL)
    {
        tempNode = lastNode;
        lastNode = nextNode;
        nextNode = nextNode->next;
        lastNode->next = tempNode;
    }

    if (nextNode->next == NULL)
    {
        nextNode->next = lastNode;
        list->head = nextNode;
    }
}
