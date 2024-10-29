# Variables
NAME = libft.a              # Static library name
SO_NAME = libft.so          # Dynamic library name
CC = gcc                    # Compiler
CFLAGS = -Wall -Wextra -Werror -fPIC   # Compiler flags
SRCS = $(wildcard *.c)      # Automatically find all .c files in the current directory
OBJS = $(SRCS:.c=.o)        # Corresponding .o files
INCLUDES = -I./             # Include path

# Default target to build both libraries
all: $(NAME) $(SO_NAME)

# Rule to build the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to build the dynamic library
$(SO_NAME): $(OBJS)
	$(CC) $(CFLAGS) -nostartfiles -shared -o $(SO_NAME) $(OBJS)

# Rule to build object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up all build files (object files and libraries)
fclean: clean
	rm -f $(NAME) $(SO_NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re