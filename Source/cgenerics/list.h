/** list.h
 ** A geneic type linked list
 **
 ** @author Diogo Fernandez Rocha
 **
 ** Use:
 ** Define LTYPE as the type of this list
 ** Create a Comparer function for LTYPE. It must receive two LTYPE arguments, a and b,
 ** and the returns must be: -1 if a < b, 0 if a == b and 1 if a > b
 ** Assign the function address to "Comparer_Type(LTYPE) Comparer(LTYPE)"
 **
 ** Functions and types are called like this: List_DoStuff (LTYPE) (Args)
 **/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* PREPROCESSOR DEFINES */
#define TOKENPASTE(x, y) x ## y

#define List_Node(T) TOKENPASTE(List_Node_, T) //Node type: List_Node_LTYPE
#define _struct_list_node(T) TOKENPASTE(struct_node_, T) //Node structure: struct_node_LTYPE
#define List(T) TOKENPASTE(List_, T) //List type: List_LTYPE
#define _struct_list(T) TOKENPASTE(struct_list_, T) //List struct: struct_list_LTYPE

#define Comparer(T) TOKENPASTE(Comparer_, T) //Compare function: Compare_LYTPE
#define Comparer_Type(T) TOKENPASTE(comparerType_, T) //Function pointer to a comparer
#define Predicate(T) TOKENPASTE(predicate_, T)
#define Iterator(T) TOKENPASTE(iterator_, T)

#define NullValue(T) TOKENPASTE(T, _NullValue) //Returns a T type with all bits set to 0

#define List_New(T) TOKENPASTE(List_NewList_, T) //NewList
#define List_IsEmpty(T) TOKENPASTE(List_IsEmpty_, T) //Is empty

#define List_Prepend(T) TOKENPASTE(List_Prepend_, T) //Prepend Element
#define List_Append(T) TOKENPASTE(List_Append_, T) //Append Element
#define List_Add(T) List_Append(T) //Add element (append)
#define List_Insert(T) TOKENPASTE(List_Insert_, T) //InsertAt

#define List_GetElement(T) TOKENPASTE(List_GetElement_, T)//ElementAtIndex
#define List_IndexOf(T) TOKENPASTE(List_IndexOf_, T) //IndexOf
#define List_Contains(T) TOKENPASTE(List_Contains_, T) //Contains
#define List_GetHead(T) TOKENPASTE(List_GetHead_, T) //GetHead

#define List_Find(T) TOKENPASTE(List_Find_, T) //Find
#define List_Delete(T) TOKENPASTE(List_Delete_, T) //Delete

#define List_FindAll(T) TOKENPASTE(List_FindAll_, T) //FindAll
#define List_DeleteAll(T) TOKENPASTE(List_DeleteAll_, T) //DeleteAll

#define List_Clear(T) TOKENPASTE(List_Clear_, T) //Clear
#define List_Destroy(T) TOKENPASTE(List_Destroy_, T) //Destroy

#define List_ToArray(T) TOKENPASTE(List_ToArray_, T) //ToArray

#define List_Sort(T) TOKENPASTE(List_Sort_, T)//Sort (QuickSort)
#define List_StableSort(T) TOKENPASTE(List_StableSort_, T) //StableSort (MergeSort)

#define List_Reverse(T) TOKENPASTE(List_Reverse_, T) //Reverse
#define List_ForEach(T) TOKENPASTE(List_ForEach_, T) //ForEach

typedef char (*Comparer_Type(LTYPE))(LTYPE,LTYPE);
Comparer_Type(LTYPE) Comparer(LTYPE); //Needs to be defined on main program

typedef char (*Predicate(LTYPE)) (LTYPE);
typedef char (*Iterator(LTYPE)) (LTYPE*);

/** Node type*/
typedef struct _struct_list_node(LTYPE) List_Node(LTYPE);

struct _struct_list_node(LTYPE){
    LTYPE item;
    List_Node(LTYPE) * next;
};

/** List type */
typedef struct _struct_list(LTYPE) {
    int itemCount;
    List_Node(LTYPE) * head;
    List_Node(LTYPE) * tail;
} *List(LTYPE);

