CC := C:/msys64/mingw64/bin/gcc.exe
CFLAGS := -std=c11 -g3 -O0 -Wall -Wextra
SOURCES := $(wildcard *.c)
PROGRAMS := $(SOURCES:.c=.exe)
NAMES := $(basename $(PROGRAMS))

.PHONY: all $(NAMES)

all: $(PROGRAMS)

$(NAMES): %: %.exe

%.exe: %.c
	"$(CC)" $(CFLAGS) "$<" -o "$@"
