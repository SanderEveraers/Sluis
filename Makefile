#
#	Makefile for IPC32
#
#	(c) Fontys 2016, Sander Everaers
#

# CFLAGS=-Wall -Werror -pedantic -O3 -Icode -c
# LDDFLAGS=-lpthread

# MAIN_SOURCES=$(products/*.cpp)
# MAIN_OBJECTS=$(MAIN_SOURCES:.cpp=.o) 

# TEST_LIBS=-lgtest -lgtest_main -lpthread

# CC=g++

# .phony: all clean

# sort: $(MAIN_OBJECTS) 
# 	@$(CC) $(MAIN_OBJECTS) -fopenmp -o $@ $(LDDFLAGS)
	
# all: sort

# .cpp.o: Makefile
# 	$(CC) $(CFLAGS) -fopenmp $< -o $@

# clean:
# 	@rm -rf sort products/*.o test/*.o *.bin

CC = g++
CFLAGS = -g3 -Wall -W -Wshadow -Wcast-qual -Wwrite-strings
LDLIBS = -lrt -lpthrea

BINARIES= ui

sluis: $(BINARIES)

all: sluis

network: products/network.o

ui: products/ui.o

clean:
	rm *.o $(BINARIES)