/** Null Value */
LTYPE   NullValue(LTYPE)();

/** New list function*/
List(LTYPE)    List_New(LTYPE) ();

/** Is empty function */
char    List_IsEmpty(LTYPE) (List(LTYPE) list);

/** Prepend function*/
char    List_Prepend(LTYPE) (List(LTYPE) list, LTYPE item);

/** Append function */
char    List_Append(LTYPE) (List(LTYPE) list, LTYPE item);

/** Get an element by index */
LTYPE    List_GetElement(LTYPE) (List(LTYPE) list, int index);

/** Insert at index */
char    List_Insert(LTYPE) (List(LTYPE) list, int index, LTYPE item);

/** Returns the index of the first ocurrence an element, if it exists */
int     List_IndexOf(LTYPE) (List(LTYPE) list, LTYPE item);

/** Checks if the list contains a certain element */
char    List_Contains(LTYPE) (List(LTYPE) list, LTYPE item);

/** Returns the head element of a list*/
LTYPE   List_GetHead(LTYPE) (List(LTYPE) list);

/** Finds an element that matches a given predicate */
LTYPE   List_Find(LTYPE) (List(LTYPE list), Predicate(LTYPE) p);

/** Deletes an element that matches a given predicate */
char    List_Delete(LTYPE) (List(LTYPE list), Predicate(LTYPE) p, Predicate(LTYPE) destroy);

/** Allocates an array and fills it with all list elements that match a given predicates */
int     List_FindAll(LTYPE) (List(LTYPE) list, Predicate(LTYPE) p, LTYPE** results);

/** Deletes all elements that match a given predicate */
int     List_DeleteAll(LTYPE) (List(LTYPE list), Predicate(LTYPE) p, Predicate(LTYPE) destroy);

/** Clears all elements of a list*/
int     List_Clear(LTYPE) (List(LTYPE) list, Predicate(LTYPE) destroy);

/** Clears and deallocates a list */
int     List_Destroy(LTYPE) (List(LTYPE) list, Predicate(LTYPE) destroy);

/** Returns an allocated array with all list items. Its size is equal to list->itemCount */
LTYPE*  List_ToArray(LTYPE) (List(LTYPE) list);

/** Sorts the list in min-order, based on the comparer function */
void    List_Sort(LTYPE) (List(LTYPE) list);

/** Sorts the list in min-order, based on the comparer function. Uses stable algorithm*/
void    List_StableSort(LTYPE) (List(LTYPE) list);

/** Reverses the element order in a list */
void    List_Reverse(LTYPE) (List(LTYPE) list);

/** Executes iterator function in every element in the list */
char     List_ForEach(LTYPE) (List(LTYPE) list, Iterator(LTYPE) it);

/** -------------- IMPLEMENTATIONS ---------------- **/

/** Null value */
LTYPE   NullValue(LTYPE)(){
    LTYPE nullValue;
    memset(&nullValue, 0, sizeof(LTYPE));
    return nullValue;
}

/** New list function*/
List(LTYPE)    List_New(LTYPE) (){
    List(LTYPE) newList = malloc(sizeof(struct _struct_list(LTYPE)));

    if(newList == NULL)
        return NULL;

    newList->itemCount = 0;

    newList->head = malloc(sizeof(List_Node(LTYPE)));

    if(newList->head == NULL){
        free(newList);
        return NULL;
    }

    newList->head->next = NULL;
    newList->tail = newList->head;

    newList->head->item = NullValue(LTYPE)();

    return newList;
}

/** Is empty function */
char    List_IsEmpty(LTYPE) (List(LTYPE) list){
    if(list != NULL)
        return (list->head == list->tail);
    else
        return 1;
}

/** Prepend function*/
char    List_Prepend(LTYPE) (List(LTYPE) list, LTYPE item){
    if(List_IsEmpty(LTYPE)(list)) return List_Append(LTYPE) (list, item);

    List_Node(LTYPE)* newNode = malloc(sizeof(List_Node(LTYPE)));

    if(newNode == NULL) return 0;

    newNode->item = item;
    newNode->next = list->head->next;

    (list->itemCount)++;
    list->head->next = newNode;

    return 1;
}

