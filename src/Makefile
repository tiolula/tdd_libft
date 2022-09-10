
NAME		= libft.a
SRCS		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_toupper.c
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar crs ${NAME} ${OBJS}

${OBJS}:
			cc ${CFLAGS} -I . -c ${SRCS}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

