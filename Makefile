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

SRCS = ft_filler.c \
ft_algorithm.c \
ft_pieces.c \
ft_place_piece.c \
ft_map.c \
ft_util.c 

SRC_DIR = srcs/

OBJ = $(SRCS:.c=.o)

OBJ_DIR = obj/

INCLUDES = -I libft/includes -I includes/

LINK = -L libft -lft

LIBFT = libft/libft.a

#FLAGS = -Wall -Wextra -Werror -Wconversion -g 
FLAGS = -Wall -Wextra -Werror -Wconversion -g -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT)
	gcc -c $(FLAGS) $(addprefix $(SRC_DIR), $(SRCS)) $(INCLUDES)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ) $(OBJ_DIR)
	gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) -o $(NAME) $(LINK)
$(LIBFT):
	make -s -C libft
clean: 
	make -s -C libft/ clean
	rm -rf obj

fclean: clean
	rm -rf $(NAME)
	make -s -C libft/ fclean

re: fclean all
