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

List * createList() {

  List* list = (List*) malloc(sizeof (List));
  list -> head = NULL;
  list -> tail = 0;
  list -> current = NULL;
  
  return list;
}

void * firstList(List * list) {
  if(!list -> head) return NULL;

  list -> current = list -> head;

  return list -> head -> data;
  
}

void * nextList(List * list) {
  if(!list -> current) return NULL;
  
  list -> current = list -> current -> next;

  if(!list -> current) return NULL;
  
  return list -> current -> data;
}
//La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 


void * lastList(List * list) {

  list -> current = list -> current ;
    
  return list -> tail -> data;
}


//La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
  Node* newNodo =createNode(data);
  newNodo -> next = list -> head;

  if(list -> head){
    list -> head -> prev = newNodo;
  }
  list -> head = newNodo;
  newNodo -> prev = NULL;
  
  list -> tail = newNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
  list->current = list->head;
  return popCurrent(list);
}

void * popBack(List * list) {
  list->current = list->tail;
  return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}