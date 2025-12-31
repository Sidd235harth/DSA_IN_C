/*Develop a menu driven Program in C for the following operations on 
Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo 
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of nodes in it 
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node
{
    int sem;
    long int phno;
    char name[20], branch[10], usn[20];
    struct node *next;
};

struct node *first = NULL, *last = NULL, *temp = NULL, *temp1 = NULL;

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter USN NAME BRANCH SEM PHNO:\n");
    scanf("%s %s %s %d %ld",
          temp->usn, temp->name, temp->branch,
          &temp->sem, &temp->phno);
    temp->next = NULL;
    count++;
}

void insert_front()
{
    create();
    if (first == NULL)
        first = last = temp;
    else
    {
        temp->next = first;
        first = temp;
    }
}

void insert_rear()
{
    create();
    if (first == NULL)
        first = last = temp;
    else
    {
        last->next = temp;
        last = temp;
    }
}

void display()
{
    temp1 = first;
    if (temp1 == NULL)
    {
        printf("List Empty\n");
        return;
    }
    printf("\nUSN\tNAME\tBRANCH\tSEM\tPHNO\n");
    while (temp1)
    {
        printf("%s\t%s\t%s\t%d\t%ld\n",
               temp1->usn, temp1->name,
               temp1->branch, temp1->sem, temp1->phno);
        temp1 = temp1->next;
    }
    printf("Total Students = %d\n", count);
}

void delete_front()
{
    if (first == NULL)
    {
        printf("List Empty\n");
        return;
    }
    temp = first;
    first = first->next;
    printf("Deleted: %s %s\n", temp->usn, temp->name);
    free(temp);
    count--;
}

void delete_rear()
{
    if (first == NULL)
    {
        printf("List Empty\n");
        return;
    }
    if (first == last)
    {
        printf("Deleted: %s %s\n", first->usn, first->name);
        free(first);
        first = last = NULL;
    }
    else
    {
        temp = first;
        while (temp->next != last)
            temp = temp->next;
        printf("Deleted: %s %s\n", last->usn, last->name);
        free(last);
        last = temp;
        last->next = NULL;
    }
    count--;
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Display\n4.Delete Front\n5.Delete Rear\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insert_front(); break;
        case 2: insert_rear(); break;
        case 3: display(); break;
        case 4: delete_front(); break;
        case 5: delete_rear(); break;
        case 6: exit(0);
        default: printf("Invalid Choice\n");
        }
    }
}
