#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool sub_string_func(char string[], char substring[])
{
    int string_len = strlen(string);
    int substring_len = strlen(substring);
    if (substring_len > string_len)
        return false;
    for (int i = 0; i < substring_len; i++)
        if (string[string_len - i] != substring[substring_len - i])
            return false;

    return true;
}
int main()
{
    char string[] = "roses are red";
    char substring[] = "red";

    if (sub_string_func(string, substring))
        printf("The string ends with the substring\n");
    else
        printf("The string does not ends with the substring\n");

    return 0;
}