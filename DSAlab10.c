/*Develop a menu driven Program in C for the following operations on 
Binary Search Tree (BST) of Integers . 
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2 
b. Traverse the BST in Inorder, Preorder and Post Order 
c. Search the BST for a given element (KEY) and report the appropriate message 
d. Exit*/
#include <stdio.h>
#include <stdlib.h>

/* Definition of BST node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Create BST */
struct node* createtree(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (data < root->data)
        root->left = createtree(root->left, data);
    else if (data > root->data)
        root->right = createtree(root->right, data);

    return root;
}

/* Inorder Traversal */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search in BST */
void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (key == root->data)
        printf("Element found: %d\n", root->data);
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int main()
{
    int ch, n, i, data;
    struct node *root = NULL;

    while (1)
    {
        printf("\n--- BST MENU ---");
        printf("\n1. Create BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
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
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
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

