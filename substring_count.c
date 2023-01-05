#include <stdio.h>
#include <string.h>
void occurance_count(char string[], char substring[])
{
    int count = 0;
    int len_of_string = strlen(string);
    int len_of_substring = strlen(substring);
    for (int i = 0; i < strlen(substring); i++)
    {
        if (string[i] == substring[i])
            count++;
    }
    printf("%d", count);
}
int main()
{
    char string[] = "hello world hello world hello world";
    char substring[] = "hello";
    occurance_count(string, substring);
}