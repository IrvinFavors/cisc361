//
// adapted from http://www.cprogramming.com/snippets/source-code/singly-linked-list-insert-remove-add-count
//

#include "mp3.h"
#define  BUFFERSIZE 128

mp3_t *head;

void insert(char *name, char *song, int runtime, mp3_t *prev, mp3_t *next);
void print();
void freeList();

int main()
{
  int i, runtime, len;
  struct node *n;
  char name[BUFFERSIZE], song[BUFFERSIZE], c;

  head = NULL;

  while (1) {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("(1) Insert\n");
    printf("(2) Display\n");
    printf("(3) Delete\n");
    printf("(4) Exit\n");
    printf("Enter your choice : ");
    if (scanf("%d%c", &i, &c) <= 0) {          // use c to capture \n
        printf("Enter only an integer...\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1: printf("Enter the Artist's name: ");
		if (fgets(name, BUFFERSIZE , stdin) != NULL) {
                  len = strlen(name);
                  name[len - 1] = '\0';   // override \n to become \0
                } else {
                    printf("wrong name...");
                    exit(-1);
                  }
		printf("Enter the Song title: ");
		if (fgets(song, BUFFERSIZE , stdin) != NULL) {
                  len = strlen(song);
                  song[len - 1] = '\0';   // override \n to become \0
                } else {
                    printf("wrong name...");
                    exit(-1);
                  }
                printf("Enter the track runtime: ");
                scanf("%d%c", &runtime, &c);  // use c to capture \n

                printf("[%s] [%s] [%d]\n", name, song, runtime);
                insert(name, song, runtime, NULL, NULL);
                break;
        case 2: if (head == NULL)
                  printf("List is Empty\n");
                else
                  print();
                break;
        case 3: printf("delete function has not been implemented...\n");
                break;
        case 4: freeList();
                return 0;
        default: printf("Invalid option\n");
        }
    }
  }
  return 0;
}
