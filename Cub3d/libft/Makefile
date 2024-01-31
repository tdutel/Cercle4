# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 16:33:32 by leo               #+#    #+#              #
#    Updated: 2023/09/18 23:12:57 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS			=	-Wall -Wextra -Werror -g

CC				=	cc

OBJS_DIR	=	.OBJS/

STR_FILES		=	str/ft_strchr.c \
					str/ft_strnstr.c \
					str/ft_substr.c \
					str/ft_strlcpy.c \
					str/ft_strtrim.c \
					str/ft_itoa.c \
					str/ft_toupper.c \
					str/ft_strmapi.c \
					str/ft_strdup.c \
					str/ft_split.c \
					str/ft_striteri.c \
					str/ft_strncmp.c \
					str/ft_strcmp.c \
					str/ft_strrchr.c \
					str/ft_tolower.c \
					str/ft_strjoin.c \
					str/ft_strlen.c \
					str/ft_str_revert.c \
					./str/ft_strsep.c
PRINTING_FILES	=	print/ft_putstr_fd.c \
					print/ft_putnbr_fd.c \
					print/ft_putchar_fd.c \
					print/ft_putendl_fd.c 
BOOLEAN_FILES	=	boolean/ft_is_in_str.c \
					boolean/ft_isprint.c \
					boolean/ft_isdigit.c \
					boolean/ft_isascii.c \
					boolean/ft_isalpha.c \
					boolean/ft_isalnum.c 
MEMORY_FILES	=	memory/ft_memset.c \
					memory/ft_bzero.c \
					memory/ft_memmove.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c \
					memory/ft_calloc.c \
					memory/ft_memcpy.c
LIST_FILES		=	list/ft_lstadd_back.c \
					list/ft_lstmap.c \
					list/ft_lstiter.c \
					list/ft_lstnew.c \
					list/ft_lstlast.c \
					list/ft_lstclear.c \
					list/ft_lstsize.c \
					list/ft_lstdelone.c \
					list/ft_lstadd_front.c
INT_FILES		=	ft_atoi.c \
					ft_atoi_ullong.c
PRINTF_FILES	=	ft_printf/flags/print_precision.c \
					ft_printf/flags/print_field_width.c \
					ft_printf/flags/print_space.c \
					ft_printf/flags/get_details.c \
					ft_printf/flags/print_padding.c \
					ft_printf/flags/print_plus.c \
					ft_printf/flags/field_width_utils.c \
					ft_printf/flags/predict.c \
					ft_printf/flags/priorities.c \
					ft_printf/flags/print_minus.c \
					ft_printf/flags/print_pound.c \
					ft_printf/ft_printf_utils.c \
					ft_printf/ft_printf.c
JOINF_FILES		=	ft_joinf/ft_joinf_utils.c \
					ft_joinf/ft_joinf.c


FILES_GNL		=	./gnl/get_next_line.c \
					./gnl/get_next_line_utils.c

FILES			=	$(PRINTING_FILES) \
					$(STR_FILES) \
					$(BOOLEAN_FILES) \
					$(MEMORY_FILES) \
					$(LIST_FILES) \
					$(INT_FILES) \
					$(FILES_GNL) \
					$(PRINTF_FILES) \
					$(JOINF_FILES) \

OBJS				=	$(addprefix $(OBJS_DIR), $(FILES:.c=.o))
HEADER				=	libft.h

RED					=	\033[0;31m
GREEN				=	\033[0;32m
NC					=	\033[0m

NAME			=	libft.a

HEADER			=	libft.h

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)
					@echo "$(GREEN)Libft compiled :D$(NC)"
					@norminette $(FILES)libft.h | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'

$(OBJS_DIR)%.o:	%.c $(HEADER) Makefile | $(OBJS_DIR)
				$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
				@mkdir -p $(OBJS_DIR)
				@mkdir -p $(OBJS_DIR)boolean
				@mkdir -p $(OBJS_DIR)ft_joinf
				@mkdir -p $(OBJS_DIR)ft_printf
				@mkdir -p $(OBJS_DIR)ft_printf/flags
				@mkdir -p $(OBJS_DIR)gnl
				@mkdir -p $(OBJS_DIR)list
				@mkdir -p $(OBJS_DIR)memory
				@mkdir -p $(OBJS_DIR)print
				@mkdir -p $(OBJS_DIR)str

all:			$(NAME)

clean:
					rm -rf $(OBJS) $(OBJS_DIR)

fclean:			clean
					rm -f $(NAME)
				
re:				fclean all

.PHONY:			all	clean	fclean	re 
