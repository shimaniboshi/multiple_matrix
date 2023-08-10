CC = gcc
CFLAGS = -Wall
TARGET = multiple_matrix
SRCS = \
    multiple_matrix.c \
    matrix.c
OBJS = $(SRCS:.c=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

