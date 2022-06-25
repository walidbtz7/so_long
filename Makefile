# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 21:23:23 by wboutzou          #+#    #+#              #
#    Updated: 2022/06/25 21:23:27 by wboutzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    		= helpers.c get_next_line.c checker_map.c graphic.c so_long.c

FLAGS 			=	-Wall -Wextra -Werror 

MLX				= 	-lmlx -framework OpenGL -framework AppKit
OBJS			=    $(SRCS:.c=.o)

NAME    		=    so_long

PRINTF    		=    ./ft_printf/libftprintf.a

LIBFT    		=    ./libft/libft.a

.PHONY:		all clean fclean re bonus

all: $(NAME)

$(NAME):  $(LIBFT)  $(PRINTF) $(OBJS)
	cc -g $(FLAGS) $(OBJS) $(MLX) $(LIBFT)  $(PRINTF) -o $(NAME)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C ft_printf
%.o:%.c 
	cc $(FLAGS) -c $< -o $@
clean:
	@rm -f ${OBJS}

fclean:    clean
	@make  -C libft fclean
	@make  -C ft_printf fclean
	@rm -f ${NAME}

re: fclean all