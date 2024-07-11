# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/07/11 20:05:07 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC			= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
					ftpr_utils.c \
					ftpr_utoa.c \
					ftpr_convert_smpl_cdsi.c \
					ftpr_convert_smpl_p.c \
					ftpr_convert_smpl_x.c \
					ftpr_convert_smpl.c

HDR	= ft_printf.h

OBJ_DIR		= obj
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

# here $(OBJ_DIR) is a 'order-only' prequisite. that means it is only build if
# it does not exist. not if it was only updated. this is what we want here.
#
# another cool thing is also happening here: the $< inside the recipe is only
# taking all the files from $(SRCS) which is the first prequisite. $(HDR) is
# only a dependency. this is why noone is trying to compile ft_printf.h
$(OBJ_DIR)/%.o: %.c $(HDR) | $(OBJ_DIR)
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

########################################## bonus start
BONUS_SRCS	= $(SRCS) \
							ftpr_convert_compl_bonus.c

# the logic behind choosing different names for bonus-objs is, that it enables
# us to completely seperate compilation of bonus and mandatory. the real
# bonus-objs only get compiled into the library because we use $(BONUS_OBJS) as
# prequisite in $(BONUS_NAME) rule. in $(NAME) rule $(OBJS) is used which
# does not include any bonus files.
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/bonus-%.o)
BONUS_HDR = ft_printf_bonus.h
BONUS_NAME = libftprintf_bonus.a

$(OBJ_DIR)/bonus-%.o: %.c $(HDR) $(BONUS_HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DBONUS -c $< -o $@

# this and...
$(BONUS_NAME): $(BONUS_OBJS)
	make -C $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar -rcs $(BONUS_NAME) $(BONUS_OBJS)
	cp $(BONUS_NAME) $(NAME)

# ... this is the missing hack for making even `make bonus` never ever relink.
# seperating the every file touching action from bonus-rule
# \o/ \o/ \o/
bonus: $(BONUS_NAME)
########################################## bonus end

test: all
	cc -o test_ftprintf tests/test_ftprintf.c libftprintf.a
	./test_ftprintf

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
