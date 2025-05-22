# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 12:37:42 by alosada-          #+#    #+#              #
#    Updated: 2025/02/21 12:37:47 by alosada-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Indicamos el nombre de nuestro ejecutable
NAME = libft.a

#Declaramos la variable con los archivos que van a componer nuestro ejecutable. El \ indica fin de linea
SOURCES = 	ft_isalpha.c 	\
			ft_isdigit.c 	\
			ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isprint.c 	\
			ft_strlen.c 	\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c 	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strnstr.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\

#Declaramos variable para decir cuales van a ser nuestros archivos objeto, los .c y los .o
OBJECTS = $(SOURCES:.c=.o)

#Indicamos cual va a ser nuetro compilador
CC = gcc

#Declaramos nuestros flags
CFLAGS = -Wall -Wextra -Werror

#Declaramos variable para el comando clean
RM = rm -f

#Funcion principal
all: $(NAME)

#Se compila la libreria
$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

#Borrado de objetos
clean:
	$(RM) $(OBJECTS)

#Borrado de objetos y del ejecutable
fclean: clean
	$(RM) $(NAME)

#Lo borra todo
re: fclean all 

#Indicamos que no cree ningun archivo con estos nombres
.PHONY: all clean fclean re
