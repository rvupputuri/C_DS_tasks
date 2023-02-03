#include <stdio.h>
#include <string.h>
int main()
{
    char buff[20] = {0}, str[] = "Geeks for geeks";
    int i = 0, j = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (i == 0)
        {
            // printf("%c\n", str[i]);
            buff[j] = str[i];
            j++;
        }
        else if (str[i] == ' ')
        {
            // printf("%c\n", str[i + 1]);
            buff[j] = str[i + 1];
            j++;
        }
    }
    for (j = 0; buff[j] != '\0'; j++)
        printf("%c\n", buff[j]);
    return 0;
}