# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/07/16 07:43:22 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC			= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
					ftpr_smpl_utils.c \
					ftpr_smpl_utoa.c \
					ftpr_smpl_convert_cdsi.c \
					ftpr_smpl_convert_p.c \
					ftpr_smpl_convert_x.c \
					ftpr_smpl_convert.c

# stupid little hack, but good for learning some more make voodoo ;)
# removes leading './' again
# SRCS = $(patsubst ./%,%,$(SRCS_IN))

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
BONUS_SRCS 	= $(SRCS) \
							ftpr_compl_parse_bonus.c \
							ftpr_compl_check_fmt_bonus.c \
							ftpr_compl_convert_bonus.c \
							ftpr_compl_utils_bonus.c \
							ftpr_compl_is_conv_bonus.c \
							ftpr_compl_flagging_bonus.c \
							ftpr_compl_do_conv.c \
							ftpr_compl_convert_d.c \
							ftpr_compl_convert_u.c

# oh! again that stupid little hack.
# BONUS_SRCS = $(patsubst ./%,%,$(BONUS_SRCS_IN)) $(SRCS)

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
	cp $(LIBFT) $(BONUS_NAME)
	ar -rcs $(BONUS_NAME) $(BONUS_OBJS)
	cp $(BONUS_NAME) $(NAME)
	rm $(BONUS_NAME)

# ... this is the missing hack for making even `make bonus` never ever relink.
# seperating the every file touching action from bonus-rule
# \o/ \o/ \o/
bonus: $(BONUS_NAME) $(NAME)
########################################## bonus end

########################################## tests start
tests: all tests/test_ftprintf_smpl.c tests/test_ftpr_smpl-func.c
	cc -o test_ftprintf_smpl tests/test_ftprintf_smpl.c tests/test_ftpr_smpl-func.c libftprintf.a
	./test_ftprintf_smpl

test: bonus tests/test_ftprintf.c tests/test_ftpr_smpl-func.c
	cc -DBONUS -o test_ftprintf tests/test_ftprintf.c tests/test_ftpr_smpl-func.c libftprintf.a
	./test_ftprintf

testf: 
	cc -o test_printf_flags tests/test_printf_flags.c
	./test_printf_flags

testclean:
	rm -f ./test_printf_flags ./test_ftprintf ./test_ftprintf_smpl
########################################## tests end

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

# NOTE: remove testclean before final submission
fclean: clean testclean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
