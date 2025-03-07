# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 12:00:36 by ituriel           #+#    #+#              #
#    Updated: 2025/03/07 16:41:05 by cauffret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#directories used
SO_LONG_DIR = .
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
MAPS_DIR= ./maps
GET_NEXT_LINE_DIR = ./get_next_line
MLX_DIR = ./mlx_linux
UTILS_DIR = ./utils

# what i want to link against
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GET_NEXT_LINE_DIR)/get_next_line.a
MLX = $(MLX_DIR)/libmlx_Linux.a

# now listing my files 
MAPS_SRCS = $(MAPS_DIR)/map_checker_1.c \
			$(MAPS_DIR)/map_checker_2.c \
			$(MAPS_DIR)/map_list.c \
			$(MAPS_DIR)/map_renderer.c

UTILS_SRCS = $(UTILS_DIR)/game_start.c \
			 $(UTILS_DIR)/animations.c \
			 $(UTILS_DIR)/window_exit.c \
			 $(UTILS_DIR)/clean.c \
			 $(UTILS_DIR)/game_clean.c \
			 $(UTILS_DIR)/movement.c \
			 $(UTILS_DIR)/movement_1.c \
			 $(UTILS_DIR)/move_hook.c \
			 $(UTILS_DIR)/state.c \
			 $(UTILS_DIR)/flood_algo.c
			 

# What do I need to make so_long work ? my custom so_long functions :)
SO_LONG_SRCS = $(SO_LONG_DIR)/so_long.c
SRCS = $(SO_LONG_SRCS) $(MAPS_SRCS) $(UTILS_SRCS)

# object files build
OBJS = $(SRCS:.c=.o) 

# Rules
all: $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Building printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL):
	@echo "Building get next line..."
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MLX):
	@echo "Building minilibx..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(PRINTF) $(GNL) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MAPS_DIR) -I$(UTILS_DIR) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Removing libs and executables..."
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all clean fclean re