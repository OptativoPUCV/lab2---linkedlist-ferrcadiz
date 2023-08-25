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

void * lastList(List * list) {
  if(!list -> tail) return NULL;
  
  list -> current = list -> tail;
    
  return list -> tail -> data;
}

void * prevList(List * list) {
  if(!list -> current) return NULL;

  list -> current = list -> current -> prev;

  if(!list -> current) return NULL;

  return list -> current -> data;
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
  Node* newNodo =createNode(data);
  
  newNodo -> next = list -> current -> next;
  newNodo -> prev = list -> current;

  if(list -> current -> next != NULL){
    list -> current -> next -> prev = newNodo;
  }
  
  list -> current -> next = newNodo;

  list -> tail = newNodo;
}

void * popFront(List * list) {
  list->current = list->head;
  return popCurrent(list);
}

void * popBack(List * list) {
  list->current = list->tail;
  return popCurrent(list);
}
//6. Programe la función `void* popCurrent(List * list)`, la cual elimina el nodo que está en la posición del current de la lista enlazada, y además retorna el **dato** del nodo eliminado.
// **Nota**: El current debe quedar apuntando al nodo siguiente del eliminado.
void * popCurrent(List * list) {

  if(list -> current -> prev != NULL){
    list -> current -> prev -> next = list -> current -> next;
  }
  else{
    list -> head = list -> current -> next;
  }

  if(list -> current -> next != NULL){
    list -> current -> next -> prev = list -> current -> prev;
    list -> current -> prev -> next = list -> current -> next;
    list -> current = list -> current -> next;
  }
  else{
    list -> tail = list -> current -> prev;
    list -> current = NULL;
  }

  return list -> current -> data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}