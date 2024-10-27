CC = gcc
LD = $(CC)
CSTANDARD = -std=c11
CFLAGS = -c -Wall -g -lpthread
TARGET = a.out

SOURCES=$(shell find . -type f -iname '*.c')
OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

default: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $^ -o $@

%.o: %.c
		$(CC) $(CSTANDARD) $(CFLAGS) $(CINCLUDE_EXTERNAL_MODULES) $(CINCLUDE_PROJECT_MODULES) $^ -o $@

clean:
		rm -f $(TARGET) $(OBJECTS)
		