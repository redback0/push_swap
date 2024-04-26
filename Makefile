NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

PS_LIB = push_swap.a

LIBFT = libft.a
LIBFT_HEADER = libft.h

SRC = push_swap_solver.c \
	  push_swap_solver_ext.c \
	  quicksort.c \
	  distance_sort.c \
	  distance_sort_ext.c \
	  get_distances.c \
	  initial_sort.c \
	  return_sort.c \

PS_LIB_SRC = push_swap.c \
			 push_swap_utils.c \

B_SRC = checker.c \
		checker_ext.c \

OBJ = $(SRC:.c=.o)
PS_LIB_OBJ = $(PS_LIB_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

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

$(BONUS): $(PS_LIB) $(LIBFT) $(B_OBJ)
	@echo "<$(NAME)>CREATING $(BONUS)"
	@$(CC) $(CFLAGS) -o $(BONUS) $(B_OBJ) $(PS_LIB) $(LIBFT)

clean:
	@echo "<$(NAME)>REMOVING ALL OBJ"
	@make fclean -C libft
	@rm -f $(OBJ) $(PS_LIB_OBJ) $(B_OBJ)

fclean: clean
	@echo "<$(NAME)>REMOVING LIBS/EXEC"
	@rm -f $(NAME) $(BONUS) $(PS_LIB) $(LIBFT) $(LIBFT_HEADER)

re: fclean all

.PHONY: all clean fclean re

