#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// In this program i took delimiter as "|"

bool separate_func(char string[])
{
    if (string == NULL)
        return false;
    int i = 0;
    char token = ' ';
    while (string[i] != '\0')
    {
        if (string[i] == token)
            printf("|");
        else
            printf("%c", string[i]);
        i++;
    }

    return true;
}
int main()
{
    char string[] = "Hi this is Rajesh";
    separate_func(string);

    printf("\n");

    return 0;
}
