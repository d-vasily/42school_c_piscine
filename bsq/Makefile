NAME := bsq

CC := gcc

CFLAGS := -Wall -Werror -Wextra -c

OFLAGS	= -Wall -Werror -Wextra -o

SRC_DIR := ./src/

OBJ_DIR	= ./obj/
 
SRC_FILES = main.c ft_first_str.c ft_free.c ft_add.c ft_start.c square_find.c string_manip.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADER := -I include/

RM := rm -rf

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): $(OBJS) ./include/universe.h
	$(CC) $(OFLAGS) $(NAME) $(OBJS) $(HEADER)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckDefine ./include/
	norminette -R CheckForbiddenSourceHeader ./src/

.PHONY: all clean fclean re norm
