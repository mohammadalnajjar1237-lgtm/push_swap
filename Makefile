NAME = push_swap.a
##CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c checking_args_util.c extra_func.c modified_libft_util.c modified_libft_util2.c operations.c operations2.c sort_complex.c sort_simple.c
OBJS = ${SRCS:.c=.o}
VAR = ar rcs
HEADER = push_swap.h
all : ${NAME}
${NAME} : SUBMAKE ${OBJS} ${HEADER}
	cp libft/libft.a ${NAME}
	${VAR} ${NAME} ${OBJS}
SUBMAKE : 
	make -C libft
clean :
	make clean -C libft
	rm -f ${OBJS}
fclean : clean
	make fclean -C libft
	rm -f ${NAME}
re : fclean all
.PHONY: all clean fclean re SUBMAKE

