# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokarimi <mokarimi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:09:44 by mokarimi          #+#    #+#              #
#    Updated: 2025/10/30 16:16:09 by mokarimi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strjoin.c ft_atoi.c ft_strlcat.c ft_bzero.c ft_calloc.c \
ft_memcmp.c ft_strlen.c ft_isalnum.c ft_memcpy.c ft_strmapi.c ft_memchr.c ft_strlcpy.c \
ft_isalpha.c ft_memmove.c ft_strncmp.c ft_isascii.c ft_memset.c ft_strnstr.c \
ft_isdigit.c ft_putchar_fd.c ft_strrchr.c ft_isprint.c ft_putendl_fd.c ft_strtrim.c \
ft_itoa.c ft_putnbr_fd.c ft_substr.c ft_putstr_fd.c ft_tolower.c \
ft_split.c ft_toupper.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_free_split.c

BONUS_SRCS = ft_lstadd_back_bonus.c   ft_lstlast_bonus.c \
ft_lstadd_front_bonus.c ft_lstmap_bonus.c ft_lstclear_bonus.c \
ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstsize_bonus.c \
ft_lstiter_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean