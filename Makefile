# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 13:40:03 by mbelorge          #+#    #+#              #
#    Updated: 2020/02/10 14:36:21 by mbelorge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -L./minilibX/ ./minilibX/libmlx.a -lm -lmlx -lX11 -lXext -lbsd

NAME = so_long

SRCS	=	so_long.c\
			parsing/build_map.c\
			raycasting/keyboard_control.c\
			parsing/check_map.c\
			raycasting/sprite_init.c\
			parsing/check_error.c\
			parsing/error.c\
			parsing/check_fd.c\
			raycasting/initialisation.c\
			parsing/free.c\
			raycasting/moove.c\
			raycasting/draw.c\
			tools/color_tools.c\
			tools/pixel_tools.c\

OBJSRCS = $(SRCS:.c=.o)

$(NAME) : $(OBJSRCS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf Cub3D
	@echo "\033[33m[Cub3D compilation...]"
	@echo "\033[33m[Libft compilation...]"
	$(MAKE) -C ./libft
	@gcc -o $(NAME) -I include.h $(OBJSRCS) $(MLX) ./libft/libft.a -Wall -Wextra -Werror -g3
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf save.bmp

re : fclean all