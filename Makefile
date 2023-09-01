# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 12:23:08 by jsteenpu          #+#    #+#              #
#    Updated: 2023/05/31 10:50:46 by jsteenpu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBC = ar rcs
RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror

SCRS = ft_format_c.c ft_format_s.c \
			ft_format_p.c ft_format_i_d.c \
			ft_format_u.c ft_format_x.c \
			ft_printf.c

OBJS = $(SCRS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
