#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct StoragableType{
    int priority;
    char shortName[10];
};

struct Storagable{
    char shortName[10];
    int size;
    struct StoragableType storagableType;
};

struct Box{
    struct StoragableType storagableType;
    int size;
    struct Storagable contains[10];
};



int addToStorageTypes(){
    return 0;
};
int addToBox(){
    return 0;
};

struct ListOfStoragables{
    struct Storagable *item;
    struct ListOfStoragables *next;
};
void printListOfStoragables(struct ListOfStoragables *list){
    while(list!=NULL){
        printf("%s", list->item->shortName);
        printf("\n");
        list=list->next;
    }
}

struct DynamicBox{
    struct StoragableType storagableType;
    int size;
    struct ListOfStoragables* head;
};

int addToListOfStoragables(struct ListOfStoragables **head, struct Storagable* newItem){
    /* 1. allocate node */
    struct ListOfStoragables* new_element = (struct ListOfStoragables*) malloc(sizeof(struct ListOfStoragables));

    /* 2. put in the data */
    new_element->item = newItem;

    /* 3. Make next of new node as head */
    new_element->next = (*head);

    /* 4. move the head to point to the new node */
    (*head) = new_element;

    return 0;
}

int addToDynamicBox(struct DynamicBox *box, struct Storagable* newItem){
    struct ListOfStoragables **head=box->head;
    /* 1. allocate node */
    struct ListOfStoragables* new_element = (struct ListOfStoragables*) malloc(sizeof(struct ListOfStoragables));

    /* 2. put in the data */
    new_element->item = newItem;

    /* 3. Make next of new node as head */
    new_element->next = (*head);

    /* 4. move the head to point to the new node */
    (*head) = new_element;

    return 0;
}


void boxDrawer(const char name[10]){
    unsigned int sizeOfName = strlen(name);
    unsigned int separatorNum = (12-sizeOfName)/2;
    printf("--------------\n");

    printf("|");
    for (int i = 0; i < separatorNum; ++i) {
        printf("-");
    }

    printf("%s", name);

    for (int i = 0; i < separatorNum; ++i) {
        printf("-");
    }
    if (sizeOfName%2){
        printf("-");
    }
    printf("|");
    printf("\n");
    printf("--------------\n");
}

int main() {
    struct StoragableType st1 = {0, "clothing"};
    struct StoragableType st2 = {1, "toy"};
    struct StoragableType st3 = {2, "food"};

    struct Storagable s1 = {"Apple", 3, st3};
    struct Storagable s2 = {"Meat", 5, st3};
    struct Storagable s3 = {"Jumper", 10, st1};
    struct Storagable s4 = {"LEGO", 7, st2};
    struct Storagable s5 = {"Figure", 6, st2};

    struct Box b1 = {st1, 5, {s3}};
    struct Box b2 = {st2, 6, {s4,s5}};
    struct Box b3 = {st3, 12, {s1,s2}};


    boxDrawer(b1.storagableType.shortName);
    boxDrawer(b2.storagableType.shortName);
    boxDrawer(b3.storagableType.shortName);

    printf("////////////\n");

    struct ListOfStoragables* head=NULL;

    addToListOfStoragables(&head,&s1);
    addToListOfStoragables(&head,&s2);
    addToListOfStoragables(&head,&s3);

    printListOfStoragables(head);

    printf("\n Code finished\n");
    return 0;
}
