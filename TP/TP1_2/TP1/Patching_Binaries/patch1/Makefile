CHALLENGE=test
USER=app-systeme-$(CHALLENGE)
USER_CRACKED=app-systeme-$(CHALLENGE)-cracked

CC=gcc
CFLAGS=-Wall -Wextra -m32 -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wl,-z,now -Wl,-z,relro,-z,noexecstack -no-pie
LDFLAGS=-Wl,--rpath=/lib/old32/ -Wl,--dynamic-linker=/lib/old32/ld-2.19.so

SRC=$(CHALLENGE).c
OBJ=$(SRC:.c=.o)
BIN=$(CHALLENGE)

.DEFAULT_GOAL := challenge
.PHONY : clean all

pre-build:
	@echo "Removing immutable flags..."

post-build:
	@echo "Adding immutable flags..."

all: pre-build
	@echo "Compiling..."
	$(MAKE) $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(SRC) $(LDFLAGS) $(CFLAGS)

challenge: all
	@echo "Applying permissions..."
	rm -f $(OBJ)
	$(MAKE) post-build

clean: pre-build
	rm -f $(BIN) $(OBJ)
	$(MAKE) post-build

