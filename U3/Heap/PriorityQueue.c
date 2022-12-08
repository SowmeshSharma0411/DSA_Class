// Descending Priority Queue
#include <stdio.h>
#define MAX 50

void topDownHeap(int h[], int n);
void heapify(int h[], int n);
int maxDelete(int h[], int *n);

int main()
{
    int h[MAX];
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    topDownHeap(h, n);
    printf("\nHeap:");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);

    int res = maxDelete(h, &n);
    printf("\nDeqd %d\n", res);
    printf("\nHeap:");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);

    res = maxDelete(h, &n);
    printf("\nDeqd %d\n", res);
    printf("\nHeap:");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);
}
void topDownHeap(int h[], int n)
{
    int c, p, key;

    for (int i = 1; i < n; i++)
    {
        c = i;
        p = (c - 1) / 2;
        key = h[c];

        while (c > 0 && key > h[p])
        {
            h[c] = h[p];
            c = p;
            p = (c - 1) / 2;
        }
        h[c] = key;
    }
}
void heapify(int h[], int n)
{
    int c, p, key;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        p = i;
        c = 2 * p + 1;
        key = h[p];
        while (c < n)
        {
            if (c + 1 < n)
            {
                if (h[c + 1] > h[c])
                    c++;
            }
            if (key < h[c])
            {
                h[p] = h[c];
                p = c;
                c = 2 * p + 1;
            }
            else
                break;
        }
        h[p] = key;
    }
}
int maxDelete(int h[], int *n)
{
    int del = h[0];
    h[0] = h[*n - 1];
    *n--;
    heapify(h, *n);
    return del;
}