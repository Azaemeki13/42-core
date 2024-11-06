# Name of the final executable
NAME = ft_printf

# Source files for ft_printf, parser, and related functions
# BEGIN SRC
SRC = \
    ft_printf.c \
    ft_printf_char.c \
    ft_printf_d.c \
    ft_printf_p.c \
    ft_printf_parser.c \
    ft_printf_s.c
# END SRC (line number: 8)

# Object files generated from source files
OBJS = $(SRCS:.c=.o)

# Directory for libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./ -I $(LIBFT_DIR)

# Default rule to build everything
all: $(NAME)

# Build the final executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything, including the final executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything from scratch
re: fclean all
