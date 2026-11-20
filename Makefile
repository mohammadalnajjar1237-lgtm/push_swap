NAME = push_swap
SLIB = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c checking_args_util.c extra_func.c modified_libft_util.c operations.c operations2.c sort_simple.c\
sort_complex.c sort_medium.c sort_utils.c sort_adaptive.c operations3.c sort_utils2.c main.c
OBJS = ${SRCS:.c=.o}
VAR = ar rcs
HEADER = push_swap.h
BONUS_SRCS = operations_bonus.c operations_bonus2.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
all : SUBMAKE ${NAME}
${NAME} : ${SLIB}
		${CC} ${CFLAGS} main.c ${SLIB} -o ${NAME}
${SLIB} : ${OBJS} ${HEADER}
	cp libft/libft.a ${SLIB}
	${VAR} ${SLIB} ${OBJS}
SUBMAKE : 
	make -C libft
bonus : SUBMAKE checker

checker : main_bonus.c ${BONUS_OBJS} ${SLIB}
	${CC} ${CFLAGS} main_bonus.c ${BONUS_SRCS} ${SLIB} -o checker
clean :
	make clean -C libft
	rm -f ${OBJS} ${BONUS_OBJS}
fclean : clean
	make fclean -C libft
	rm -f ${SLIB} ${NAME} checker
re : fclean all
.PHONY: all clean fclean re SUBMAKE bonus