/** Append function*/
char    List_Append(LTYPE) (List(LTYPE) list, LTYPE item){
    List_Node(LTYPE)* newNode = malloc(sizeof(List_Node(LTYPE)));

    if(newNode == NULL) return 0;

    newNode->item = item;
    newNode->next = NULL;

    (list->itemCount)++;
    list->tail->next = newNode;
    list->tail = newNode;

    return 1;
}

/** Get an element by index*/
LTYPE    List_GetElement(LTYPE) (List(LTYPE) list, int index){
    if(index > list->itemCount || index < 0){
        fprintf(stderr, "ERROR: Tried to access item in out of bounds index.\n");
        return NullValue(LTYPE)();
    }

    int i;
    List_Node(LTYPE)* aux = list->head;
    for(i = 0; i <= index; i++)
        aux = aux->next;

    return aux->item;
}

/** Insert at index function*/
char    List_Insert(LTYPE) (List(LTYPE) list, int index, LTYPE item){
    if(index > list->itemCount || index < 0){
        fprintf(stderr, "ERROR: Tried to insert item at out of bounds index.\n");
        return 0;
    }

    if(index == list->itemCount) return List_Append(LTYPE) (list, item);
    if(index == 0) return List_Prepend(LTYPE) (list, item);

    //If the index is not the last nor the first

    List_Node(LTYPE)*  newNode = malloc(sizeof(List_Node(LTYPE)));

    if(newNode == NULL) return 0;

    newNode->item = item;

    int i;
    List_Node(LTYPE)* aux = list->head;
    for(i = 0; i < index; i++)
        aux = aux->next;

    newNode->next = aux->next;
    aux->next = newNode;
    (list->itemCount)++;

    return 1;
}

/** Returns the index of the first ocurrence an element, if it exists */
int     List_IndexOf(LTYPE) (List(LTYPE) list, LTYPE item){
    List_Node(LTYPE)* aux;
    int i = 0;
    for(aux = list->head->next; aux != NULL; aux = aux->next){
        if(Comparer(LTYPE)(aux->item, item) == 0) return i;
        i++;
    }

    return -1;
}

/** Checks if the list contains a certain element */
char    List_Contains(LTYPE) (List(LTYPE) list, LTYPE item){
    List_Node(LTYPE)* aux;
    for(aux = list->head->next; aux != NULL; aux = aux->next){
        if(Comparer(LTYPE)(aux->item, item) == 0) return 1;
    }

    return 0;
}

/** Returns the head element of a list */
LTYPE   List_GetHead(LTYPE) (List(LTYPE) list){
    if(list->itemCount == 0)
        return NullValue(LTYPE)();

    return list->head->next->item;
}

/** Finds a element that checks with a given predicate */
LTYPE   List_Find(LTYPE) (List(LTYPE list), Predicate(LTYPE) p){
    List_Node(LTYPE)* aux;
    for(aux = list->head->next; aux != NULL; aux = aux->next){
        if(p(aux->item)) return aux->item;
    }

    return NullValue(LTYPE)();
}

/** Deletes an element that matches a given predicate */
char    List_Delete(LTYPE) (List(LTYPE list), Predicate(LTYPE) p, Predicate(LTYPE) destroy){
    List_Node(LTYPE)* aux;
    for(aux = list->head; aux->next != NULL; aux = aux->next){
        if(p(aux->next->item)){
            List_Node(LTYPE)* toDelete = aux->next;
            aux->next = aux->next->next;

            if(list->tail == toDelete)
                list->tail = aux;

            if(destroy) destroy(toDelete->item);
            free(toDelete);
            (list->itemCount)--;
            return 1;
        }
    }

    return 0;
}

/** Allocates an array and fills it with all list elements that match a given predicates */
int     List_FindAll(LTYPE) (List(LTYPE) list, Predicate(LTYPE) p, LTYPE** results){
    *results = calloc(list->itemCount, sizeof(LTYPE));
    int i = 0; List_Node(LTYPE)* aux;

    if(!*results){
        fprintf(stderr, "Failed to allocate memory in List_FindAll.\n");
        return 0;
    }

    for(aux = list->head->next; aux != NULL; aux = aux->next){
        if(p(aux->item))
            (*results)[i++] = aux->item;
    }

    realloc(*results, sizeof(LTYPE));
    return i;

}

