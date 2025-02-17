# **************************************************************************** #
#                               Program Names                                  #
# **************************************************************************** #

CLIENT      = client
SERVER      = server

# **************************************************************************** #
#                           Compiler and Flags                                 #
# **************************************************************************** #

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# **************************************************************************** #
#                               Directories                                    #
# **************************************************************************** #

MINI_TALK_DIR   = .
UTILITIES_DIR   = ./utilities
LIBFT_DIR       = ./libft
PRINTF_DIR      = ./libft/ft_printf

# **************************************************************************** #
#                               Libraries                                      #
# **************************************************************************** #

LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# **************************************************************************** #
#                               Source Files                                   #
# **************************************************************************** #

CLIENT_SRCS = $(MINI_TALK_DIR)/client.c
SERVER_SRCS = $(MINI_TALK_DIR)/server.c

UTILITIES_SRCS = $(UTILITIES_DIR)/ft_atol.c \
                 $(UTILITIES_DIR)/uti_functions.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o) $(UTILITIES_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o) $(UTILITIES_SRCS:.c=.o)

# **************************************************************************** #
#                               Default Target                                 #
# **************************************************************************** #

all: $(LIBFT) $(PRINTF) $(CLIENT) $(SERVER)

# ---------------------------------------------------------------------------- #
# Build libft if needed
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf if needed
$(PRINTF):
	@echo "Building ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR)

# ---------------------------------------------------------------------------- #
# Compile the client
$(CLIENT): $(CLIENT_OBJS)
	@echo "Building $(CLIENT)..."
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT) $(PRINTF)

# Compile the server
$(SERVER): $(SERVER_OBJS)
	@echo "Building $(SERVER)..."
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) $(PRINTF)

# ---------------------------------------------------------------------------- #
# Compile source files into object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

# **************************************************************************** #
#                               Clean Targets                                  #
# **************************************************************************** #

.PHONY: all clean fclean re

clean:
	@echo "Cleaning object files..."
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@echo "Removing binaries..."
	@rm -f $(CLIENT) $(SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
