#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plist.h"

char* ensure_capacity(char *buf, int *sz, int pos) {
    if (*sz == pos) {
        char *newbuf = (char*) realloc(buf, *sz * GROWTH_FACTOR);
        if (newbuf == NULL) {
            free(buf);
            *sz = 0;
            return NULL;
        } else {
            *sz *= GROWTH_FACTOR;
            return newbuf;
        }
    } else {
        return buf;
    }
}


char* fetchline(void) {
    int pos = 0;
    int sz  = INITIAL_SIZE;
    char *buf = (char*) malloc(sizeof(char) * sz);
    if (buf == NULL) { return NULL; }
    char ch = getchar();
    while (ch != '\n') {
        buf = ensure_capacity(buf, &sz, pos);
        if (buf == NULL) { return NULL; }
        buf[pos++] = ch;
        ch = getchar();
    }
    buf = ensure_capacity(buf, &sz, pos);
    if (buf == NULL) { return NULL; }
    buf[pos++] = '\0';
    return buf;
}


int main(void){
  plist_t *tarlist = make_list();
  plist_t *taglist = make_list();
  printf("Enter a player's name (press enter to begin game):");
  char *name = fetchline();
  printf(" %s \n",name);
  list_insert(tarlist, name);
  while(strlen(name) > 0){
    printf("Enter another player's name:");
    char *name = fetchline();
    list_insert(tarlist, name);
        printf("you entered %s\n",name);

  }
  printAsTargetRing(tarlist);
  printAsTaggedList(taglist);
  while((list_size(tarlist)) >= 1){
    printf("There are %d people left!\n", list_size(tarlist));
    printf("Enter a target:");
    char *name = fetchline();
    printf("%s \n",name);
    list_remove(tarlist, name);
    list_insert(taglist, name);
    printAsTargetRing(tarlist);
    printAsTaggedList(taglist);
  }
  printAsTargetRing(tarlist);
  printAsTaggedList(taglist);
  free_list(tarlist);
  free_list(taglist);
  return(0);
}
