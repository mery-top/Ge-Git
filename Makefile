CC = gcc
SRC = main.c \
src/init.c \
src/hash_object.c

OUT = gegit

$(OUT):$(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)