# Name of the final executable
NAME = ft_printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./ -I $(LIBFT_DIR)

# BEGIN SRC
SRC = \
    ft_printf.c \
    ft_printf_X.c \
    ft_printf_char.c \
    ft_printf_d.c \
    ft_printf_p.c \
    ft_printf_parser.c \
    ft_printf_s.c \
    ft_printf_x.c
# END SRC (line number: 10)

# Object files generated from source files
OBJS = $(SRC:.c=.o)

# Directory for libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

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
