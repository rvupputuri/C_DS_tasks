/*How calculate the sum of n numbers
by using dynamic memory allocation function*/

#include <stdio.h>
#include <stdlib.h>
void main()
{
    int num, i, sum = 0;
    int *ptr;
    printf("Enter the number of elements : ");
    scanf("%d", &num);
    ptr = (int *)malloc(num * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not available");
        exit(0);
    }
    printf("Enter the elements : \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + *(ptr + i);
    }
    printf("The sum of elements is:%d\n", sum);
    free(ptr);
}
