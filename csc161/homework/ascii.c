#include <stdio.h>

void reverse_triangle(void) {
  for (int i = 6; i >= 0; i--) {
    for (int j = i; j > 0; j--) {
      printf("*") ;
    }
    printf("\n");
  }
}

void pyramid(void) {
  for (int i = 6; i>0; i--) {
    for (int j = 0; j < (i-1); j++) {
      printf(".") ;
    }
    for (int k = 13; k > (i*2); k--) {
      printf("#") ;
    }
    for(int l = 0; l < (i-1); l++) {
      printf(".");
    }
    printf("\n");
  }
}

int main(void) {
  reverse_triangle();
  pyramid();
  return 0;
}
