# code details

EXE = ./book_management
SRC= main.c store_load.c borrow.c book_management.h

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
main.o:      main.c book_management.h
store_load.o:     store_load.c book_management.h
borrow.o: borrow.c book_management.h