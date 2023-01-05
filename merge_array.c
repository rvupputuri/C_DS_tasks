#include <stdio.h>
#include <stdbool.h>
bool merge_array(int first_array[], int second_array[], int len_first_array, int len_second_array, int merged_array[], int len_third_array)
{
    if (first_array == NULL || second_array == NULL || len_first_array == 0 || len_second_array == 0)
        return false;
    int i, j;
    for (i = 0; i < len_first_array; i++)
    {
        merged_array[i] = first_array[i];
    }
    for (i = 0, j = len_first_array; i < len_second_array && j < len_third_array; i++, j++)
    {
        merged_array[j] = second_array[i];
    }
    return true;
}
bool sorting(int array[], int length)
{
    if (array == NULL || length == 0)
        return false;
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
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
    int len_third_array = len_first_array + len_second_array;
    int merged_array[len_third_array];

    printf("The first array is:\n");
    array_print(first_array, len_first_array);
    printf("\n");

    printf("The second array is:\n");
    array_print(second_array, len_second_array);
    printf("\n");

    printf("The merged array before sorting:\n");
    merge_array(first_array, second_array, len_first_array, len_second_array, merged_array, len_third_array);
    array_print(merged_array, len_third_array);
    printf("\n");

    printf("The merged array after sorting:\n");
    merge_array(first_array, second_array, len_first_array, len_second_array, merged_array, len_third_array);
    sorting(merged_array, len_third_array);
    array_print(merged_array, len_third_array);
    printf("\n");

    return 0;
}