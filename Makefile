# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/07/11 10:24:00 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC			= cc
CFLAGS	= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= ft_printf.c \
					ftpr_utils.c \
					ftpr_utoa.c \
					ftpr_convert_smpl_cdsi.c \
					ftpr_convert_smpl_p.c \
					ftpr_convert_smpl_x.c \
					ftpr_convert_smpl.c

OBJ_DIR		= obj
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

# here $(OBJ_DIR) is a 'order-only' prequisite. that means it is only build if
# it does not exist. not if it was only updated. this is what we want here.
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
