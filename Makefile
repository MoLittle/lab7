CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/calculo_investimento.o src/gerenciamento_investimento.o

all: investimentos

investimentos: $(OBJ)
	$(CC) $(CFLAGS) -o investimentos $(OBJ) -lm

src/main.o: src/main.c include/investimento.h include/calculo_investimento.h include/gerenciamento_investimento.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/calculo_investimento.o: src/calculo_investimento.c include/calculo_investimento.h
	$(CC) $(CFLAGS) -c src/calculo_investimento.c -o src/calculo_investimento.o

src/gerenciamento_investimento.o: src/gerenciamento_investimento.c include/gerenciamento_investimento.h
	$(CC) $(CFLAGS) -c src/gerenciamento_investimento.c -o src/gerenciamento_investimento.o

clean:
	rm -f src/*.o investimentos
