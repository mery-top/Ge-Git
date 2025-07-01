CC = gcc
SRC = main.c \
src/init.c \
src/hash_object.c \
src/utils.c

OPENSSL_PREFIX = /opt/homebrew/opt/openssl@3

OUT = gegit

$(OUT):$(SRC)
	$(CC) $(SRC) -o $(OUT) \
	-I$(OPENSSL_PREFIX)/include \
	-L$(OPENSSL_PREFIX)/lib -lssl -lcrypto

run:
	./$(OUT)

clean:
	rm -f $(OUT)