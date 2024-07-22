# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/07/22 12:10:10 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC			= cc

## for unit test to work:
CFLAGS	= -Wall -Wextra -Werror

# we are building a library which might even end up being a shared lib. so
# generating "Position Independent Code" seems like a good idea.
# additionally printf-unit-test needs this. some literature:
# https://stackoverflow.com/questions/5311515/gcc-fpic-option
PIC	=	-fPIC

SRCS_IN	= ./ft_printf.c \
					./smpl_utils.c \
					./smpl_utoa.c \
					./smpl_convert_cdsi.c \
					./smpl_convert_p.c \
					./smpl_convert_x.c \
					./smpl_convert.c

# stupid little hack, but good for learning some more make voodoo ;)
# removes leading './' again
SRCS = $(patsubst ./%,%,$(SRCS_IN))

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
	$(CC) $(CFLAGS) $(PIC) -c $< -o $@

all: $(NAME)

.mandatory: $(OBJS)
	rm -f .bonus
	touch .mandatory
	make -C $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(NAME): .mandatory

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

########################################## bonus start
BONUS_SRCS_IN = ./compl_parse_bonus.c \
								./compl_check_fmt_bonus.c \
								./compl_convert_bonus.c \
								./compl_utils_bonus.c \
								./compl_is_conv_bonus.c \
								./compl_flagging_bonus.c \
								./compl_do_conv_bonus.c \
								./compl_convert_d_bonus.c \
								./compl_convert_u_bonus.c \
								./compl_convert_c_bonus.c \
								./compl_convert_s_bonus.c \
								./compl_convert_p_bonus.c \
								./compl_convert_x_bonus.c

# oh! again that stupid little hack.
BONUS_SRCS = $(patsubst ./%,%,$(BONUS_SRCS_IN)) $(SRCS)

# the logic behind choosing different names for bonus-objs is, that it enables
# us to completely seperate compilation of bonus and mandatory. the real
# bonus-objs only get compiled into the library because we use $(BONUS_OBJS) as
# prequisite in $(BONUS_NAME) rule. in $(NAME) rule $(OBJS) is used which
# does not include any bonus files.
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/bonus-%.o)
BONUS_HDR = ft_printf_bonus.h
BONUS_NAME = libftprintf_bonus.a

$(OBJ_DIR)/bonus-%.o: %.c $(HDR) $(BONUS_HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(PIC) -DBONUS -c $< -o $@

.bonus: $(BONUS_OBJS)
	rm -f .mandatory
	touch .bonus
	make -C $(LIBFT_PATH) all
	cp $(LIBFT) $(BONUS_NAME)
	ar -rcs $(BONUS_NAME) $(BONUS_OBJS)
	mv $(BONUS_NAME) $(NAME)

# ... this is the missing hack for making even `make bonus` never ever relink.
# \o/ \o/ \o/
bonus: .bonus
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
	rm -f $(NAME) $(BONUS_NAME) .mandatory .bonus

re: fclean all

.PHONY: all clean fclean re bonus testclean
