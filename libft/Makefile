CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c \
		ft_strlen.c ft_strrchr.c ft_bzero.c ft_isascii.c ft_memchr.c \
		ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_isalnum.c \
		ft_memset.c ft_strlcpy.c ft_strnstr.c ft_toupper.c \
		ft_isdigit.c ft_memcmp.c ft_calloc.c ft_strdup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re