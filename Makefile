NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

PS_LIB = push_swap.a

LIBFT = libft.a
LIBFT_HEADER = libft.h

SRC = push_swap_solver.c \
	  push_swap_solver_ext.c \
	  quicksort.c \
	  distance_sort.c \
	  get_distances.c \
	  get_distances_ext.c \

PS_LIB_SRC = push_swap.c \
			 push_swap_utils.c \

OBJ = $(SRC:.c=.o)
PS_LIB_OBJ = $(PS_LIB_SRC:.c=.o)

all: $(NAME)

$(NAME): $(PS_LIB) $(LIBFT) $(OBJ)
	@echo "<$(NAME)>CREATING push_swap"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PS_LIB) $(LIBFT)

%.o: %.c
	@echo "<$(NAME)>COMPILING $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(PS_LIB): $(LIBFT) $(PS_LIB_OBJ)
	@echo "<$(NAME)>CREATING push_swap.a"
	@ar rcs $(PS_LIB) $(PS_LIB_OBJ)

$(LIBFT): $(LIBFT_HEADER)
	@echo "<$(NAME)>GETTING LIBFT"
	@make -C libft
	@cp libft/$(LIBFT) .

$(LIBFT_HEADER):
	@cp libft/$(LIBFT_HEADER) .

clean:
	@echo "<$(NAME)>REMOVING ALL OBJ"
	@make fclean -C libft
	@rm -f $(OBJ) $(PS_LIB_OBJ)

fclean: clean
	@echo "<$(NAME)>REMOVING LIBS/EXEC"
	@rm -f $(NAME) $(PS_LIB) $(LIBFT) $(LIBFT_HEADER)

re: fclean all

.PHONY: all clean fclean re

