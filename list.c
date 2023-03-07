#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef enum {
    Int, //0 
    Float, // 1
    Char, 
    Student,
    IntArray,
    FloatArray,
    CharArray,
    StudentArray
} DataType;

typedef struct {
    int len;
    void *array;
} Array;

typedef struct {
    DataType dtype;
    void *data;
} Item;

bool Item_print(Item *item){
    switch (item->dtype)
    {
    case Int:
        {
            int *data = (int *) item->data;
            printf("%d, ", *data);
        }
        break;
    case Float:
        {
            float *data = (float *) item->data;
            printf("%0.2f, ", *data);
        }
        break;
    case Char:
        {
            char *data = (char *) item->data;
            printf("%c, ", *data);
        }
        break;
    case IntArray:
        {
            Array *int_array = item->data;
            int *array = int_array->array;
            printf(" { ");
            for(int i =0; i<int_array->len;i++){
                printf("%d, ", array[i]);
            }
            printf(" }, ");
        }
        break;
    case CharArray:
        {
            Array *char_array = item->data;
            char *string = char_array->array;
            printf("\"");
            for(int i=0; i< char_array->len;i++){
                printf("%c", string[i]);
            }
            printf("\",");
        }
        break;
    default:
        break;
    }
}

typedef struct {
    int len;
    Item *items;
} List;

void List_print(List *list){
    printf("{ ");
    for(int i=0; i<list->len; i++){
        Item_print(&list->items[i]);
    }
    printf(" } ");
}

int main(){
    int a = 100;
    Item item_a = { Int, &a};
    // Item_print(&item_a);

    float pi = 3.14;
    Item item_pi = { Float, &pi};
    // Item_print(&item_pi);

    char ch = 'A';
    Item item_ch = { Char, &ch};
    // Item_print(&item_ch);

    int b = 456;

    int nums[] = {1,2,3,4,5,6};

    // void *ptr = nums;
    Array nums_array = { 6, nums};

    char hello[] = "Hello World";
    Array string = { strlen(hello), hello};

    Item items[] = {
        item_a,
        item_pi,
        item_ch,
        { Int, &b},
        { IntArray, &nums_array},
        { CharArray, &string},
    };

    List list = { 6, items};

    List_print(&list);

    Item_print(&items[2]);


    return 0;
}