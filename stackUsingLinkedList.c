#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

void push(int data)
{
    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("Stack is full!! No element can be inserted\n");
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!! No element left\n");
        return;
    }
    node *temp = top;
    top = top->next;
    free(temp);
}

int peek()
{
    return top->data;
}

void print()
{
    node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" End\n");
}

void printRev(node* temp)
{
    
    if (temp==NULL)
    return;

    printRev(temp->next);
    printf("%d  ", temp->data);
}

int main()
{

    push(5);
    push(6);
    print();
    
    push(7);
    print();
   
    push(8);
    push(9);
    print();

    pop();
    pop();
    pop();
    print();
   
    printf("Printing reverse ");
    printRev(top);

    int value = peek();
    printf("\nTop element of stack is %d\n", value);

    return 0;
}
