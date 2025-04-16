NAME = minishell_lib

# Directories
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

# Libs
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a

# GNL files
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Includes (optional if headers are needed)
INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

# === Rules ===

#all: $(NAME)

libminishell_lib.a: $(LIBFT) $(PRINTF) $(GNL_OBJ)
	ar rcs $@ $(GNL_OBJ) $(wildcard $(LIBFT_DIR)/*.o) $(wildcard $(PRINTF_DIR)/*.o)
	ranlib $@

# Update 'all' to depend on the library
all: libminishell_lib.a

# Build sub-libraries
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Compile GNL objects
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link everything into final executable
$(NAME): $(LIBFT) $(PRINTF) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(GNL_OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(GNL_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all