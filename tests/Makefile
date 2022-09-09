TESTFILE 	= tests_libft.c
TESTPROGRAM = libft.tests
SRCDIR		= ../src/
NAME		= libft.a
SRCS		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_memset.c
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror

test:		build
			@cc ${CFLAGS} -o ${TESTPROGRAM} -I . -I ${SRCDIR} ${TESTFILE} -L. -lft
			@./${TESTPROGRAM}

leak:		test
			valgrind --error-exitcode=42 ./${TESTPROGRAM}

leakfull:	test
			valgrind --error-exitcode=42 --leak-check=full ./${TESTPROGRAM}

build:		${NAME}

${NAME}:	${OBJS}
			ar crs ${NAME} ${OBJS}

${OBJS}: 
			cc ${CFLAGS} -I . -c ${addprefix ${SRCDIR}, ${SRCS}}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME} ${TESTPROGRAM}

re:			fclean test

