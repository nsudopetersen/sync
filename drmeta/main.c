#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLS_COUNT 3
#define MSGSIZE_ORG 128
#define MSGSIZE_TR MSGSIZE_ORG * 8

static char *trtable[3][SYMBOLS_COUNT] = {
    [0][0] = "A",  [1][0] = "1", [2][0] = "0110", [0][1] = "B", [1][1] = "011",
    [2][1] = "01", [0][2] = "C", [1][2] = "01",   [2][2] = "1"};

static struct {
  char pos;
  char message[MSGSIZE_ORG];
} message_org;
static struct {
  char pos_a;
  char pos_b;
  char message[2][MSGSIZE_TR];
} message_tr;

static unsigned int attempts_made[MSGSIZE_ORG];

void insert_next(void);
void crashme(unsigned int);

int main(int argc, char **argv) { return 0; }

void insert_next(void) {
  memcpy(&message_org.message[message_org.pos],
         trtable[0][attempts_made[message_org.pos]],
         strlen(trtable[0][attempts_made[message_org.pos]]));

  memcpy(&message_tr.message[0][message_tr.pos_a],
         trtable[1][attempts_made[message_org.pos]],
         strlen(trtable[1][attempts_made[message_org.pos]]));
  memcpy(&message_tr.message[1][message_tr.pos_b],
         trtable[2][attempts_made[message_org.pos]],
         strlen(trtable[2][attempts_made[message_org.pos]]));

  /* Increase pos_a, pos_b */

  if (message_tr.pos_a >= message_tr.pos_b) {
    if (!strncmp(message_tr.message[0], message_tr.message[1],
                 message_tr.pos_a)) {
    }
  }

  if (attempts_made[message_org.pos]++ >
      SYMBOLS_COUNT) { /* Handle no more attempts on this stage */
  }
}

void crashme(unsigned int e) {
  printf("crashme %u\n", e);
  exit(e);
}
