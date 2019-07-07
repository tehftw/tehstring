dirsrc=src
SRC := $(shell find ./src -name "*.c")
HEADERS := $(shell find ./src -name "*.h")

all: string.elf

run: string.elf
	./string.elf

string.elf: $(SRC) $(HEADERS)
	gcc -Wall -Wextra $(SRC) -o string.elf
