/*Develop a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

int s[MAX], top = -1, item;

int IsFull()
{
    if (top >= MAX - 1)
        return 1;
    return 0;
}

int IsEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push(int item)
{
    s[++top] = item;
}

void pop()
{
    item = s[top--];
}

void display()
{
    int i;
    printf("\nElements of stack are:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", s[i]);
}

void check_pal()
{
    int num = 0, revnum = 0, k = 0;

    if (IsEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    while (!IsEmpty())
    {
        pop();
        num = num * 10 + item;
        revnum = item * pow(10, k) + revnum;
        k++;
    }

    printf("Reverse of %d is %d\n", num, revnum);

    if (num == revnum)
        printf("The stack contains a Palindrome number\n");
    else
        printf("The stack does not contain a Palindrome number\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Push 2.Pop 3.Display 4.Check Palindrome 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            if (IsFull())
                printf("Stack Overflow\n");
            else
                push(item);
            break;

        case 2:
            if (IsEmpty())
                printf("Stack Underflow\n");
            else
            {
                pop();
                printf("Deleted item is %d\n", item);
            }
            break;

        case 3:
            if (IsEmpty())
                printf("Stack is empty\n");
            else
                display();
            break;

        case 4:
            check_pal();
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);

    return 0;
}