/** Deletes all elements that match a given predicate */
int    List_DeleteAll(LTYPE) (List(LTYPE list), Predicate(LTYPE) p, Predicate(LTYPE) destroy){
    List_Node(LTYPE)* aux;
    int delCount = 0;
    for(aux = list->head; aux->next != NULL; aux = aux->next){
        while(p(aux->next->item)){
            List_Node(LTYPE)* toDelete = aux->next;
            aux->next = aux->next->next;

            if(list->tail == toDelete)
                list->tail = aux;

            if(destroy) destroy(toDelete->item);
            free(toDelete);
            (list->itemCount)--;
            delCount++;

            if(aux->next == NULL)
                break;
        }

        if(aux->next == NULL)
            break;
    }

    return delCount;
}

/** Clears all elements of a list */
int     List_Clear(LTYPE) (List(LTYPE) list, Predicate(LTYPE) destroy){
    List_Node(LTYPE)* aux = list->head;
    int delCount = 0;
    while(aux->next != NULL){
        List_Node(LTYPE)* toDelete = aux->next;
        aux->next = aux->next->next;
        if(destroy) destroy(toDelete->item);
        free(toDelete);
        (list->itemCount)--;
        delCount++;
    }

    list->tail = list->head;
    return delCount;
}

/** Clears and deallocates a list */
int     List_Destroy(LTYPE) (List(LTYPE) list, Predicate(LTYPE) destroy){
    int delCount = List_Clear(LTYPE) (list, destroy);
    free(list->head);
    free(list);
    return delCount;
}

/** Returns an allocated array with all list items. Its size is equal to list->itemCount */
LTYPE*  List_ToArray(LTYPE) (List(LTYPE) list){
    LTYPE* retArray = calloc(list->itemCount, sizeof(LTYPE));

    if(!retArray){
        fprintf(stderr, "Failed to allocate memory in List_ToArray.\n");
        return 0;
    }

    int i = 0; List_Node(LTYPE)* aux;

    for(aux = list->head->next; aux != NULL; aux = aux->next){
        retArray[i++] = aux->item;
    }

    return retArray;
}

/** Sorts the list in min-order, based on the comparer function */
/* QUICKSORT IMPLEMENTATION */
#define _QuickSort_Partition(T) TOKENPASTE(_QuickSort_Partition_, T) //Quick sort implementation functions
#define _QuickSort_Recursion(T) TOKENPASTE(_QuickSort_Recursion_, T)

