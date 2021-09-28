NAME := rush-02

CC := gcc

CFLAGS := -Wall -Werror -Wextra -c

OFLAGS	= -Wall -Werror -Wextra -o

SRC_DIR := ./src/

OBJ_DIR	= ./obj/

SRC_FILES = ft_num_3.c ft_input.c main.c string_manip.c create_elem_with_data.c \
			ft_list_push_front.c ft_list_find.c parse_number.c \
			ft_list_push_back.c ft_list_print.c dict_parsing.c dict_preparsing.c \
			list.c

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

$(NAME): $(OBJS)
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
