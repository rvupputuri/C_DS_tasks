#include <stdio.h>

int main()
{
	int length = 0, i, array[100] = {10, 20, 30, 40, 50, 60, 70};
	for (i = 0; array[i] != 0; i++)
		length = i;
	for (i = length + 1; i > 0; i--)
		array[i + 1] = array[i];
	array[0] = length;
	for (i = 0; i < length + 1; i++)
	{
		if (i == 0)
			printf("[%d] ", array[i]);
		else
			printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
