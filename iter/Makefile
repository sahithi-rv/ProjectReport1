# Sample typical Makefile for CSE 597 
#
# Adam Lavely
# Fall 2018

#-#-#-#-#
# Compiler
CC=g++
# Can be any compilers in your path
# Know what modules you have loaded (comment!)
# $ module load gcc/5.3.1

# Flags
CPPFLAGS=-c  -g -std=c++11
#CFLAGS=-c -Wall -O2
#-#-#-#-#

cg: cg.o
	$(CC) -std=c++11 cg.o -o cg

cg.o: cg.cpp
	$(CC) $(CPPFLAGS) cg.cpp

clean:
	rm *o cg

