# Project name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
PUSH_SWAP_DIR = .
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
ACTIONS_DIR = ./actions
UTILS_DIR = ./utils

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Manually listed source files for actions
ACTIONS_SRCS = $(ACTIONS_DIR)/push.c \
               $(ACTIONS_DIR)/reverse_rotate.c \
               $(ACTIONS_DIR)/rotate.c \
			   $(ACTIONS_DIR)/swap.c \
			   $(ACTIONS_DIR)/reverse_rotate_all.c \
			   $(ACTIONS_DIR)/rotate_all.c


# Manually listed source files for actions
UTILS_SRCS =	$(UTILS_DIR)/free_stack.c \
				$(UTILS_DIR)/ft_atol.c \
				$(UTILS_DIR)/print_error.c \
				$(UTILS_DIR)/error_management.c \
				$(UTILS_DIR)/sort.c \
				$(UTILS_DIR)/presort_prep.c \
				$(UTILS_DIR)/target.c \
				$(UTILS_DIR)/index_helper.c \
				$(UTILS_DIR)/cheapest.c \
				$(UTILS_DIR)/min_to_top.c \
				$(UTILS_DIR)/cases_prices.c \
				$(UTILS_DIR)/moves.c \
				$(UTILS_DIR)/moves_2.c \
				$(UTILS_DIR)/solving_actions.c \
				$(UTILS_DIR)/values.c \
				$(UTILS_DIR)/sort_4_5.c

# Source files for push_swap and actions
PUSH_SWAP_SRCS = $(PUSH_SWAP_DIR)/ft_push_swap.c
SRCS = $(PUSH_SWAP_SRCS) $(ACTIONS_SRCS) $(UTILS_SRCS)

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
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(ACTIONS_DIR) -c $< -o $@

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