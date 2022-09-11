TESTFILE 	= tests_libft.c
TESTPROGRAM = libft.tests
SRCDIR		= ../src/
NAME		= libft.a
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror

test:		fclean
			make -C ../src
			@cc ${CFLAGS} -o ${TESTPROGRAM} -I . -I ${SRCDIR} ${TESTFILE} -L${SRCDIR} -lft
			@./${TESTPROGRAM}

leakfull:	test
			valgrind --error-exitcode=42 --leak-check=full ./${TESTPROGRAM}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME} ${TESTPROGRAM}
