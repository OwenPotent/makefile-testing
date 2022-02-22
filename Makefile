CC = gcc
CFLAGS = -Wall -g -O2 -std=c99

C_Files = $(wildcard *.c)
OBJ = test.exe

all:
	$(CC) $(CFLAGS) -o $(OBJ) $(C_Files)