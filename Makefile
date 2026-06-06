CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = inspector.c take_data.c print_generals.c
OBJ = $(SRC:.c=.o)
TARGET = inspect

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)