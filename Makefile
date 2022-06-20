SRCS    		= helpers.c get_next_line.c checker_map.c

FLAGS 			=	-Wall -Wextra -Werror 
OBJS			=    $(SRCS:.c=.o)

NAME    		=    so_long

PRINTF    		=    ./ft_printf/libftprintf.a

LIBFT    		=    ./libft/libft.a

.PHONY:		all clean fclean re bonus

all: $(NAME)

$(NAME):  $(LIBFT)  $(PRINTF) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT)  $(PRINTF) -o $(NAME)

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