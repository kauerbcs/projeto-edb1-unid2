CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11

OBJ = src/pedido.o src/fila.o src/main.o
TARGET = restaurante

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)