#include <stdio.h>

int main()
{
    char array[] = "Mr.Jock TV quiz Ph.D. bags few lynx";
    for (int i = 0; i < sizeof(array); i++)
    {
        if ((array[i] >= 65 && array[i] <= 90) || (array[i] >= 97 && array[i] <= 122))
        {
            printf("Given string is PANGRAM\n");
        }
        else
        {
            printf("Given string is not a PANGRAM\n");
        }
    }
    return 0;
}