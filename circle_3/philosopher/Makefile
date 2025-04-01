NAME = philo

# Compiler && flags 
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

# Directories
PHILO_DIR = .
UTILS_DIR = ./utils

 #Now I list manually :D 
UTILS_SRCS = $(UTILS_DIR)/ft_atoi.c \
					$(UTILS_DIR)/list.c \
					$(UTILS_DIR)/ft_split.c \
					$(UTILS_DIR)/list_annex.c \
					$(UTILS_DIR)/philo_actions.c \
					$(UTILS_DIR)/thread.c \
					$(UTILS_DIR)/ft_strjoin.c

#$(UTILS_DIR)/error.c


#Now my philo 
PHILO_SRCS = $(PHILO_DIR)/philo.c
SRCS = $(PHILO_SRCS) $(UTILS_SRCS)

#Object files
OBJS = $(SRCS:.c=.o)

# Rules
all : $(NAME)

$(NAME): $(OBJS)
		@echo "building $(NAME)..."
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
		@echo "Compiling $<..."
		$(CC) $(CFLAGS) -o -I$(UTILS_DIR) -c $< -o $@

clean:
		@echo "Cleaning object files..."
		rm -f $(OBJS)

fclean:
		@echo "LMAO ITS THE SAME XD..."
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
