define draw
	@echo "\033[1;31m    ____             __       _____                    \033[0m"
	@echo "\033[1;31m   / __ \__  _______/ /_     / ___/      ______ _____  \033[0m"
	@echo "\033[1;31m  / /_/ / / / / ___/ __ \    \__ \ | /| / / __ \`/ __ \ \033[0m"
	@echo "\033[1;31m / ____/ /_/ (__  ) / / /   ___/ / |/ |/ / /_/ / /_/ / \033[0m"
	@echo "\033[1;31m/_/    \__,_/____/_/ /_/   /____/|__/|__/\__,_/ .___/  \033[0m"
	@echo "\033[1;31m                                             /_/       \033[0m"
endef

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

LIBFT_DIR = ./libft/
GNL_DIR = ./bonus/gnl/
BONUS_DIR = ./bonus/

SRC = best_move.c free_utils.c ft_helper.c instructions_three.c instructions_two.c \
	instructions.c lnkd_lst.c long_inc_sub.c moves.c moves.c parsing_two.c \
	parsing.c push_swap.c sort_algos.c sort.c

LIBFT_SRC_BASE = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_memmove.c ft_putstr_fd.c \
	ft_split.c ft_strlen.c ft_strtrim.c ft_substr.c

BNS_SRC_BASE = checker.c free_utils.c instructions.c instructions_two.c \
	instructions_three.c lnkd_lst.c parsing.c parsing_two.c read_and_do_moves.c

GNL_SRC_BASE = get_next_line.c get_next_line_utils.c

BNS_SRC = $(addprefix  $(BONUS_DIR), $(BNS_SRC_BASE))

LIBFT_SRC = $(addprefix  $(LIBFT_DIR), $(LIBFT_SRC_BASE))

GNL_SRC = $(addprefix  $(GNL_DIR), $(GNL_SRC_BASE))

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS_SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

NAME = push_swap
CHECKER_NAME = checker


all : $(NAME)
	$(call draw)

$(NAME) : $(OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BNS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $^ -o $(CHECKER_NAME)

clean : 
	$(RM) $(OBJ) $(BNS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ)
	$(call draw)

fclean : clean
	$(RM) $(NAME) $(CHECKER_NAME)

re : fclean all
