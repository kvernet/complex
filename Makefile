COMPILER =gcc
CFLAGS   =-O02 -fPIC -Wall -Werror -Wextra
LDFLAGS  =-shared

LIB_NAME =complex
BIN_NAME =cexec

all: $(BIN_NAME)

$(BIN_NAME): $(BIN_NAME).c $(LIB_NAME)
	mkdir -p bin
	$(COMPILER) $(CFLAGS) -o bin/$@ $< -Isrc -Llib -l$(LIB_NAME) -Wl,-rpath=`pwd`/lib

LIB_SRCS =src/complex.c

$(LIB_NAME): $(LIB_SRCS)
	mkdir -p lib
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o lib/lib$@.so $^ -Isrc -lm

clean:
	rm -rf bin
	rm -rf lib

.PHONY: all clean $(LIB_NAME) $(BIN_NAME)
