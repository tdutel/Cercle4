# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 13:40:06 by tdutel            #+#    #+#              #
#    Updated: 2023/07/25 14:43:18 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = a.out
HEADER = Fixed.hpp Point.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC =	main.cpp Fixed.cpp Point.cpp

OBJ = $(SRC:.cpp=.o)


all :
	make $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)
	rm -f *.replace

fclean : 
	$(MAKE) clean
	rm -f $(NAME)

re : fclean
	make all

debug :
	$(MAKE) all CFLAGS="-Wall -Werror -Wextra -std=c++98 -g"

rdebug : fclean
	make debug

norme :
	norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re debug rdebug
