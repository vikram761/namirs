CC = clang
SRC = src/main.c
OBJ = main.o
BIN_DIR = bin
OUT = $(BIN_DIR)/main

$(BIN_DIR)/main: $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(SRC) -o $(OUT)

clean:
	rm -rf $(BIN_DIR)

