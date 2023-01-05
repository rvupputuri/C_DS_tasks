#include <stdio.h>
#include <stdbool.h>
bool palindrome_func(char string[])
{
    if (string == NULL)
        return false;

    int i = 0, j = 0;
    while (string[j] != '\0')
    {
        j++;
    }
    j = j - 1;
    while (i < j)
    {
        if (string[i] != string[j])
            break;
        i++;
        j--;
    }
    if (i >= j)
        printf("The string is palindrome\n");
    else
        printf("The string is not palindrome\n");

    return true;
}

int main()
{
    char string[] = "malayalam";
    palindrome_func(string);
    return 0;
}