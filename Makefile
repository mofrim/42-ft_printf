# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/06/22 11:12:07 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC			= cc
CFLAGS	= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= ftpr_printf.c \
					ftpr_utils.c \
					ftpr_utoa.c \
					ftpr_parse_args.c \
					ftpr_convert_smpl_cdsi.c \
					ftpr_convert_smpl_p.c \
					ftpr_convert_smpl_x.c \
					ftpr_convert_flag.c \
					ftpr_convert_smpl.c \
					ftpr_isconv.c


OBJ_DIR		= obj
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME) tests/test_ftprintf.c
	# $(CC) $(CFLAGS) -o tests/test_ftprintf tests/test_ftprintf.c $(LIBFT) libftprintf.a
	$(CC) -o tests/test_ftprintf tests/test_ftprintf.c $(LIBFT) libftprintf.a
	@echo "Running test_printf..."
	@echo
	@./tests/test_ftprintf

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re libft test
