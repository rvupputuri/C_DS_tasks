#include <stdio.h>
#include <stdbool.h>
bool sum_of_array(int first_array[], int second_array[], int len_first_array, int len_second_array, int sum_array[], int len_third_array)
{
    if (first_array == NULL || second_array == NULL || len_first_array == 0 || len_second_array == 0)
        return false;

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len_first_array, j < len_second_array, k < len_third_array; i++, j++, k++)
    {
        sum_array[k] = first_array[i] + second_array[j];
    }
    return true;
}
void array_print(int *array, int array_size)
{
    printf("[");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", *array++);
    }
    printf("]");
}
int main()
{
    int first_array[] = {2, 3, 6, 5};
    int second_array[] = {1, 7, 8, 4};
    int len_first_array = sizeof(first_array) / sizeof(int);
    int len_second_array = sizeof(second_array) / sizeof(int);
    int len_third_array = sizeof(second_array) / sizeof(int);
    int sum_array[len_third_array];

    printf("The first array is:\n");
    array_print(first_array, len_first_array);
    printf("\n");

    printf("The second array is:\n");
    array_print(second_array, len_second_array);
    printf("\n");

    printf("The sum of two arrays :\n");
    sum_of_array(first_array, second_array, len_first_array, len_second_array, sum_array, len_third_array);
    array_print(sum_array, len_third_array);
    printf("\n");
    return 0;
}
