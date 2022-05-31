#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}

    * first,
    *last = NULL;
// *last = NULL;

void create(int A[], int n)
{
    int i;
    struct node *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    // Iterative Approach

    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }

    // Recursively
    /*
    if (p != 0)
    {
        display(p->next);
        printf("%d\n", p->data);
    }
    */
}

// All the following are possible with Recursion also
int count(struct node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }
    return count;
}

int totalSum(struct node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

struct node *Lsearch(struct node *p, int key)
{
    while (p != 0)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return 0;
}

int RLsearch(struct node *p, int key)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->data == key)
    {
        return p->data;
    }
    return RLsearch(p->next, key);
}

// Insert Function (we can also make a linked list from scratch using insertion)
void insert(struct node *p, int index, int value)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = value;

    if (index < 0 || index > count(p))
    {
        return;
    }

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else if (index > 0)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

void insertLast(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = 0;
    if (first == 0)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void sortedinsert(struct node *p, int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    while (p != 0)
    {
        if ((p->next)->data >= x)
        {
            t->next = p->next;
            p->next = t;
            break;
        }
        p = p->next;
    }
}

int main()
{
    struct node *temp;
    int A[] = {3, 5, 7, 10, 15, 20};
    create(A, 6);
    // printf("%d\n", count(first));
    // temp = Lsearch(first, 17);
    // printf("%d", RLsearch(first, 12));
    // insert(first, 5, 1000);
    insertLast(1000);
    insertLast(555);
    sortedinsert(first, 12);
    display(first);
}
