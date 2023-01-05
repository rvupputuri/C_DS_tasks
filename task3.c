#include <stdio.h>
#include <string.h>
#define number 10
#define size 20
int name_len = 0;
// inserting a name in an array
void insert(char (*name)[size])
{
    int i;
    printf("Enter element to insert:\n");
    // reading inputs from the user
    scanf("%s", name[name_len]);
    name_len++;
}

// displaying the names present in an array
void display(char (*name)[size])
{
    printf("\nEntered names are:\n");
    for (int i = 0; i < name_len; i++)
        printf("%s ", name[i]);
    printf("\n");
}

// searching the name whether it is present in an array or not
void search(char (*name)[size])
{
    char item[20];
    int flag = 0;
    printf("Enter item to search:\n");
    // reading a input from the user to search a name
    scanf("%s", item);
    for (int i = 0; i < name_len; i++)
    {
        // comparing the array and user specified input
        if (strcmp(name[i], item) == 0)
        {
            // iniatially the flag will be 0 when the both the items found. Making flag 1
            flag = 1;
            printf("Element found\n");
            break;
        }
    }
    if (flag != 1)
        printf("Element not found\n");
}

// deleting a particular name from the array
void delete (char (*name)[size])
{
    char item[20];
    printf("Enter item to delete:\n");
    // reading a input from the user to delete a item
    scanf("%s", item);
    for (int i = 0; i < name_len; i++)
        if (strcmp(name[i], item) == 0)
            memmove(name[i], name[i + 1], (number - (i + 1)) * size);
}

int main()
{
    char name[number][size];
    // char **name;
    int choice;
    while (1)
    {
        printf("Enter your choice \n 1.insert the strings \n 2.search\n 3.delete\n 4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // function call for inserting a name in to array
            insert(name);
            display(name);
            printf("\n");
            break;
        case 2:
            // function call for the searching the name in array
            search(name);
            printf("\n");
            break;
        case 3:
            // function call for deleting the name in an array
            delete (name);
            display(name);
            printf("\n");
            break;
        case 4:
            // exiting the loop
            return 0;
        }
    }
    return 0;
}
