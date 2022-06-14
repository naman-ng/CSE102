#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * first, *last = NULL;
//
void create(int A[], int n)
{
    struct node *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
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

void deleteDuplicatesOfValue(struct node *p, int value)
{
    struct node *q;
    if (p->data == value)
    {
        first = p->next;
    }
    q = p->next;
    while (q != NULL)
    {
        if (q->data == value)
        {
            p->next = q->next;
        }
        else
        {
            p = q;
        }
        q = q->next;
    }
}

void reversePointersLL(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseArrLL(struct node *p)
{
    struct node *q = p;
    int *arr, i = 0;
    arr = (int *)malloc(sizeof(int) * count(p));
    while (q != 0)
    {
        arr[i] = q->data;
        q = q->next;
        i++;
    };
    i--;
    q = p;
    while (q != 0)
    {
        q->data = arr[i];
        q = q->next;
        i--;
    }
}

void reverseRecursionLL(struct node *q, struct node *p)
{
    if (p)
    {
        reverseRecursionLL(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void isloop(struct node *p)
{
    struct node *a, *b;
    a = b = p;
    do
    {
        a = a->next;
        b = b->next;
        b = b ? b->next : b;
    } while (a && b && a != b);

    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct node *temp;
    int A[] = {34, 5, 2, 8, 15, 7};
    create(A, 6);
    insert(first, 5, 1000);
    // reverseArrLL(first);
    reversePointersLL(first);
    display(first);
}
