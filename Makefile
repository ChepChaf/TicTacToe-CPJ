
CC=g++

PROG=main

CPPFLAGS=-Wall
LDFLAGS=-lconio_64
OBJS=main.cpp board.cpp tic_tac_toe.cpp game_gui.cpp game_input.cpp
DEBUGFLAGS=-DDEBUG=true -g

all:
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) $(CPPFLAGS)

debug:
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) $(CPPFLAGS) $(DEBUGFLAGS)

default: all

