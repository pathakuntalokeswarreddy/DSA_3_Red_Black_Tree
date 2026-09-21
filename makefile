CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = a.out

SOURCES = main.c insert.c search.c delete.c \
          find_min.c find_max.c delete_min.c delete_max.c \
		  print_tree.c rotate_helpers.c

OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c rbt.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) a.out