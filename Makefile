NAME = push_swap
BONUS = checker CC = cc

ifeq ($(DEBUG), 1)
	CFLAGS = -Wall -Wextra -Werror -g
else
	CFLAGS = -Wall -Wextra -Werror
endif

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


#LOGGING DEFINES
LOGLEVEL ?= 4
LOGERROR ?= 4
export LOGLEVEL
export LOGERROR

DEFINES = -DLOGLEVEL=$(LOGLEVEL) -DLOGERROR=$(LOGERROR)


#PREFIX/COLOUR VARIABLES
C_GRAY = \033[1;30m
C_ORANGE = \033[0;33m
C_RED = \033[0;31m
C_CYAN = \033[0;36m
NC = \033[0m

PREFIX = $(C_ORANGE)<$(NAME)>$(NC)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(PS_LIB) $(LIBFT) $(OBJ)
	@printf "$(PREFIX) CREATING $(C_CYAN)$@$(NC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PS_LIB) $(LIBFT)

%.o: %.c
	@printf "$(PREFIX) $(C_GRAY)COMPILING $@$(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(PS_LIB): $(LIBFT) $(PS_LIB_OBJ)
	@printf "$(PREFIX) MAKING $(C_CYAN)$@$(NC) ARCHIVE\n"
	@ar rcs $(PS_LIB) $(PS_LIB_OBJ)

$(LIBFT): $(LIBFT_HEADER)
	@printf "$(PREFIX) MAKING $(C_CYAN)$@$(NC) ARCHIVE\n"
	@make -C libft
	@cp libft/$@ .

$(LIBFT_HEADER):
	@printf "$(PREFIX) $(C_GRAY)GETTING LIBFT HEADER$(NC)\n"
	@cp libft/$(LIBFT_HEADER) .

$(BONUS): $(PS_LIB) $(LIBFT) $(B_OBJ)
	@printf "$(PREFIX) CREATING $(C_CYAN)$@$(NC)\n"
	@$(CC) $(CFLAGS) -o $(BONUS) $(B_OBJ) $(PS_LIB) $(LIBFT)

clean:
	@printf "$(PREFIX) $(C_RED)REMOVING OBJECT FILES$(NC)\n"
	@make fclean -C libft
	@rm -f $(OBJ) $(PS_LIB_OBJ) $(B_OBJ)

fclean: clean
	@printf "$(PREFIX) $(C_RED)REMOVING ARCHIVE$(NC)\n"
	@rm -f $(NAME) $(BONUS) $(PS_LIB) $(LIBFT) $(LIBFT_HEADER)

re: fclean all

.PHONY: all clean fclean re

