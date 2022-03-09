SRC := kadai2-1.c \
			 kadai2-2.c \
			 kadai2-3.c \
			 kadai2-4.c \
			 kadai2-5.c \
			 kadai2-6.c \
			 kadai2-7.c \
			 kadai2-8.c \
			 kadai2-9.c

all: $(SRC:.c=.o)

%.o: %.c
	gcc -o $@ $<

format:
	clang-format -i $(SRC)

clean:
	rm -f *.txt a.out *.o

.PHONY: all format clean
