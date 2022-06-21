# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drakan <drakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 19:40:05 by drakan            #+#    #+#              #
#    Updated: 2021/12/27 19:40:07 by drakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_putnbr.c ft_putchar.c ft_putstr.c

OBJS	= $(SRCS:.c=.o)

HEADER	= libft.h

all:	$(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I $(HEADER)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	 clean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
