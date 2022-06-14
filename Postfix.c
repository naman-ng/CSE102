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

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = InToPost(infix);
    printf("%s ", postfix);
    return 0;
}