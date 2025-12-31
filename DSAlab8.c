/*Develop a menu driven Program in C for the following operations on 
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo 
a. Create a DLL of N Employees Data by using end insertion. 
b. Display the status of DLL and count the number of nodes in it 
c. Perform Insertion and Deletion at End of DLL 
d. Perform Insertion and Deletion at Front of DLL 
e. Demonstrate how this DLL can be used as Double Ended Queue. 
f. Exit*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node
{
    int ssn;
    float sal;
    long int phno;
    char name[20], dept[10], desg[20];
    struct node *prev, *next;
};

struct node *first = NULL, *last = NULL, *temp;

/* Create a new node */
void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter SSN Name Dept Designation Salary PhoneNo:\n");
    scanf("%d %s %s %s %f %ld",
          &temp->ssn,
          temp->name,
          temp->dept,
          temp->desg,
          &temp->sal,
          &temp->phno);

    temp->prev = temp->next = NULL;
    count++;
}

/* Insert at front */
void insert_front()
{
    create();
    if (first == NULL)
        first = last = temp;
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

/* Insert at rear */
void insert_rear()
{
    create();
    if (first == NULL)
        first = last = temp;
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

/* Delete from front */
void delete_front()
{
    if (first == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    temp = first;
    printf("Deleted Employee: %s\n", temp->name);

    if (first == last)   // only one node
        first = last = NULL;
    else
    {
        first = first->next;
        first->prev = NULL;
    }

    free(temp);
    count--;
}

/* Delete from rear */
void delete_rear()
{
    if (last == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    temp = last;
    printf("Deleted Employee: %s\n", temp->name);

    if (first == last)   // only one node
        first = last = NULL;
    else
    {
        last = last->prev;
        last->next = NULL;
    }

    free(temp);
    count--;
}

/* Display DLL */
void display()
{
    struct node *cur;

    if (first == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    printf("\nSSN\tName\tDept\tDesg\tSalary\tPhone\n");
    cur = first;
    while (cur != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%.2f\t%ld\n",
               cur->ssn, cur->name, cur->dept,
               cur->desg, cur->sal, cur->phno);
        cur = cur->next;
    }
    printf("Total Employees = %d\n", count);
}

/* MAIN MENU */
int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n----- DLL MENU -----\n");
        printf("1. Create DLL (Insert N Employees at Rear)\n");
        printf("2. Insert Front\n");
        printf("3. Insert Rear\n");
        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Display DLL & Count\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter number of employees: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insert_rear();
            break;

        case 2:
            insert_front();
            break;

        case 3:
            insert_rear();
            break;

        case 4:
            delete_front();
            break;

        case 5:
            delete_rear();
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
