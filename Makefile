# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 09:54:18 by lusimon           #+#    #+#              #
#    Updated: 2025/04/18 17:04:49 by lusimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# === Compiler / Flags ===
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -lhistory

# === External Repo Setup ===
GITHUB_REPO = https://github.com/Lucieee0/minishell_lib.git
LIBS_DIR = minishell_lib
MINISHELL_LIB_DIR = $(LIBS_DIR)
#INCLUDES = -I./$(MINISHELL_LIB_DIR)/includes -I./$(MINISHELL_LIB_DIR)/libft -I./$(MINISHELL_LIB_DIR)/ft_printf -I./$(MINISHELL_LIB_DIR)/get_next_line
INCLUDES = -I./minishell_lib/libft \
           -I./minishell_lib/ft_printf \
           -I./minishell_lib/get_next_line
LIBDIR = -L./$(MINISHELL_LIB_DIR)
LIBFT = $(MINISHELL_LIB_DIR)/libminishell_lib.a  # Correct

# === Source / Object Management ===
SRCS = pwd.c env.c exit.c echo.c cd_path.c cd_env_failure_free.c cd_cd.c builtin.c mini_shell.c helper.c
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# === Build Rules ===

all: download_resources $(LIBFT) $(NAME)

download_resources:
	git submodule update --init --remote --recursive 
#be careful with this command it doesnt update if you delete the folder
libs: $(LIBFT)
setup: art download_resources libs

$(LIBFT):
	@if [ ! -d "$(LIBS_DIR)" ]; then \
		git clone $(GITHUB_REPO) $(LIBS_DIR); \
	fi
	$(MAKE) -C $(MINISHELL_LIB_DIR) libminishell_lib.a  # Explicitly build the .a

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBDIR) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# === Clean Rules ===

clean:
	@$(MAKE) -C $(MINISHELL_LIB_DIR) clean || true
	@rm -f $(OBJDIR)/*.o
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(MINISHELL_LIB_DIR) fclean || true
	@rm -f $(NAME)

re: download_resources fclean all

# === Help ===

help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "  make          Build the project"
	@echo "  make clean    Remove object files"
	@echo "  make fclean   Remove object files and the binary"
	@echo "  make re       Rebuild the project"
	@echo "  make help     Show this help message"

.PHONY: all clean fclean re help
.PHONY: all clean fclean re help setup download_resources libs
