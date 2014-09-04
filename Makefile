CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
DBFLAGS=-g

SDIR=src
ODIR=src/obj

_DEP=draughts.h game.h gameboard.h scoreboard.h utility.h
_OBJ=draughts.o game.o gameboard.o scoreboard.o utility.o
DEP=$(patsubst %,$(SDIR)/%,$(_DEP))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

EXE=draughts

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ 

$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) $(DBFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ $(EXE)

