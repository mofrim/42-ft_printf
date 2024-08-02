# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/02 08:13:55 by fmaurer          ###   ########.fr        #
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

BONUS_SRCS_IN = ./compl_parse_bonus.c \
								./compl_check_fmt_bonus.c \
								./compl_convert_bonus.c \
								./compl_utils_bonus.c \
								./compl_is_conv_bonus.c \
								./compl_flag_utils_bonus.c \
								./compl_do_conv_bonus.c \
								./compl_convert_d_bonus.c \
								./compl_convert_u_bonus.c \
								./compl_convert_c_bonus.c \
								./compl_convert_s_bonus.c \
								./compl_convert_p_bonus.c \
								./compl_convert_x_bonus.c

# stupid little hack, but good for learning some more make voodoo ;)
# removes leading './' again
SRCS = $(patsubst ./%,%,$(SRCS_IN)) $(patsubst ./%,%,$(BONUS_SRCS_IN))

BONUS_HDR = ft_printf_bonus.h
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
$(OBJ_DIR)/%.o: %.c $(HDR) $(BONUS_HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(PIC) -DBONUS -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: all

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
