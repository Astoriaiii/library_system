CC = gcc 
LD = gcc

# all files
SRCS = $(wildcard *.c)

# to .o
OBJS = $(patsubst %c, %o, $(SRCS))

# executable file name
TARGET = Management

.PHONY:all clean

# target file
all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^

%.o:%.c
	$(CC) -c $^

# make clean
clean:
	rm -f $(OBJS) $(TARGET)
