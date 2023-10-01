#include <stdio.h> 
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

int isFull()
{
    return top == MAX_SIZE - 1;
}

int isEmpty()
{
    return top == -1;
}

void peek()
{
    printf("Top is %d\n", stack[top]);
}

void push(int x)
{
    if (isFull())
    {
        printf("Error: Stack Overflow!!! \n");
    }
    else
    {
        stack[++top] = x;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Error: Stack Underflow !!! \n");
    }
    else
    {
        peek();
        top--;
    }
}

void print()
{
    if (isEmpty())
    {
        printf("No element!!!");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main()
{
    push(1);
    print();

    push(2);
    push(3);
    print();

    push(4);
    push(5);
    print();

    push(6);
    print();

    pop();
    print();

    pop();
    print();
    
    pop();
    print();


    return 0;
}
