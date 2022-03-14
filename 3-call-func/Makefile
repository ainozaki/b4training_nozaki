SRC := kadai3-3.c \
			 kadai3-5-1.c \
			 kadai3-5-2.c \
			 kadai3-8.c

all: $(SRC:.c=.o)

%.o: %.c
	gcc -o $@ $<

format:
	clang-format -i $(SRC)

clean:
	rm -f *.txt a.out *.o

kadai3-3: kadai3-3.c
	gcc -O0 $<

.PHONY: all format clean
