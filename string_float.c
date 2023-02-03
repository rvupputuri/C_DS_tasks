#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "12.34";
    float result;
    result = atof(str);
    printf("The converted float value from string :%f\n", result);
    return 0;
}