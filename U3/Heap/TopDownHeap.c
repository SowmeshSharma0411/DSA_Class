// Redo
#include <stdio.h>
#define MAX 50

void topDownHeap(int h[], int n);

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

    for (int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
}
void topDownHeap(int h[], int n)
{
    int val = h[0];
    int ind = 0;
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        ind = i;
        val = h[ind];
        c = (ind - 1) / 2;
        while (ind > 0 && val > h[c])
        {
            h[ind] = h[c];
            ind = c;
            c = (ind - 1) / 2;
        }
        h[ind] = val;
    }
}