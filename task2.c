#include <stdio.h>
#include <string.h>
void string_reverse(char *string)
{
    // char string[20];
    char temp;
    int i = 0, j = 0;
    while (string[j] != '\0')
    {
        j++;
    }
    j = j - 1;
    while (i < j)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
    printf("The reversed string is:%s\n", string);
}
void sub_string(char *string1, char *string2)
{
    // char string1[20],string2[10];
    int i = 0, j = 0, k;
    while (string1[i] != '\0')
    {
        if (string1[i] != string2[j])
        {
            i++;
        }
        else
        {
            k = i + 1;
            while (string2[j] != '\0')
            {
                if (string1[i] != string2[j])
                    break;
                i++;
                j++;
            }
            if (string2[j] == '\0')
                break;
            else
            {
                i = k;
                j = 0;
            }
        }
    }
    if (string2[j] == '\0')
        printf("The sub string is present\n");
    else
        printf("The sub string is not present\n");
}
int main()
{
    int choice;
    char string[50], substring[20];
    while (1)
    {
        printf("Enter your choice \n 1.string_reverse\n 2.sub_string\n 3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter a string:");
            scanf("%s", string);
            string_reverse(string);
            break;
        case 2:
            printf("enter a string:");
            scanf("%s", string);
            printf("enter sub string:");
            scanf("%s", substring);
            sub_string(string, substring);
            break;
        case 3:
            printf("exit the program\n");
            return 0;
        default:
            printf("Iam in default");
        }
    }
}