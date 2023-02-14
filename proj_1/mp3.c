#include "mp3.h"

extern mp3_t *head;

void insert(char *name, char *song, int runtime, mp3_t *prev, mp3_t *next)
{
  mp3_t *temp, *mp3;

  mp3 = (mp3_t *) malloc(sizeof(mp3_t));        // malloc space for MP3
  mp3->name = (char *) malloc(strlen(name) + 1);  // malloc space for name
  mp3->song = (char *) malloc(strlen(song) + 1);
  mp3->prev = (mp3_t *) malloc(sizeof(mp3_t));
  mp3->next = (mp3_t *) malloc(sizeof(mp3_t));

  strcpy(mp3->name, name);                        // "assign" name via copy
  strcpy(mp3->song, song);
  mp3->runtime = runtime;
  mp3->prev = prev;
  mp3->next = next;

  if (head == NULL)
  {
    head = mp3;               // add the first MP3
  }
  else
  {
    temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = mp3;         // append to the tail/end
    mp3->prev = temp;
  }
}

void delete(char *name)
{
  mp3_t *temp = head, *rmv = NULL;

  while (temp != NULL){
    if (temp == head && strcmp(temp->name, name) == 0){
      head = temp->next;
      head->prev = NULL;
      free(temp->name);
      free(temp->song);
      free(temp);
      temp = head;
    } else if (strcmp(temp->name, name) == 0) {
        rmv = temp;
	rmv->prev->next = temp->next;
        temp = temp->next;
        free(rmv->name);
        free(rmv->song);
	free(rmv);
      }
    else temp = temp->next;
  }
}

void freeList()
{
  mp3_t *temp;
  int  i = 0;

  while (head != NULL) {
    temp = head;
    head = head->next; // point to next MP3 record
    free(temp->name);  // first free name inside MP3 record
    free(temp->song);
    free(temp->prev);
    free(temp->next);
    free(temp);        // then free MP3 record
    i++;
  }
  printf("free %d MP3 records...\n", i);
}

void printIO()
{
  mp3_t *temp;
  int  i = 0;

  temp = head;

  while (temp != NULL) {
    printf("(%d)--%s--%s--%d--\n", ++i, temp->name, temp->song, temp->runtime);
    temp = temp->next;
  }
}

void printRev()
{

}
