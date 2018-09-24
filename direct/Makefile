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

direct_lu: direct_lu.o
	$(CC) -std=c++11 direct_lu.o -o direct_lu

direct_lu.o: direct_lu.cpp
	$(CC) $(CPPFLAGS) direct_lu.cpp

ldlt: ldlt.o
	$(CC) -std=c++11 ldlt.o -o ldlt

direct_lu.o: ldlt.cpp
	$(CC) $(CPPFLAGS) ldlt.cpp

clean:
	rm *o direct_lu ldlt

