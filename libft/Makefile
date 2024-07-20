# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 13:53:42 by fmaurer           #+#    #+#              #
#    Updated: 2024/07/20 20:28:28 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c \
						 ft_lstadd_front.c \
						 ft_lstsize.c \
						 ft_lstlast.c \
						 ft_lstadd_back.c \
						 ft_lstclear.c \
						 ft_lstdelone.c \
						 ft_lstiter.c \
						 ft_lstmap.c \
						 $(SRCS)

OBJS_DIR = objs
OBJS	= $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
OBJS_BONUS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(BONUS_SRCS))
CC = cc
CC_FLAGS = -Wall -Wextra -Werror

# we are building a library which might even end up being a shared lib. so
# generating "Position Independent Code" seems like a good idea.
# additionally printf-unit-test needs this. some literature:
# https://stackoverflow.com/questions/5311515/gcc-fpic-option
PIC	=	-fPIC

INC = -I ./

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling: $^"
	@ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(PIC) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	@echo "Bonus Compiling: $^"
	@ar -rcs $(NAME) $(OBJS_BONUS)

.PHONY: clean fclean re all
