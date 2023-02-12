#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct mp3 {
  char *name;
  char *song;
  int runtime;
  struct mp3 *prev;  
  struct mp3 *next;
} mp3_t; 
