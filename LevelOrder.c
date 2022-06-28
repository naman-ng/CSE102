#include <stdio.h>
#include <stdlib.h>

typedef struct bin_node
{
    int val;
    struct bin_node *left;
    struct bin_node *right;
} bt;

typedef struct node
{
    bt *val;
    struct node *next;
} node;

typedef struct Queue
{
    node *head;
    node *tail;
} qu;

qu *initializeQ()
{
    qu *Q = (qu *)malloc(sizeof(qu));
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

bt *bNode(int val)
{
    bt *root = (bt *)malloc(sizeof(bt));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node *allocate(bt *val)
{
    node *head = (node *)malloc(sizeof(node));
    head->val = val;
    head->next = NULL;
    return head;
}

node *insertion_front(node *head, node *n)
{
    head->next = n;
    return n;
}
void enqueue(qu *Q, bt *val)
{
    node *n = allocate(val);

    if (Q->head == NULL)
    {
        Q->head = n;
        Q->tail = n;
        return;
    }
    Q->tail = insertion_front(Q->tail, n);
}

bt *dequeue(qu *Q)
{
    if (Q->head == NULL)
    {
        printf("Underflow");
        return NULL;
    }
    node *tmp = Q->head;
    Q->head = Q->head->next;
    return tmp->val;
}

int main()
{
    int n, r, x;
    qu *Q = initializeQ();
    scanf("%d", &n);
    scanf("%d", &r);
    bt *root = bNode(r);
    enqueue(Q, root);
    int c = 1;
    bt *node1, *node2;
    while (Q->head != NULL && c < n)
    {
        bt *b_node = dequeue(Q);
        scanf("%d", &x);
        if (x == -1)
            node1 = NULL;
        else
            node1 = bNode(x);
        if (c >= n)
            break;

        enqueue(Q, node1);
        c++;
        b_node->left = node1;

        scanf("%d", &x);
        if (x == -1)
            node2 = NULL;

        else
            node2 = bNode(x);
        enqueue(Q, node2);

        c++;
        b_node->right = node2;
    }

    return 0;
}