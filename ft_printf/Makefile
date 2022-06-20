SRCS    		=   ft_printf.c ft_printf_helper.c ft_check.c

FLAGS 			=	-Wall -Wextra -Werror
OBJS			=    $(SRCS:.c=.o)

NAME    		=    libftprintf.a
RM        		=     rm -f

all:    $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean:    clean
	${RM} ${NAME}

re:        fclean all

.PHONY:		all clean fclean re bonus
