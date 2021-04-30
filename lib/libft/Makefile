# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 11:34:43 by anchenni          #+#    #+#              #
#    Updated: 2020/07/16 20:06:50 by anchenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isprint.c	\
			ft_strchr.c		\
			ft_strlen.c		\
			ft_strncmp.c	\
			ft_strrchr.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_isdigit.c	\
			ft_isalpha.c	\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memmove.c	\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_itoa.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_split.c		\
			ft_strmapi.c	\

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS}

all:		$(NAME)

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re