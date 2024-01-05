

CC = mpicc

CFLAGS = -c -Wall -std=c11 -g -o2 -I/usr/include/openmpi-x86_64/ -DNDEBUG 

LDFLAGS = 

SRCS= main.c functions.c

OBJS = main.o functions.o

all: project $(SRCS)

project: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o project
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o
functions.o: functions.c
	$(CC) $(CFLAGS) functions.c -o functions.o

clean:
	rm -rf $(OBJS)