NAME = libftprintf.a
CC = cc
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
VAR = ar rcs
SRCS = ft_printf.c ft_itoa_void.c ft_putnbr_hexa.c ft_putstr.c ft_putchar.c print_double.c
OBJS = ${SRCS:.c=.o}
	
all : ${NAME}
${NAME} : ${OBJS}
	cp libft/libft.a ${NAME}
	${VAR} ${NAME} ${OBJS}
clean :
	rm -f ${OBJS}
fclean : clean
	rm -f ${NAME}
re : fclean all
.PHONY: all clean fclean re
