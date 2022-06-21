#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
} *root = NULL;
//
struct node *insert(struct node *t, int key)
{
    struct node *p;
    if (root == NULL) // Creating a new node with key as data
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (key < t->data)
    {
        t->lchild = insert(t->lchild, key);
    }
    else if (key >= t->data)
    {
        t->rchild = insert(t->rchild, key);
    }
    return t;
}

void inorder(struct node *p) // Increasing order
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", p->data);
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->lchild), height(root->rchild));
}

int count(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->lchild) + count(root->rchild);
}

struct node *search(int key)
{
    struct node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    printf("NULL\n");
}

struct node *minValueNode(struct node *p)
{
    struct node *q = p;
    while (q && q->lchild)
    {
        q = q->lchild;
    }
    return q;
}

struct node *deleteNode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->lchild = deleteNode(root->lchild, key);
    }

    else if (key > root->data)
    {
        root->rchild = deleteNode(root->rchild, key);
    }
    else
    {
        if (root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->rchild);

        root->data = temp->data;

        root->rchild = deleteNode(root->rchild, temp->data);
    }
    return root;
}

int isBST(struct node *node)
{
    if (node == NULL)
        return 1;

    /* false if left is > than node */
    if (node->lchild != NULL && node->lchild->data > node->data)
        return 0;

    /* false if right is < than node */
    if (node->rchild != NULL && node->rchild->data < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(node->lchild) || !isBST(node->rchild))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}

struct node *lca(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->lchild, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->rchild, n1, n2);

    return root;
}

int main()
{
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);
    return 0;
}