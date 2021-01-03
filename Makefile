TARGET = sk

CC = clang
INCLUDES = -I ./include
CFLAGS = -Wall -Werror -std=c99 $(INCLUDES)

HEADERS=$(shell find ./include -type f -name *.h)
SOURCE=$(shell find ./src -type f -name *.c)
OBJS=$(SOURCE:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

run: $(OBJS) $(HEADERS)
	@$(CC) -o $(TARGET) $(OBJS)

.PHONY: clean
clean:
	@rm $(OBJS)
	@rm ./$(TARGET)

