# Variables
NAME = libft.a                  # Static library name
SO_NAME = libft.so              # Dynamic library name
LIBFT = libft
CC = gcc                        # Compiler
CFLAGS = -Wall -Wextra -Werror -fPIC  # Compiler flags
SRC = $(wildcard *.c)           # Automatically find all .c files in the current directory
OBJ = $(SRC:.c=.o)              # Corresponding object files derived from .c files

# Default target
all: $(NAME) $(SO_NAME)

# Rule to build the static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to build the dynamic library
$(SO_NAME): $(OBJ)
	$(CC) -shared -o $(SO_NAME) $(OBJ) -nostartfiles

# Rule to build object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up all build files (object files and libraries)
fclean: clean
	rm -f $(NAME) $(SO_NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
