#include <stdio.h>
#define NUM_STEPS 3

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


void peak(void) {
  for (int i = 5; i > 0; i--) {
    for (int j = 2 * NUM_STEPS + i; j >= 0; j--) {
        printf(" "); }
          printf(" /"); 
    for (int k = 5-i; k > 0; k--) {
      printf("/\\"); }
    printf("\\\n");
  }
}

void tower(void) {
  for (int i = 3; i > 0; i--) {
    if (i != 2) {
      for (int j = (2*NUM_STEPS) + 2; j >= 0; j--) {
        printf("-"); }
      printf("| %%    %% |");
      for (int l = (2*NUM_STEPS) + 2; l >= 0; l--) {
      printf("-"); }
        printf("\n");
    } 
    else {
      for (int k = NUM_STEPS; k >= 0; k--) {
        printf(" o"); }
          printf(" | %%    %% |"); 
       for (int m = NUM_STEPS; m >= 0; m--) {
         printf(" o"); }
       printf("\n"); } } }

  
void steps(void) {
  for (int i = NUM_STEPS; i > 0; i--) {
    for (int j = 3; j > 0; j--) {
      if (j = 3) {
    for (int k = i; k >=0; k--) {
          printf("-^"); }
      printf("-/");
      for (int l =(4 * (NUM_STEPS - i)) + 7; l >= 0 ; l--) {
      printf("-"); }
      printf("\\-");
      for (int m = i; m >=0; m--) {
        printf("^-"); }
      printf("\n"); }
        if (j = 2) {
          for (int n = i; n >= 0; n--) {
            printf("^-"); }
          printf("/");
          for (int o =(4 * (NUM_STEPS - i)) + 9; o >= 0; o--) {
          printf("-"); }
          printf("\\");
          for (int p = i; p >= 0; p--) {
            printf("-^"); }
          printf("\n"); }
          if (j = 1) {
            for (int q = 2 * i; q >= 0; q--) {
              printf(" "); }
            printf(" |");
            for (int r = (4 * (NUM_STEPS - i)) + 9; r >= 0; r--) {
             printf("="); }
            printf("|\n"); }
    }
  }
}


  
void base(void) {
  for (int i = 7; i > 0; i--) {
    if (i = 7) {
    for (int j = 3; j > 0; j--) {
      printf(" "); }
    printf("/");
    for (int k =(4 * (NUM_STEPS - 1)) + 11; k >= 0; k--) {
      printf(" "); }
    printf("\\ \n"); }
    if (i = 6) {
      for (int l = 2; l > 0; l--) {
        printf(" "); }
        printf("/  ");
        for (int m = (4 * (NUM_STEPS - 1)) + 9; m>= 0; m--) {
          printf("="); }
        printf("  \\ \n"); }
    if (i = 5) {
      printf(" /  / ");
      for (int n = (4 * (NUM_STEPS -1)) + 7; n>= 0; n--) {
        printf("\""); }
      printf(" \\  \\ \n");
    }
    if (i = 4) {
      printf("|  |   ");
      for (int o = (4 * (NUM_STEPS - 1)) + 5; o>= 0; o--) {
        printf("\""); }
      printf("   |  | \n"); }
    if (i = 3) {
      printf(" \\  \\ ");
      for (int o = (4 * (NUM_STEPS - 1)) + 7; o>= 0; o--) {
        printf("\""); }
      printf(" /  / \n"); }
    if (i = 2) {
      printf("  \\  ");
      for (int p = (4 * (NUM_STEPS - 1)) + 9; p>= 0; p--) {
            printf("="); }
          printf("  / \n"); }
    if (i = 1) {
      printf("   \\");
      for (int q = (4 * (NUM_STEPS - 1)) + 11; q>=0; q--) {
        printf("_"); }
      printf("/ \n"); }
}
}

  
void rocky_steps(void) {
  peak();
  tower();
  steps();
  base();
}

int main(void) {
  reverse_triangle();
  pyramid();
  rocky_steps();
  return 0;
}
