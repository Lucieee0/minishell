# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 09:54:18 by lusimon           #+#    #+#              #
#    Updated: 2025/04/19 12:53:23 by lusimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === Project Name ===
NAME = minishell

# === Compiler / Flags ===
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -lhistory

# === External Repo Setup ===
LIBS_DIR = minishell_lib
MINISHELL_LIB_DIR = $(LIBS_DIR)
INCLUDES = -I./minishell_lib/libft \
 -I./minishell_lib/ft_printf \
 -I./minishell_lib/get_next_line
 
# Library paths for linking
LIBFT = ./minishell_lib/libft/libft.a
FT_PRINTF = ./minishell_lib/ft_printf/ft_printf.a

# === Source / Object Management ===
SRCS = pwd.c env.c exit.c echo.c cd_path.c cd_env_failure_free.c cd_cd.c export.c builtin.c mini_shell.c helper.c
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Get Next Line sources (directly included here)
GNL_SRCS = ./minishell_lib/get_next_line/get_next_line.c \
 ./minishell_lib/get_next_line/get_next_line_utils.c
 
# Get Next Line object files
GNL_OBJS = get_next_line.o get_next_line_utils.o

# === Phony Targets ===
.PHONY: all clean fclean re libft ft_printf get_next_line

# === Rules ===
# Default target: build the project
all: libft ft_printf get_next_line $(NAME)

# Build the project binary
$(NAME): $(OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(LIBS) -L./minishell_lib/libft -L./minishell_lib/ft_printf -L./minishell_lib/get_next_line -lreadline -lhistory

# Rule for creating object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR) # Create obj directory if not exists
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule for creating object files for get_next_line (direct compilation)
get_next_line.o: ./minishell_lib/get_next_line/get_next_line.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

get_next_line_utils.o: ./minishell_lib/get_next_line/get_next_line_utils.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile the libft library
libft:
	@echo "Compiling libft..."
	$(MAKE) -C ./minishell_lib/libft

# Compile the ft_printf library
ft_printf:
	@echo "Compiling ft_printf..."
	$(MAKE) -C ./minishell_lib/ft_printf

# Compile the get_next_line files directly
get_next_line: get_next_line.o get_next_line_utils.o
	@echo "Compiling get_next_line..."

# Clean up object files
clean:
	rm -f $(OBJS) $(GNL_OBJS)
	$(MAKE) -C ./minishell_lib/libft clean
	$(MAKE) -C ./minishell_lib/ft_printf clean

# Clean up object files and the executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./minishell_lib/libft fclean
	$(MAKE) -C ./minishell_lib/ft_printf fclean

# Rebuild the project
re: fclean all

# Display help message
help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "  make        Build the project"
	@echo "  make clean  Remove object files"
	@echo "  make fclean Remove object files and the binary"
	@echo "  make re     Rebuild the project"
	@echo "  make help   Display this help message"