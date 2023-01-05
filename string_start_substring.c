#include <stdio.h>
#include <stdbool.h>
bool sub_string_func(char string[], char substring[])
{
    if (string == NULL || substring == NULL)
        return false;
    int flag = 0, i;
    for (i = 0; substring[i] != '\0'; i++)
    {
        if (string[i] != substring[i])
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    if (flag == 1)
        printf("The string is started with substring\n");
    else
        printf("The string is not started with substring\n");

        return true;
}
int main()
{
    char string[] = "helloworld";
    char substring[] = "hello";

    sub_string_func(string, substring);

    return 0;
}