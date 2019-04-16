CC=gcc
EXE=program
OBJ=main.o sparseMatrix.o
INCLUDE=.

all:$(EXE)
$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

%.o: %.c
	$(CC) -c -o $@ $< -I $(INCLUDE)

#$(EXE):$(OBJ)
#	$(CC) -o $(EXE) $(OBJ)
#	
#main.o:sparseMatrix.h
#	$(CC) -I $(INCLUDE) -c main.c
#	
#sparseMatrix.o:sparseMatrix.h
#	$(CC) -I $(INCLUDE) -c sparseMatrix.c

.PHONY: clean
clean:
	rm $(EXE) *.o