#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rchild;
    struct node *lchild;
    int height;
} * root;

int nodeHeight(struct node *p)
{
    // exp ? exp=true : exp = false ;
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct node *p)
{
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct node *LL(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = p->lchild->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

struct node *RR(struct node *p)
{
    struct node *pl = p->rchild;
    struct node *plr = p->rchild->lchild;

    pl->lchild = p;
    p->rchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

struct node *insert(struct node *p, int key)
{
    struct node *t = NULL;

    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = insert(p->lchild, key);

    else if (key > p->data)
        p->rchild = insert(p->rchild, key);

    p->height = nodeHeight(p);

    int balance = balanceFactor(p);
    int balanceL = balanceFactor(p->lchild);
    int balanceR = balanceFactor(p->rchild);

    if (balance == 2 && balanceL == 1)
        return LL(p);

    if (balance == 2 && balanceL == -1)
        return LR(p);

    if (balance == -2 && balanceL == -1)
        return RR(p);

    if (balance == -2 && balanceL == 1)
        return RL(p);

    return p;
}

struct node *deleteN(struct node *p, int key)
{
    if (p == NULL)
    {
        return p;
    }

    if (key < p->data)
        p->lchild = deleteN(p->lchild, key);

    else if (key > p->data)
        p->rchild = deleteN(p->rchild, key);

    else
    {
        if ((p->lchild == NULL) || (p->rchild == NULL))
        {
            struct node *temp = p->lchild ? p->lchild : p->rchild;

            if (temp == NULL)
            {
                temp = p;
                p = NULL;
            }
            else
                *p = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(p->rchild);

            p->data = temp->data;

            // Delete the inorder successor
            p->rchild = deleteNode(p->rchild, temp->data);
        }
    }

    if (p == NULL)
        return p;

    p->height = 1 + max(height(p->lchild), height(p->rchild));

    int balance = getBalance(p);

    // If this node becomes unbalanced, then there are 4 cases

    // lchild lchild Case
    if (balance > 1 && getBalance(p->lchild) >= 0)
        return rightRotate(p);

    // lchild rchild Case
    if (balance > 1 && getBalance(p->lchild) < 0)
    {
        p->lchild = leftRotate(p->lchild);
        return rightRotate(p);
    }

    // rchild rchild Case
    if (balance < -1 && getBalance(p->rchild) <= 0)
        return leftRotate(p);
}

int main()
{
    return 0;
}