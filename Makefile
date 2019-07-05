OBJS = src/parser.c src/mpc.c

CC = gcc

COMPILE_FLAGS = -std=c99 -Wall

OBJ_NAME = LFPprompt

all : $(OBJS)
	$(CC) $(COMPILE_FLAGS) $(OBJS) -o $(OBJ_NAME)
