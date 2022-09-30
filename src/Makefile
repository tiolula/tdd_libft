
NAME		= libft.a
SRCS		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_toupper.c ft_bzero.c ft_atoi.c ft_itoa.c ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strnstr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_putchar_fd.c ft_putstr_fd.c ft_putend1_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strdup.c ft_striteri.c
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

