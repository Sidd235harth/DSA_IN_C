/*Develop a Program in C for the following operationson 
Singly Circular Linked List (SCLL) with header nodes 
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x 2 y 2 z-4yz 5 +3x 3 yz+2xy 5 z-2xyz 3 
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z) 
Support the program with appropriate functions for each of the above operations*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int cf, px, py, pz;
    int flag;
    struct node *link;
};
typedef struct node NODE;

/* Create node */
NODE* getnode()
{
    NODE *x = (NODE*)malloc(sizeof(NODE));
    if (x == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    x->flag = 0;   // IMPORTANT
    return x;
}

/* Display polynomial */
void display(NODE *head)
{
    NODE *temp;

    if (head->link == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }

    temp = head->link;
    while (temp != head)
    {
        printf("%d x^%d y^%d z^%d",
               temp->cf, temp->px, temp->py, temp->pz);

        if (temp->link != head)
            printf(" + ");

        temp = temp->link;
    }
    printf("\n");
}

/* Insert at rear */
NODE* insert_rear(int cf, int x, int y, int z, NODE *head)
{
    NODE *temp, *cur;
    temp = getnode();

    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;

    cur = head;
    while (cur->link != head)
        cur = cur->link;

    cur->link = temp;
    temp->link = head;

    return head;
}

/* Read polynomial */
NODE* read_poly(NODE *head)
{
    int cf, px, py, pz, ch;

    do
    {
        printf("Enter coefficient: ");
        scanf("%d", &cf);

        printf("Enter powers of x y z: ");
        scanf("%d %d %d", &px, &py, &pz);

        head = insert_rear(cf, px, py, pz, head);

        printf("Press 1 to continue, 0 to stop: ");
        scanf("%d", &ch);

    } while (ch == 1);

    return head;
}

/* Add two polynomials */
NODE* add_poly(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *p1, *p2;
    int cf;

    p1 = h1->link;
    while (p1 != h1)
    {
        p2 = h2->link;
        while (p2 != h2)
        {
            if (p1->px == p2->px &&
                p1->py == p2->py &&
                p1->pz == p2->pz)
                break;
            p2 = p2->link;
        }

        if (p2 != h2)
        {
            cf = p1->cf + p2->cf;
            p2->flag = 1;
            if (cf != 0)
                h3 = insert_rear(cf, p1->px, p1->py, p1->pz, h3);
        }
        else
        {
            h3 = insert_rear(p1->cf, p1->px, p1->py, p1->pz, h3);
        }
        p1 = p1->link;
    }

    p2 = h2->link;
    while (p2 != h2)
    {
        if (p2->flag == 0)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }

    return h3;
}

/* Evaluate polynomial */
void evaluate(NODE *head)
{
    NODE *temp = head->link;
    int x, y, z;
    float result = 0;

    printf("Enter x y z values: ");
    scanf("%d %d %d", &x, &y, &z);

    while (temp != head)
    {
        result += temp->cf *
                  pow(x, temp->px) *
                  pow(y, temp->py) *
                  pow(z, temp->pz);
        temp = temp->link;
    }

    printf("Polynomial value = %.2f\n", result);
}

/* MAIN */
int main()
{
    NODE *h1, *h2, *h3, *eval;
    int ch;

    while (1)
    {
        h1 = getnode();
        h2 = getnode();
        h3 = getnode();
        eval = getnode();

        h1->link = h1;
        h2->link = h2;
        h3->link = h3;
        eval->link = eval;

        printf("\n1. Evaluate Polynomial");
        printf("\n2. Add Two Polynomials");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter polynomial:\n");
            eval = read_poly(eval);
            display(eval);
            evaluate(eval);
            break;

        case 2:
            printf("Enter first polynomial:\n");
            h1 = read_poly(h1);

            printf("Enter second polynomial:\n");
            h2 = read_poly(h2);

            h3 = add_poly(h1, h2, h3);

            printf("First polynomial:\n");
            display(h1);
            printf("Second polynomial:\n");
            display(h2);
            printf("Sum polynomial:\n");
            display(h3);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
