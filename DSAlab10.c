/*Develop a menu driven Program in C for the following operations on 
Binary Search Tree (BST) of Integers . 
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2 
b. Traverse the BST in Inorder, Preorder and Post Order 
c. Search the BST for a given element (KEY) and report the appropriate message 
d. Exit*/
#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};
typedef struct BST NODE;

/* Create BST */
NODE* createtree(NODE *root, int data)
{
    if (root == NULL)
    {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
        root->left = createtree(root->left, data);
    else if (data > root->data)
        root->right = createtree(root->right, data);
    return root;
}

/* Traversals */
void inorder(NODE *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(NODE *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search */
void search(NODE *root, int data)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (data == root->data)
        printf("Element found: %d\n", root->data);
    else if (data < root->data)
        search(root->left, data);
    else
        search(root->right, data);
}

int main()
{
    int ch, n, i, data;
    NODE *root = NULL;

    while (1)
    {
        printf("\n1.Create BST\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter elements:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = createtree(root, data);
            }
            break;
        case 2:
            printf("Inorder Traversal:\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal:\n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal:\n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
