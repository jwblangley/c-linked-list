#ifndef LINLIST
#define LINLIST


//TODO make generic
typedef struct Node {
  struct Node* next;
  int value;
} node_t;

typedef struct LinkedList {
  node_t* head;
  node_t* last;
} linked_list_t;

int* readArray(int size);

void printArray(int* arr, int size);

linked_list_t* createList();

linked_list_t* listFromArray(int* arr, int size);

void printList(linked_list_t* list);

size_t listSize(linked_list_t* list);

void insert(int value, size_t index, linked_list_t* list);

void delete(size_t index, linked_list_t* list);

void freeList();



#endif /* end of include guard: LINLIST */
