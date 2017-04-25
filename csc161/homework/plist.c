#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plist.h"


plist_t* make_list() {
  plist_t *ret = (plist_t*) malloc(sizeof(plist_t));
  ret->first = NULL;
  return ret;
}

pnode_t* make_node(char *name, pnode_t *next) {
  pnode_t *ret = (pnode_t*) malloc(sizeof(pnode_t));
  ret->name = name;
  ret->next  = next;
  return ret;
}

void free_node(pnode_t *node) {
  free(node->name);
  free(node);
}

void free_list(plist_t *list) {
  pnode_t *cur = list->first;
  while (cur != NULL) {
    pnode_t *t = cur->next;
    cur = t;
  }
  free(list);
}

void list_insert(plist_t *list, char *name) {
    pnode_t *cur = list->first;
    if(list->first == NULL){
      list->first = make_node(name, NULL);
    }
    else{
  while(cur->next != NULL){
    printf("%s\n", cur->name);
      cur = cur->next;
  }
  cur->next = make_node(name, NULL);
}
}

bool list_remove(plist_t *list, char *name) {
 pnode_t *cur = list->first;
 pnode_t *prev = list->first;
 if(strcmp(list->first->name, name) == 0) {
    cur = cur->next;
    list->first = cur;
    free_node(prev);
    return true;
  }
  while(cur != NULL) {
    if(strcmp(cur->name, name) == 0) {
      prev->next = cur->next;
      free_node(cur);
      return true;
      }
      else {
        prev = cur;
        cur = cur->next;
      }
    }
  return false;
}

int list_size(plist_t *list) {
  pnode_t *cur = list->first;
  int val = 0;
  while( cur != NULL) {
    val = val + 1;
    cur = cur->next;
  }
  return val;
}

void printAsTargetRing(plist_t *list) {
  pnode_t *cur = list->first;
  if(cur == NULL){
    printf("There are no targets left!\n");
  }
  else if(cur->next == NULL){
    printf("%s is the final person remaining!", cur->name);
  }
  else{
    while(cur->next != NULL) {
      printf("\t%s is stalking %s\n", cur->name, cur->next->name);
      cur = cur->next;
    }
    printf("\t%s is stalking %s\n", cur->name, list->first->name); 
  }
}

void printAsTaggedList(plist_t *list){
  pnode_t *cur = list->first;
  if(cur != NULL){
    printf("Tagged List: \n");
    while(cur != NULL) {
      printf("\t%s\n", cur->name);
      cur = cur->next;
    }
  }
  else {
    printf("No people have been tagged yet!\n");
  }
}


