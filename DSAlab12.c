/*Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F.
 Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of
  memory addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are Integers. 
  Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder method), 
  and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using 
  linear probing*/
/* 
Given a file of employee records stored using Hash Table.
Hash Function: H(K) = K mod m
Collision Resolution: Linear Probing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // Size of Hash Table

struct employee
{
    int id;
    char name[20];
};

struct employee emp[MAX];
int ht[MAX];   // Hash table to store keys

int hash(int key)
{
    return key % MAX;
}

void insert()
{
    int id, index, i;

    printf("Enter employee id: ");
    scanf("%d", &id);

    index = hash(id);

    for (i = 0; i < MAX; i++)
    {
        if (ht[index] == -1)
        {
            ht[index] = id;
            emp[index].id = id;

            printf("Enter employee name: ");
            scanf("%s", emp[index].name);
            return;
        }
        index = (index + 1) % MAX;   // Linear probing
    }

    printf("Hash table is full\n");
}

void display()
{
    int i;
    printf("\nIndex\tEmpID\tName\n");
    for (i = 0; i < MAX; i++)
    {
        if (ht[i] != -1)
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        else
            printf("%d\t--\t--\n", i);
    }
}

int main()
{
    int ch, i;

    for (i = 0; i < MAX; i++)
        ht[i] = -1;

    while (1)
    {
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

