CC = gcc
SRC = main.c \
src/init.c  

OUT = init

$(OUT):$(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)