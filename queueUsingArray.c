#include <stdio.h>

#define MAX 4

int queue[MAX];
int front = -1;
int rear = -1;

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return front == -1 && rear == -1;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Error: Queue is Full!!!\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Error: Queue is Empty!!!\n");
        return;
    }
    else if (front == MAX - 1 && rear == MAX - 1)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

int peek()
{
    return queue[front];
}

void printQueue()
{
    printf("Queue:");
    if (!isEmpty())
    {
        for (int i = front; i <= rear; i++)
        {
            printf(" %i", queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    printQueue();
   
    enqueue(5);
    printQueue();
   
    enqueue(7); 
    printQueue();
   
    enqueue(8);
    printQueue();
   
    enqueue(9);
    printQueue();

    enqueue(11);
    printQueue();

    printf("\nFront Element is = %i\n", peek());

    dequeue();
    printQueue();
    
    dequeue();
    printQueue();
    
    dequeue();
    printQueue();
    
    dequeue();
    printQueue();

    dequeue();
    
    return 0;
}
