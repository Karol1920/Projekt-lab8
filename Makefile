CC = gcc
CFLAGS = -Wall -std=c99
COMMON_OBJS = gauss.o backsubst.o

all: gauss

gauss: main.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o gauss main.o $(COMMON_OBJS)

test: test_gauss
	./test_gauss

test_gauss: test_gauss.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o test_gauss test_gauss.o $(COMMON_OBJS)

main.o: main.c gauss.h
	$(CC) $(CFLAGS) -c main.c

gauss.o: gauss.c gauss.h
	$(CC) $(CFLAGS) -c gauss.c

backsubst.o: backsubst.c gauss.h
	$(CC) $(CFLAGS) -c backsubst.c

test_gauss.o: test_gauss.c gauss.h
	$(CC) $(CFLAGS) -c test_gauss.c

clean:
	rm -f *.o gauss test_gauss