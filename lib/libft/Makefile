NAME = libft.a

SRCS = ft_atoi.c \
 ft_memcmp.c \
 ft_strdup.c \
 ft_strtrim.c \
 ft_bzero.c \
 ft_memcpy.c \
 ft_striteri.c \
 ft_substr.c \
 ft_calloc.c \
 ft_memmove.c \
 ft_strjoin.c \
 ft_tolower.c \
 ft_isalnum.c \
 ft_memset.c \
 ft_strlcat.c \
 ft_toupper.c \
 ft_isalpha.c \
 ft_putchar_fd.c \
 ft_strlcpy.c \
 ft_isascii.c \
 ft_putendl_fd.c \
 ft_strlen.c \
 ft_isdigit.c \
 ft_putnbr_fd.c \
 ft_strmapi.c \
 ft_isprint.c \
 ft_putstr_fd.c \
 ft_strncmp.c \
 ft_itoa.c \
 ft_split.c \
 ft_strnstr.c \
 ft_memchr.c \
 ft_strchr.c \
 ft_strrchr.c \
 get_next_line.c \
 ft_hextoa.c \
 ft_printchr.c \
 ft_printf.c \
 ft_printhex.c \
 ft_printnbr.c \
 ft_printptr.c \
 ft_printstr.c \
 ft_ptrtoa.c \
 ft_uitoa.c \
 ft_freejoin.c \
 ft_charcount.c

BONUS = ft_lstadd_back_bonus.c \
 ft_lstdelone_bonus.c \
 ft_lstnew_bonus.c \
 ft_lstadd_front_bonus.c \
 ft_lstiter_bonus.c \
 ft_lstsize_bonus.c \
 ft_lstclear_bonus.c \
 ft_lstlast_bonus.c \
 ft_lstmap_bonus.c

FLAGS = -Wall -Werror -Wextra -g

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

${OBJS}: ${SRCS}
	cc -c ${SRCS} -Includes ${FLAGS}

${BONUS_OBJS}: ${BONUS}
	cc -c ${BONUS} -Includes ${FLAGS}


clean:
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
