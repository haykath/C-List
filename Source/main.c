#include <stdio.h>

#define LTYPE int
#include "cgenerics/list.h"
#undef LTYPE

char IntComparer(int a, int b){
    if(a < b) return -1;
    else if(a == b) return 0;
    else return 1;
}

Comparer_Type(int) Comparer(int) = &IntComparer;

char CanRemove(int a){
    return (a % 2 == 1) ? 1 : 0;
}

char PrintElement(int* ip){
    printf("# %d ", *ip);
    return 1;
}

char MultiplyByTwo(int* ip){
    *ip *= 3;
    return 1;
}

int main(void){

    //Create
    List(int) intList = List_NewList_int();

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Add elements
    List_Prepend(int)(intList, 13);
    List_Add(int)(intList, 6);
    List_Add(int) (intList, 57);
    List_Prepend(int)(intList, 24);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Multply all by 2
    List_ForEach(int) (intList, &MultiplyByTwo);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Sorts
    List_StableSort(int)(intList);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Reverse order
    List_Reverse(int)(intList);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Delete element
    List_DeleteAll(int)(intList, &CanRemove, NULL);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    //Clears list
    List_Clear(int)(intList, NULL);

    printf("#\t#Int List Item Count: %d\n\tList elements are: ", intList->itemCount);
    List_ForEach(int) (intList, &PrintElement);
    printf("\n\n");

    List_Destroy(int)(intList, NULL);

	getchar();

    return 0;
}
