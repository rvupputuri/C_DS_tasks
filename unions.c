#include <stdio.h>

typedef enum{
    Int,
    Float,
    Char
} DataType;

typedef union {
    int n; 
    float f; 
    char ch; 
} Data;

typedef struct {
    DataType dtype;
    Data data;
} Item;

typedef struct {
    Item items[20];
} List;


int main(){
    Data x = { .n = 10};
    printf("x.n = %d\n", x.n);
    printf("size of union Data %lu\n", sizeof(Data));
    x.f = 3.0;
    printf("x.f = %f\n", x.f);
    x.ch = 'A';
    printf("x.ch = %c\n", x.ch);

    printf("size of struct Item = %lu\n", sizeof(Item));
    printf("size of enum DataType = %lu\n", sizeof(DataType));
    printf("size of struct List = %lu\n", sizeof(List));

    Item item1 = { Int, { .n = 10 } };
    Item item2 = { Float, { .f= 22.0 } };
    Item item3 = { Char, { .ch='A'} };

    List list;

    list.items[0] = item1;
    list.items[1] = item2;
    list.items[2] = item3;

    for(int i=0; i<3; i++){
        switch(list.items[i].dtype){
            case Int:
                printf("%d. %d\n", i+1, list.items[i].data.n);
                break;
            case Float:
                printf("%d. %f\n", i+1, list.items[i].data.f);
                break;
            case Char:
                printf("%d. %c\n", i+1, list.items[i].data.ch);
                break;
        }
    }


    return 0;
}
