# Variables
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and objects
SRC = ft_push_swap.c
OBJ = $(SRC:.c=.o)

# Directories for dependencies
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Targets
all: $(FT_PRINTF_LIB) $(NAME)

# Build the main push_swap executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF_LIB)

# Rule to build object files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build ft_printf and libft
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)

re: fclean all
