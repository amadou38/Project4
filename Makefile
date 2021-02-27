CC=gcc
CCFLAGS= -c
LDFLAGS= -lm
EXE=projet4
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
$(EXE):$(OBJ)
	$(CC) -o $(EXE) $^ $(LDFLAGS)
%.o:%.c
	$(CC) $(CCFLAGS) $<
clean:
	rm $(OBJ) $(EXE)

