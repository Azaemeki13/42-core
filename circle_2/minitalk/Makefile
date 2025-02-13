# Project name
NAME = mini_talk

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
MINI_TALK_DIR = .
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a


# Source files for push_swap and actions
MINI_TALK_SRCS = $(MINI_TALK_DIR)/client.c \
				 $(MINI_TALK_DIR)/server.c
SRCS = $(MINI_TALK_SRCS)

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Building ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Removing libraries and executable..."
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re