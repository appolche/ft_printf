SOURCE	=	ft_char.c\
			ft_find_type.c\
			ft_hex.c\
			ft_integer.c\
			ft_itoa_hex.c\
			ft_itoa_unsigned.c\
			ft_parse_flag.c\
			ft_parse_format_string.c\
			ft_parse_type.c\
			ft_pointr.c\
			ft_printf.c\
			ft_string.c\
			ft_stardot.c\
			ft_unsigned.c\

HEADER	=	ft_printf.h libft/libft.h

LIBFTPATH = libft/libft.a

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	libftprintf.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror


all:		
			make -C libft
			make ${NAME}

%.o: %.c ${HEADER}
			gcc ${CFLAGS} -I libft -c $< -o $@

${NAME}:	${OBJECTS} ${LIBFTPATH} 
			
			cp  ${LIBFTPATH} $(NAME)
			${AR} ${NAME} ${OBJECTS}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

debug:		re
			gcc -g  *.c ./libft/libft.a

.PHONY:		all clean fclean bonus