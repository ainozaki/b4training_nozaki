SRC := kadai1-1.c \
			 kadai1-2.c \
			 kadai1-3.c \
			 kadai1-5.c \
			 kadai1-11.c \
			 kadai1-12.c \
			 kadai1-13.c \
			 kadai1-14.c \
			 kadai1-15.c \
			 kadai1-16.c \
			 kadai1-17.c \
			 kadai1-18.c \
			 kadai1-19.c \
			 kadai1-20.c \
			 kadai1-21.c \
			 kadai1-22.c \
			 kadai1-23.c \
			 kadai1-24.c \
			 kadai1-26.c \
			 kadai1-27.c \
			 kadai1-28-use-fd.c \
			 kadai1-28-open-fd.c \
			 kadai1-29.c \
			 kadai1-30.c \
			 kadai1-32.c \
			 kadai1-33.c \
			 kadai1-34.c \
			 kadai1-35.c

all: $(SRC:.c=.o)

%.o: %.c
	gcc -o $@ $<

format:
	clang-format -i $(SRC)

clean:
	rm -f *.txt a.out *.o

.PHONY: format clean
