#include <stdio.h>
#include <stdlib.h>
int n, m;

struct queue
{
    int size;
    int head;
    int tail;
    int *arr;
};

struct queue *init(int size)
{
    struct queue *q = (struct queue *)(malloc(sizeof(struct queue)));
    q->size = size;
    q->head = q->tail = 0;
    q->arr = (int *)(malloc(size * sizeof(int)));
    return q;
}

int isempty(struct queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    q->arr[q->tail] = val;
    if (q->tail == q->size - 1)
    {
        q->tail = 0;
    }
    else
    {
        q->tail += 1;
    }
}

int dequeue(struct queue *q)
{
    int ret = q->arr[q->head];
    if (q->head == q->size - 1)
    {
        q->head = 0;
    }
    else
    {
        q->head += 1;
    }
    return ret;
}

void bfs(int u, struct queue *q, int arr[][n + 1], int vis[], int n)
{
    int v;
    printf("%d", u);
    vis[u] = 1;
    enqueue(q, u);
    while (!isempty(q))
    {
        v = dequeue(q);
        for (int i = 1; i <= n; i++)
        {
            // printf("%d %d",arr[v][i],vis[i]);
            if (arr[v][i] == 1 && vis[i] == 0)

            {
                printf("%d ", i);
                vis[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

int main()
{

    int u, v;
    scanf("%d %d", &n, &m); // n=no. of nodes,  m=no. of edges
    struct queue *q = init(n);

    int vis[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        vis[i] = 0;
    }

    int arr[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    bfs(1, q, arr, vis, n);
    return 0;
}