//Partition
static List_Node(LTYPE)* _QuickSort_Partition(LTYPE)(List_Node(LTYPE)* head, List_Node(LTYPE)* end, List_Node(LTYPE)** newHead, List_Node(LTYPE)** newEnd){
    List_Node(LTYPE)* pivot = end;
    List_Node(LTYPE) *prev = NULL, *cur = head, *tail = pivot;

    //Begin partitioning
    while(cur != pivot){
        if(Comparer(LTYPE)(cur->item, pivot->item) == -1){ //If the item of cur is smaller than the item of the pivot
            if(*newHead == NULL) //First item smaller than the pivot becomes the new head
                *newHead = cur;

            prev = cur;
            cur = cur->next;

        }
        else{ //item of cur is bigger, must change positions

            //Move cur to the tail
            if(prev)
                prev->next = cur->next;

            List_Node(LTYPE)* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    //Changes head if neccessary
    if(*newHead == NULL)
        *newHead = pivot;

    //New end will be the last node
    *newEnd = tail;

    return pivot;
}

//Recursion
static List_Node(LTYPE)* _QuickSort_Recursion(LTYPE)(List_Node(LTYPE)* head, List_Node(LTYPE)* tail){
    if(!head || head == tail) //if number of elements is less than or equal to one
        return head;

    List_Node(LTYPE) *newHead = NULL, *newTail = NULL;

    List_Node(LTYPE)* pivot = _QuickSort_Partition(LTYPE)(head, tail, &newHead, &newTail);

    if(newHead != pivot){ //No need for sorting the left part if the pivot is the head
        //Breaks the list
        List_Node(LTYPE)* tmp = newHead;
        while(tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;

        //sorts left list
        newHead = _QuickSort_Recursion(LTYPE)(newHead, tmp);

        //Relinks the left part
        tmp = newHead;
        while(tmp != NULL && tmp->next != NULL) tmp = tmp->next;
        tmp->next = pivot;
    }

    //Sorts right list
    pivot->next = _QuickSort_Recursion(LTYPE)(pivot->next, newTail);

    return newHead;

}

//Call
void    List_Sort(LTYPE) (List(LTYPE) list){
    list->head->next = _QuickSort_Recursion(LTYPE)(list->head->next, list->tail);

    //restore tail
    list->tail = list->head->next;

    while(list->tail != NULL && list->tail->next != NULL) list->tail = list->tail->next;
    return;
}

/* END OF QUICKSORT IMPLEMENTATION */

/** Sorts the list in min-order, based on the comparer function. Uses stable algorithm*/
/* MERGE SORT IMPLEMENTATION */
#define _MergeSort_Split(T) TOKENPASTE(_MergeSort_Split_, T) //Merge sort implementation functions
#define _MergeSort_Merge(T) TOKENPASTE(_MergeSort_Merge_, T)
#define _MergeSort_Recursion(T) TOKENPASTE(_MergeSort_Recursion_, T)
//Splitting function
static void _MergeSort_Split(LTYPE)(List_Node(LTYPE)* src, List_Node(LTYPE)** front, List_Node(LTYPE)** back){

    //If length is 0 or 1
    if(!src || !src->next){
        *front = src;
        *back = NULL;
    }

    List_Node(LTYPE) *fast = src->next, *slow = src;

    while (fast)
    {
      fast = fast->next;
      if (fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *front = src;
    *back = slow->next;

    //Disconnect left from right
    slow->next = NULL;
}

//Splitting function
static List_Node(LTYPE)* _MergeSort_Merge(LTYPE)(List_Node(LTYPE)* left, List_Node(LTYPE)* right){
    if(!left)
        return right;
    if(!right)
        return left;

    List_Node(LTYPE)* retValue;

    if(Comparer(LTYPE)(left->item, right->item) <= 0){
        retValue = left;
        retValue->next = _MergeSort_Merge(LTYPE)(left->next, right);
    }
    else{
        retValue = right;
        retValue->next = _MergeSort_Merge(LTYPE)(left, right->next);
    }

    return retValue;
}

//Recursion
static void _MergeSort_Recursion(LTYPE) (List_Node(LTYPE)** headRef){
    List_Node(LTYPE)* head = *headRef;
    List_Node(LTYPE) *left, *right;

    //Base case: 1 or 0 elements
    if(head == NULL || head->next == NULL)
        return;

    //Split
    _MergeSort_Split(LTYPE)(head, &left, &right);

    //Sort
    _MergeSort_Recursion(LTYPE)(&left);
    _MergeSort_Recursion(LTYPE)(&right);

    //Merge
    *headRef = _MergeSort_Merge(LTYPE)(left, right);
}

//Interface
void    List_StableSort(LTYPE) (List(LTYPE) list){
    _MergeSort_Recursion(LTYPE)(&(list->head));

    //Restore tail
    list->tail = list->head->next;

    while(list->tail != NULL && list->tail->next != NULL) list->tail = list->tail->next;
    return;
}

/** Reverses the element order in a list */
void    List_Reverse(LTYPE) (List(LTYPE) list){
    List_Node(LTYPE) *prev = NULL, *current = list->head->next, *next;

    list->tail = list->head->next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head->next = prev;
}

/** Executes iterator function in every element in the list */
char     List_ForEach(LTYPE) (List(LTYPE) list, Iterator(LTYPE) it){
    List_Node(LTYPE)* aux;
    char retValue = 1;
    for(aux = list->head->next; aux != NULL; aux = aux->next){
        retValue = retValue && it(&(aux->item));
    }

    return retValue;
}
