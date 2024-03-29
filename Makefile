# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborione <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:18:41 by dborione          #+#    #+#              #
#    Updated: 2022/12/09 11:13:46 by dborione         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#	Sources
FILES = main.c 	\
		map_parsing.c \
		map_utils.c \
		utils.c \
		get_next_line.c	\
		get_next_line_utils.c	\
		pathfinding.c \
		init_game.c \
		movement.c \

SRCS = $(addprefix src/, $(FILES))

#	Objects
OBJS = $(SRCS:.c=.o)

#	Others
NAME = so_long
RM = rm -f

#Libft
LIBFT = libft.a
LIBFT_DIR = ./libft/
LIBFT_PATH = ./libft/libft.a

#	Colours
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
DEFAULT = \033[0m

#	Targets
all :	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_PATH)
	@echo "$(GREEN)[Done!]$(DEFAULT)"

#	Cleaning
clean:
	@echo "$(YELLOW)[Cleaning...]$(DEFAULT)"
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	@echo "$(RED)[Objects Cleaned!]$(DEAFULT)"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)[Executable File Cleaned!]$(DEFAULT)"

re: fclean all

.PHONY:	clean fclean re all bonus
