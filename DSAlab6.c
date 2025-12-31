/*Design, Develop and Implement a menu driven Program in C for the following operations on 
Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX) 
a. Insert an Element on to Circular QUEUE 
b. Delete an Element from Circular QUEUE 
c. Demonstrate Overflow and Underflow situations on Circular QUEUE 
d. Display the status of Circular QUEUE 
e. Exit Support the program with appropriate functions for each of the above operations.*/
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 4

int q[QSIZE], f = 0, r = -1, count = 0, item;

void insert()
{
    if (count == QSIZE)
    {
        printf("Queue Overflow\n");
        return;
    }

    r = (r + 1) % QSIZE;
    q[r] = item;
    count++;
}

void del()
{
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted item: %d\n", q[f]);
    f = (f + 1) % QSIZE;
    count--;
}

void display()
{
    int i, front = f;

    if (count == 0)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue contents:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d\n", q[front]);
        front = (front + 1) % QSIZE;
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            insert();
            break;

        case 2:
            del();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
