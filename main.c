#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 128

typedef struct tinfo {
  unsigned int wait_ms;
} tinfo;

static int buffer[BUFFERSIZE];
static unsigned int consume_at;
static unsigned int produce_at;

void *generate_coordinates(void *);
void crashme(unsigned int);

int main(int argc, char **argv) {
  pthread_t tid;
  pthread_attr_t taddr;
  pthread_attr_init(&taddr);
  tinfo tinfo;
  tinfo.wait_ms = 500;

  if (pthread_create(&tid, &taddr, generate_coordinates, (void *)&tinfo))
    crashme(10);

  return 0;
}

void *generate_coordinates(void *tinfo) {
  // (tinfo) *tinfo
  for (int i = 0; i < 5; i++)
    printf("i am alive\n");
  pthread_exit(0);
}

void crashme(unsigned int e) {
  printf("crashme %u\n", e);
  exit(e);
}