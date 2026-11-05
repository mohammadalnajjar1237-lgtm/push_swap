NAME = push_swap.a
##CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c checking_args_util.c extra_func.c modified_libft_util.c operations.c operations2.c sort_simple.c\
sort_complex.c
OBJS = ${SRCS:.c=.o}
VAR = ar rcs
HEADER = push_swap.h
SRCS_BOUNS = operations_bouns.c operations2_bouns.c
BOUNS_NAME = push_swap_bouns.a
BOUNS_OBJS = ${SRCS_BOUNS:.c=.o}
all : ${NAME}
${NAME} : SUBMAKE ${OBJS} ${HEADER}
	cp libft/libft.a ${NAME}
	${VAR} ${NAME} ${OBJS}
SUBMAKE : 
	make -C libft
bouns : ${BOUNS_OBJS} all
	cp ${NAME} ${BOUNS_NAME}
	${VAR} ${BOUNS_NAME} ${BOUNS_OBJS}
	${CC} main_bouns.c ${BOUNS_NAME} -o checker
clean :
	make clean -C libft
	rm -f ${OBJS}
fclean : clean
	make fclean -C libft
	rm -f ${NAME}
re : fclean all
.PHONY: all clean fclean re SUBMAKE bouns##la tensa edeef el flags o clean lal bouns

