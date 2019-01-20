CC=gcc
AS=as
CFLAGS=-std=c17 -g -Wall -O0 -pedantic-errors
RM=rm -f

.PHONY: clean all test

all: doc csx730_list_driver

csx730_list_driver: csx730_list_driver.o csx730_list.o
	$(CC) -o csx730_list_driver $^

csx730_list_driver.o: csx730_list_driver.s
	$(AS) -o $@ $<

csx730_list_driver.s: csx730_list_driver.c csx730_list.h
	$(CC) $(CFLAGS) -S $<

csx730_list.o: csx730_list.s
	$(AS) -o $@ $<

csx730_list.s: csx730_list.c csx730_list.h
	$(CC) $(CFLAGS) -S $<

test: csx730_list_tester
	./csx730_list_tester

csx730_list_tester: csx730_list_tester.o csx730_list.o
	$(CC) -o csx730_list_tester $^

csx730_list_tester.o: csx730_list_tester.s
	$(AS) -o $@ $<

csx730_list_tester.s: csx730_list_tester.c csx730_list.h
	$(CC) $(CFLAGS) -S $<

clean:
	$(RM) csx730_list_driver
	$(RM) csx730_list_tester
	$(RM) *.o
	$(RM) *.s
	$(RM) -r doc

doc: $(wildcard *.c) $(wildcard *.h)
	mkdir -p doc
	doxygen

