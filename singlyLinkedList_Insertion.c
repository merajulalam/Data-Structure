#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void print(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("Siiuuu\n");
}

Node *insertFirst(Node *head, int data)
{
    Node *firstBoy = (Node *)malloc(sizeof(Node));
    firstBoy->data = data;
    firstBoy->next = head;

    return firstBoy;
}

void insertLast(Node *head, int data)
{
    Node *lastBoy = (Node *)malloc(sizeof(Node));
    lastBoy->data = data;
    lastBoy->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = lastBoy;
}

void insertAnyPos(Node *head, int data, int pos)
{
    int i = 1;
    Node *anyBoy = (Node *)malloc(sizeof(Node));

    anyBoy->data = data;

    while (i < pos - 1)
    {
        if (head->next != NULL)
        {
            head = head->next;
        }
        i++;
    }

    anyBoy->next = head->next;
    head->next = anyBoy;
}

int main()
{
    Node *head = NULL;

    Node *first = (Node *)malloc(sizeof(Node));
    Node *second =(Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *forth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));

    head = first;

    printf("Enter data in the 1st node: ");
    scanf("%d", &first->data);
    first->next = second;

    printf("Enter data in the 2nd node: ");
    scanf("%d", &second->data);
    second->next = third;

    printf("Enter data in the 3rd node: ");
    scanf("%d", &third->data);
    third->next = forth;

    printf("Enter data in the 4th node: ");
    scanf("%d", &forth->data);
    forth->next = fifth;

    printf("Enter data in the 5th node: ");
    scanf("%d", &fifth->data);
    fifth->next = NULL;

    print(head);

    /// inserting a node to the last position
    int last;
    printf("Enter data in the Last node: ");
    scanf("%d", &last);

    insertLast(head, last);

    print(head);

    /// inserting a node to the first position
    int start;
    printf("Enter data in the 1st node: ");
    scanf("%d", &start);

    head = insertFirst(head, start);

    print(head);

    /// inserting a note to the any position
    int anyPosData;
    printf("Enter data in the Any node: ");
    scanf("%d", &anyPosData);

    int pos;
    printf("Enter data in the Any position: ");
    scanf("%d", &pos);

    insertAnyPos(head, anyPosData, pos);

    print(head);

    return 0;
}
