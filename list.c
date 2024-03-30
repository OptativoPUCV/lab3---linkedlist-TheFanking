#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList () 
{
     List *L = malloc(sizeof(Node));
     L->head = NULL; 
     return L;
}

void * firstList(List * list) 
{
  if (list == NULL) return NULL;
  if (list->head == NULL) return NULL;
  list->current = list->head;
  return list->current->data;
  
}

void * nextList(List * list) 
{
  if (list == NULL) return NULL;
  if(list->current == NULL) return NULL;
  if(list->current->next == NULL) return NULL;
  list->current = list->current->next;
  return list->current->data;
  
}

void * lastList(List * list) 
{
  if (list == NULL) return NULL; 
  if (list->tail == NULL) return NULL;
  list->current = list->tail;
  return list->current->data;
}

void * prevList(List * list) 
{
    if (list == NULL) return NULL;
    if (list->current == NULL) return NULL;
    if (list->current->prev == NULL) return NULL;
    list->current = list->current->prev;
    
    return list->current->data;
}

void pushFront(List * list, void * data) 
{
  Node *L = createNode(data);
  if (list == NULL || list->head == NULL)
  {
    list->head = L;
    list->tail = L;
  }
  else
  {
    L->next = list->head;
    list->head = L;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node *L = createNode(data);
  if (list->current == NULL)
  {
    list->tail = L;
    list->head = L;
  }
  if (list->current == list->head && list->current != NULL)
  {
    L->next = list->current->next;
    L->prev = list->current;
    list->current->next = L;
    list->current = L;
  }

  if (list->current == list->tail && list->current != NULL)
  {
    L->next = NULL;
    L->prev = list->current;
    L = list->current->next;
    list->tail = L;
    list->current = L;
  }
  
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}