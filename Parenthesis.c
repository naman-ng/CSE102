#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
} *top = NULL;
//
void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        top = top->next;
    }
}

char isBalanced(char *t)
{
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (t[i] == '(')
        {
            push('(');
        }
        if (t[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (top == NULL)
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
    char *t = "((a+b)*(c-d))";
    printf("%d", isBalanced(t));
    return 0;
}