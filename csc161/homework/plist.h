#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2

typedef struct pnode {
  char *name;
  struct pnode *next;
} pnode_t;

struct plist {
pnode_t *first;
};

typedef struct plist plist_t;


plist_t* make_list();

pnode_t* make_node(char *name, pnode_t *next);

void free_node(pnode_t *node);

void free_list(plist_t *list);

void list_insert(plist_t *list, char *name);

bool list_remove(plist_t *list, char *name);

int list_size(plist_t *list);

void printAsTargetRing(plist_t *list);

void printAsTaggedList(plist_t *list);
