# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:53:00 by tdutel            #+#    #+#              #
#    Updated: 2023/04/14 15:42:02 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
HEADER =
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC =	megaphone.cpp

OBJ = $(SRC:.cpp=.o)


all :
	make $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

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
