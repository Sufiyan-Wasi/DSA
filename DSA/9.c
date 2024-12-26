#include <stdio.h> 
#include <stdlib.h> 
// Define the structure of a node in the binary search tree 
struct node 
{ 
struct node *leftchild; 
int data; 
struct node *rightchild; 
}; 
typedef struct node *treePointer; 
treePointer root = NULL; // Initialize an empty tree 
treePointer createNode(int value); 
treePointer insertBST(treePointer root, int value); 
void inorder(treePointer root); 
void preorder(treePointer root); 
void postorder(treePointer root); 
void search(treePointer root,int key); 
int main() 
{    
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 10}; 
    int i, ch, key, n = 10;
    while (1) 
    { 
printf("1.Create BST\n 2.Traversals \n3.Search \n4.Exit \nEnter Your Choice:"); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
        case 1:  
            for (i = 0; i < n; i++) 
            { 
                root = insertBST(root, values[i]); 
            } 
            printf("Binary Search Tree Constructed.\n "); 
            break; 
        case 2: 
            printf("\n Inorder: "); 
            inorder(root);         
            printf("\n Pre order: "); 
            preorder(root); 
            printf("\n Post order: "); 
            postorder(root); 
            printf("\n"); 
            break; 
        case 3: 
            printf("\n Enter the key to Search: "); 
            scanf("%d", &key); 
            search(root, key); 
        case 4: 
            exit(0); 
        } 
    } 
    return 0; 
} 
treePointer createNode(int value) 
{ 
    treePointer temp = malloc(sizeof(struct node)); 
    temp->data = value; 
    temp->leftchild = NULL; 
    temp->rightchild = NULL; 
    return temp; 
} 
treePointer insertBST(treePointer root, int value) 
{ 
    if (root == NULL) 
    { 
        root = createNode(value); 
    } 
    else if (value < root->data) 
    { 
        root->leftchild = insertBST(root->leftchild, value); 
    } 
    else 
    { 
        root->rightchild = insertBST(root->rightchild, value); 
    } 
    return root; 
} 
void inorder(treePointer root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->leftchild); 
        printf("%d ", root->data);
        inorder(root->rightchild);
    }
} 
void preorder(treePointer root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->data); 
        preorder(root->leftchild); 
        preorder(root->rightchild); 
    } 
} 
void postorder(treePointer root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->leftchild); 
        postorder(root->rightchild); 
        printf("%d ", root->data); 
    } 
} 
void search(treePointer root, int key) 
{ 
    treePointer temp ; 
    temp= root; 
    while (temp != NULL) 
    { 
        if (key == temp->data)
        { 
            printf("Key found!\n"); 
            return; 
        } 
        else if (key < temp->data)
        { 
            temp = temp->leftchild; 
        } 
        else  
        { 
            temp = temp->rightchild; 
        } 
    } 
} 