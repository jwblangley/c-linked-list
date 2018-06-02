CC = gcc
CFLAGS = -Wall -Werror -pedantic -g -std=c99
BUILD = linkedList

all: $(BUILD)

linkedList: linkedList.o

.PHONY: clean
clean:
	rm -f *.o linkedList
