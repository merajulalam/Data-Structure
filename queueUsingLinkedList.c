#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear  = NULL;

int isFull(node *p)
{
    return p == NULL;
}

int isEmpty()
{
    return front==NULL && rear==NULL;
}

int frontValue()
{
    return front->data;
}

void printQueue()
{
    node* temp = front;

    printf("Queue: ");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("End\n");
}

void enQueue(int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;

    if (isFull(temp))
    {
        printf("Error: Queue is full\n");
        return;
    }
    else if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void deQueue()
{
    node *temp = front;

    if(isEmpty())
    {
        printf("Error: Queue is Empty\n");
        return;
    } 
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

int main()
{
    printQueue();

    enQueue(1);
    enQueue(2);
    enQueue(3);
    printQueue();

    deQueue();
    printQueue();

    printf("Front value is %d\n", frontValue());
    
    deQueue();
    printQueue();

    deQueue();
    printQueue();

    deQueue();
    
return 0;
}
