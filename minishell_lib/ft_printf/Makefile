# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 10:50:36 by lusimon           #+#    #+#              #
#    Updated: 2025/04/16 21:09:35 by lusimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = ft_printf.a

# Compiler
CC = cc

# Archiver
AR = ar

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_printf.c hexa_ptr.c print_char.c print_digit.c print_hexa_low.c \
print_hexa_up.c print_pointer.c print_string.c unsigned_int.c

# Object files (replace .c with .o). Compiling source files to object files
OBJS = $(SRCS:.c=.o)

# Rule for creating object files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

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
	@echo "  make          Build the project"
	@echo "  make clean    Remove object files"
	@echo "  make fclean   Remove object files and the library"
	@echo "  make re       Rebuild the project"
	@echo "  make help     Display this help message"

# Phony targets
.PHONY: all clean fclean re help


