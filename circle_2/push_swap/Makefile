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
STEP2_DIR = ./step2
DEBOG_DIR = ./debog

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Manually listed source files for actions
ACTIONS_SRCS = $(ACTIONS_DIR)/push.c \
               $(ACTIONS_DIR)/reverse_rotate.c \
               $(ACTIONS_DIR)/rotate.c \
			   $(ACTIONS_DIR)/swap.c 

# Manually listed source files for actions
UTILS_SRCS =	$(UTILS_DIR)/free_stack.c \
				$(UTILS_DIR)/ft_atol.c \
				$(UTILS_DIR)/print_error.c \
				$(UTILS_DIR)/error_management.c \
				$(UTILS_DIR)/presort.c \
				$(UTILS_DIR)/presort_prep.c \
				$(UTILS_DIR)/pre_logic.c \
				$(UTILS_DIR)/push_price.c \
				$(UTILS_DIR)/cheapest.c \
				$(UTILS_DIR)/solving2.c 

#Manually listed source files for xd 
STEP2_SRCS = 	$(STEP2_DIR)/atob.c \
				$(STEP2_DIR)/solving1.c

#Manually listed source files for DEBOG 
DEBOG_SRCS = 	$(DEBOG_DIR)/target_data.c 
				


# Source files for push_swap and actions
PUSH_SWAP_SRCS = $(PUSH_SWAP_DIR)/ft_push_swap.c
SRCS = $(PUSH_SWAP_SRCS) $(ACTIONS_SRCS) $(UTILS_SRCS) $(STEP2_SRCS) $(DEBOG_SRCS)

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