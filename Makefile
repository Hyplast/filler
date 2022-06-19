# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: severi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 00:48:33 by severi            #+#    #+#              #
#    Updated: 2022/06/09 12:58:21 by severi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ssavukos.filler

SRC = ft_filler.c \
ft_algorithm.c \
ft_pieces.c \
ft_place_piece.c \
ft_map.c \
ft_util.c 

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix obj/, $(SRC:.c=.o))

INC = includes/

LIBDIR = libft/

LIB_INC = libft/includes/

OBJ_DIR = obj/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: dir $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIB_INC) $(OBJS) -L $(LIBDIR) -lft -o $(NAME)
	@echo "project compiled"

dir:
	@mkdir -p $(OBJ_DIR)

$(OBJS): obj/%.o : srcs/%.c
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIB_INC) -c $< -o $@ 

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@rm -f -r $(OBJ_DIR)
	@echo "project cleaned, removed *.o files"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "removed $(NAME)"

re: fclean all