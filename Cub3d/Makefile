#---COMMON_VAR-----------------------------------
NAME			=	cub3D
CC				=	cc
RM				=	rm -rf

RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
NC				=	\033[0m

#---LIBFT_VAR-------------------------------------
LIBFT_PATH		=	libft/
LIBFT_A			=	$(LIBFT_PATH)/libft.a
LIBFT_INCLUDE	=	-I $(LIBFT_PATH)
LIBFT_LIB		=	-L $(LIBFT_PATH) -l ft

#---CUB_VAR---------------------------------------
SRC				=	srcs/main.c \
					srcs/init/init.c \
					srcs/init/init_player.c \
					srcs/parsing/parse.c \
					srcs/garbage_collector.c \
					srcs/parsing/get_map.c \
					srcs/parsing/get_map_helper.c \
					srcs/parsing/is_map_closed.c \
					srcs/parsing/get_wall.c	\
					srcs/render/render.c \
					srcs/render/line.c \
					srcs/render/horr_line.c \
					srcs/render/vert_line.c \
					srcs/render/minimap.c \
					srcs/render/casting.c \
					srcs/render/door.c \
					srcs/input/input.c \
					srcs/input/set_player_pos.c

OBJS_DIR		=	.OBJS/
OBJS			=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

HEADER_DIR		=	headers/
HEADER_FILE		=	headers/cub3d.h \
					headers/render.h \
					headers/init.h \
					headers/input.h \
					headers/struct.h \
					headers/parse.h \
					headers/err.h
BASE_INCLUDE	=	-I $(HEADER_DIR)


#---MINILIBX-------------------------------------
MLX_PATH		=	minilibx
MLX_FLAGS		=	-lXext -lX11 -lm -lz
MLX_INCLUDES	=	-I $(MLX_PATH)
MLX_A			=	$(MLX_PATH)/libmlx_Linux.a
MLX_LIB			=	-L $(MLX_PATH) -l mlx_Linux

# ----
FLAGS			=	-Wall -Werror -Wextra -g3 -O2
INCLUDES		=	$(MLX_INCLUDES) $(BASE_INCLUDE) $(LIBFT_INCLUDE)
LIBS			=	$(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS)

#---RULES----------------------------------------

all:			$(NAME)

$(NAME):		$(MLX_A) $(LIBFT_A) $(OBJS_DIR) Makefile $(HEADER_FILE) $(OBJS)
				$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $@

				@# @echo "\33[2K\r$(GREEN)Cub3d compiled :D$(NC)"


$(OBJS_DIR)%.o:	%.c $(MLX_A) $(HEADER_FILE)
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
				@# @echo -n "\33[2K\r$(YELLOW)Compiled $<"

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)
norm:
				norminette $(SRC) $(MLX_HEADER_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(NC)"}'


$(MLX_A):
				make -C $(MLX_PATH)

$(LIBFT_A):
				make -C $(LIBFT_PATH)


clean:
				make clean -C $(MLX_PATH)
				make clean -C $(LIBFT_PATH)
				@# @echo "$(GREEN)Done\n"
				@# @echo "$(RED)Deleting cub3d object...\n"
				$(RM) $(OBJS_DIR)
				@# @echo "$(GREEN)Done\n"

fclean:			clean
				@# @echo "$(RED)Deleting cub3d executable..."
				rm -f $(NAME)
				@# @echo "$(GREEN)Done\n"

re:				fclean all

.PHONY:			all clean fclean re
