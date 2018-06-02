#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedList.h"

int main(int argc, char const *argv[]) {

  int arr[] = {1,3,4,5};
  // int* arr = readArray(5);
  // printArray(arr, 5);
  linked_list_t* list = listFromArray(arr, 4);
  printList(list);
  printf("Current size of list: %ld\n", listSize(list));

  insert(2, 4, list);
  printList(list);
  printf("Current size of list: %ld\n", listSize(list));

  delete(0, list);
  printList(list);
  printf("Current size of list: %ld\n", listSize(list));

  freeList(list);
  return EXIT_SUCCESS;
}

int* readArray(int size) {
  int* arr = calloc(size, sizeof(int));
  for (size_t i = 0; i < size; i++) {
    printf(">");
    scanf("%d", arr + i);
  }
  return arr;
}

void printArray(int* arr, int size) {
  printf("[");
  int i;
  for (i = 0; i < size - 1; i++) {
    printf("%d,", arr[i]);
  }
  printf("%d]\n", arr[i]);
}

linked_list_t* createList() {
  linked_list_t* list = malloc(sizeof(linked_list_t));
  node_t* head = malloc(sizeof(node_t));
  node_t* last = malloc(sizeof(node_t));
  list->head = head;
  list->last = last;
  return list;
}

linked_list_t* listFromArray(int* arr, int size) {
  linked_list_t* list = createList();
  node_t* prev = list->head;

  for (size_t i = 0; i < size; i++) {
    node_t* temp = malloc(sizeof(node_t));
    temp->value = arr[i];

    prev->next = temp;
    prev = temp;
  }

  prev->next = list->last;
  return list;
}

void printList(linked_list_t* list) {
  node_t* curr = list->head;
  printf("[");
  while ((curr = curr->next) != list->last) {
    printf("%d%s", curr->value, (curr->next == list->last) ? "]\n" : ",");
  }
}

size_t listSize(linked_list_t* list) {
  node_t* curr = list->head;
  size_t count = 0;
  while ((curr = curr->next) != list->last) {
    count++;
  }
  return count;
}

void insert(int value, size_t index, linked_list_t* list) {
  assert (index <= listSize(list));
  node_t* prev = list->head;
  node_t* curr = list->head->next;
  for (size_t i = 0; i < index; i++) {
    prev = curr;
    curr = curr->next;
  }
  node_t* newNode = malloc(sizeof(node_t));
  newNode->value = value;
  prev->next = newNode;
  newNode->next = curr;
}

void delete(size_t index, linked_list_t* list) {
  assert (index < listSize(list));
  node_t* prev = list->head;
  node_t* curr = list->head->next;
  for (size_t i = 0; i < index; i++) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  free(curr);
}


void freeList(linked_list_t* list) {
  //free each node
  node_t* curr = list->head;
  while (curr != list->last) {
    node_t* next = curr->next;
    free(curr);
    curr = next;
  }
  //free the last node
  free(curr);
  //free the list
  free(list);
}
