#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

bool find(struct Node *head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
            return true;

        head = head->next;
    }

    return false;
}

void deleteBack(struct Node **head)
{

    if (*head == NULL)
    {
        // List is empty
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        // List has only one node
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    // Traverse to the second-last node
    while (temp->next->next != NULL)
        temp = temp->next;

    // Delete the last node
    free(temp->next);
    temp->next = NULL;
}
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{

    struct Node *head = NULL;

    for (int i = 0; i < 3; i++)
    {
        insertEnd(&head, 10);
        insertEnd(&head, 20);
        insertEnd(&head, 30);
    }

    printList(head);

    deleteBack(&head);
    printList(head);

    bool valFind = find(head, 20);

    printf("%d\n", valFind);

    valFind = find(head, 50);

    printf("%d\n", valFind);

    freeList(head);

    return 0;
}