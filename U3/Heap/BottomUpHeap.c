#include <stdio.h>
#define MAX 50

void bottomUpHeap(int h[], int n);

int main()
{
	int h[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	printf("Enter the elements\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);

	bottomUpHeap(h, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", h[i]);
	}
}
void bottomUpHeap(int h[], int n)
{
	int k = -1, val = h[0];
	int c = -1;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		k = i;
		val = h[k];
		c = 2 * k + 1;
		while (c < n)
		{
			if (c + 1 < n)
			{
				if (h[c + 1] > h[c])
					c++;
			}
			if (val < h[c])
			{
				h[k] = h[c];
				k = c;
				c = 2 * k + 1;
			}
			else
				break;
		}
		h[k] = val;
	}
}