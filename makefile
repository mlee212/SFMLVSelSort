#Makefile for "sort" C++ application
#Created by Matthew Lee 4/22/20

PROG = sort
CC = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -g -Wall
OBJS = main.o

# Link cmd
$(PROG) : $(OBJS) $(LDFLAGS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

# Compilation cmd
main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)