#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* getNewNode(int data)
{
    node *notun = (node*)malloc(sizeof(node));
    
    notun->data = data;
    notun->prev = NULL;
    notun->next = NULL;

    return notun;
}

node* atStart(node* head, int data)
{
    node* start = getNewNode(data);

    start->next = head;

    head->prev = start;

    return start;
}

void atEnd(node* head, int data)
{
    node* end = getNewNode(data);
    
    while (head->next != NULL)
    {
        head = head->next;
    } 
    end->prev = head; 
    head->next = end;
}

void atMiddle(node* head, int data, int pos)
{
    node* middle = getNewNode(data);
    node* nextHead;

    int i=1;

    while (i < pos-1)
    {   
        head = head->next;
        i++;
    }
    nextHead = head->next;

 middle->next = nextHead;
 middle->prev = head;
    
    nextHead->prev = middle;
    head->next = middle;
}

void printForward(node* head)
{
    printf("Forward  ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head= head->next;
    }
    printf("\n");
}

void printReverse(node* head)
{

    while (head->next != NULL)
    {
        head = head->next;
    } 

    printf("Backward ");
    while (head != NULL)
    {
        printf("%d ",  head ->data);
        head = head ->prev;
    }
    printf("\n");
}

int main()
{
    node* n1 = (node*) malloc(sizeof(node));
    node* n2 = (node*) malloc(sizeof(node));
    node* n3 = (node*) malloc(sizeof(node));
   
    node* head = n1;

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    printf("At normal stage\n");
    printForward(head);
    printReverse(head);

    printf("\nAfter inserting at start\n");
    head = atStart(head, 10);
    printForward(head);
    printReverse(head);

    printf("\nAfter inserting at end\n");
    atEnd(head, 30);
    printForward(head);
    printReverse(head);
   
    printf("\nAfter inserting at middle\n");
    atMiddle(head, 50, 3);
    printForward(head);
    printReverse(head);

    return 0;
}
