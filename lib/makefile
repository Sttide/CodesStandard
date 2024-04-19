#makefile
CC = gcc
AR = ar
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

LIB_NAME = libStacklib.a
OUT_DIR = /home/chao/Code/CodeStandrd/locallib/
 
#gpt
EXECUTABLES = $(SRCS:.c=.o)

lib: $(EXECUTABLES)
	$(AR) rcs $(LIB_NAME) $^

%.o: %.c
	$(CC) -c $< -o $@

# 将静态库复制到指定目录
copy: $(LIB_NAME)
	mkdir -p $(OUT_DIR)
	cp $(LIB_NAME) $(OUT_DIR)

clean:
	rm -rf *.o *.a

.PHONY: copy clean

