# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 10:50:36 by lusimon           #+#    #+#              #
#    Updated: 2025/04/19 13:13:00 by lusimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for libft project
# Project name
NAME = libft.a
# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror
# Source files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
 ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
 ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_back.c ft_lstnew.c
HEADER_FILE = libft.h
# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@echo "Creating libft library..."
	ar rcs $(NAME) $(OBJS)
	@echo "libft.a created successfully"

# Rule for creating object files
%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all

# Specify what happens when the Makefile is executed
help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "  make        Build the project"
	@echo "  make clean  Remove object files"
	@echo "  make fclean Remove object files and the library"
	@echo "  make re     Rebuild the project"
	@echo "  make help   Display this help message"

# Phony targets
.PHONY: all clean fclean re help
