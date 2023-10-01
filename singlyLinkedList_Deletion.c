#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* deleteHead(node* head)
{
    node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

void deleteEnd(node* head)
{
    node* prev = head;

    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
    }

    free(head);
    prev->next = NULL;

}

void deleteMid(node* head, int pos)
{
    int i=1;
    node* dltNode;
    while (i < pos-1)
    {
        head = head->next;
        i++;
    }
    dltNode = head->next;

    head->next = dltNode->next;
    free(dltNode);

}


void printThis(node* head)
{
    while (head != NULL)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("End is near\n");
}

int main()
{
    node* n1 = (node*) malloc(sizeof(node));
    node* n2 = (node*) malloc(sizeof(node));
    node* n3 = (node*) malloc(sizeof(node));
    node* n4 = (node*) malloc(sizeof(node));
    node* n5 = (node*) malloc(sizeof(node));

    node* head = n1;

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;
    n5->data = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    printThis(head);

    //delete from head
    head = deleteHead(head);
    printThis(head);

    //delete from end
    deleteEnd(head);
    printThis(head);

    //delete from any position
    deleteMid(head, 3);
    printThis(head);

    return 0;
}
