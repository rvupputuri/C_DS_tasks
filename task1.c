#include <stdio.h>
#include <stdlib.h>
// Coverting Decimal Number to Binary.
void binary(int num) // funtion definition
{
    int bin;
    for (int i = 31; i >= 0; i--)
    {                           // conveting from decimal to binary
        bin = ((num >> i) & 1); // right shifting
        printf("%d", bin);      // printing binary number
    }
    printf("\n");
}
// Set a bit
int setbit(int val, int pos)
{                             //  Function definition
    val = (val | (1 << pos)); // setting a particular bit(bit 1)
    return val;
}
// Clear a bit
int clearbit(int val, int pos)
{
    val = (val & (~(1 << pos))); // clearing a bit(bit 0)
    return val;
}
// Toggle a bit
int togglebit(int val, int pos)
{
    val = (val ^ (1 << pos)); // Toggling a bit(bit '0 as 1' & '1 as 0')
    return val;
}
int main()
{ // Main program
    int choice, num, pos, sb, cb, tb;
    while (1)
    {
        printf("Enter your choice \n 1. Decimal to binary\n 2. Set bit\n 3. Clear bit\n 4. Toggle bit\n 5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter decimal number:");
            scanf("%d", &num);
            binary(num); // Function call
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &num);
            binary(num);
            printf("\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("\n");
            sb = setbit(num, pos); // Function call
            printf("%d\n", sb);
            binary(sb);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &num);
            binary(num);
            printf("\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("\n");
            cb = clearbit(num, pos); // Function call
            printf("%d\n", cb);
            binary(cb);
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%d", &num);
            binary(num);
            printf("\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("\n");
            tb = togglebit(num, pos); // Function call
            printf("%d\n", tb);
            binary(tb);
            break;
        case 5:
            printf("exit the program\n");
            exit(0);
        default:
            printf("Iam in Default");
            break;
        }
    }
    return 0;
}