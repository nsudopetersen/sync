#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFERSIZE 128

typedef struct tinfo {
  unsigned int wait_ns;
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
  tinfo.wait_ns = 500000000;

  if (pthread_create(&tid, &taddr, generate_coordinates, (void *)&tinfo))
    crashme(10);

  pthread_join(tid, NULL);

  return 0;
}

void *generate_coordinates(void *myinfo) {
  for (int i = 0; i < 5; i++) {
    printf("i am alive\n");
    nanosleep(&(struct timespec){.tv_nsec = ((tinfo *)myinfo)->wait_ns}, NULL);
  }
  pthread_exit(0);
}

void crashme(unsigned int e) {
  printf("crashme %u\n", e);
  exit(e);
}
