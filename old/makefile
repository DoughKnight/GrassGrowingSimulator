CC=gcc 
CFLAGS=-Wall
DEPS = menu.h
OBJ = main.o menu.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ggs: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
