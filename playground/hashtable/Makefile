TARGET = main

CC = clang
INCLUDES = -I .
CFLAGS = -Wall -Werror -std=c99 $(INCLUDES)

HEADERS=$(shell find . -type f -name "*.h")
SOURCE=$(shell find . -type f -name "*.c")
OBJS=$(SOURCE:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

run: $(OBJS) $(HEADERS)
	@$(CC) -o $(TARGET) $(OBJS)

debug: $(SOURCE) $(HEADERS)
	@$(CC) -g $(CFLAGS) -o $(TARGET) $(SOURCE)

.PHONY: clean
clean:
	@rm -f ./$(TARGET)
	@rm -f $(OBJS)
	@rm -rf ./*.dSYM
