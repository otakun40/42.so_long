# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/01/29 12:48:34 by pjacoby           #+#    #+#             #
#   Updated: 2022/01/31 22:42:43 by pjacoby          ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME 		=	so_long

HEADER 		=	so_long.h

LIBMLX 		=	./minilibx/libmlx.a

LIBFT 		=	./libft/libft.a

MLX_FLAGS 	= 	-framework OpenGL -framework AppKit

SRCS 		=	so_long.c	react_utils.c	map_utils.c	map_properties_utils.c	\
				get_images_utils.c	print_map_utils.c	move_utils.c		\
				check_map_utils.c	check_map_utils2.c

BONUS_SRCS	=	${SRCS:.c=_bonus.c} 									\
				get_player_images_utils_bonus.c							\
				get_enemy_images_utils_bonus.c							\
				enemy_move_utils_bonus.c								\
				print_utils_bonus.c


OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS 	= 	${BONUS_SRCS:.c=.o}

CC 			= 	gcc

CFLAGS 		= 	-Wall -Wextra -Werror

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} $< -I./minilibx -c -o $@

%_bonus.o	:	%_bonus.c ${HEADER} structs_bonus.h
				${CC} ${CFLAGS} $< -I./minilibx -c -o $@

${NAME}		:	${OBJS} ${LIBMLX} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS}	-Llibft -Lminilibx -lft -lmlx \
				${MLX_FLAGS} -o ${NAME}

bonus		:	${BONUS_OBJS} ${LIBMLX} ${LIBFT}
				${CC} ${CFLAGS} ${BONUS_OBJS}	-Llibft -Lminilibx -lft	\
				-lmlx ${MLX_FLAGS} -o bonus

${LIBMLX}	:	libmlx ;

libmlx		:
				${MAKE} -C ./minilibx/

${LIBFT}	:	libft ;

libft		:
				${MAKE}	-C ./libft

clean		:
				rm -rf ${OBJS} ${BONUS_OBJS}
				${MAKE} -C ./libft clean
				${MAKE} -C ./minilibx clean

fclean		:
				rm -rf ${OBJS} ${BONUS_OBJS} ${NAME} bonus ${LIBMLX}
				${MAKE} -C ./libft fclean
				${MAKE} -C ./minilibx clean

all			:	${NAME} bonus

re			:	fclean ${NAME}

run			:	${NAME}
				./${NAME} ./maps/map.ber

.PHONY		:	all re clean fclean debug debug_bonus ch_leak run libft
