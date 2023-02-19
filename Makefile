# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:26:41 by ysakahar          #+#    #+#              #
#    Updated: 2023/02/19 10:42:15 by ysakahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
CC       = gcc
CFLAGS   = -Wall -Werror -Wextra
INCS     = -I ./includes/
SRC_DIR  = src/
OBJ_DIR  = obj/
SRC      =  _main.c _split_args.c \
			_split_args_utils1.c _split_args_utils2.c \
			argument_validator.c argument_validator_utils.c \
			initialization.c stack.c swap.c push.c \
			rotate.c reverse_rotate.c sort3.c sort.c \
			position.c cost.c move.c utils.c

SRCS     = $(addprefix $(SRC_DIR), $(SRC))
OBJ      = $(SRC:.c=.o)
OBJS     = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(OBJB_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

SHELL=/bin/bash

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-2147483647 -n 500))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

test1000: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l | tr -d '[:space:]' && echo ""

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000