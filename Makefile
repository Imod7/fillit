#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ravan-de <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/02 15:57:41 by ravan-de      #+#    #+#                  #
#    Updated: 2019/05/31 18:56:29 by ravan-de      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

OBJ = ft_putsquare.o ft_putbin.o ft_recursive.o fillit.o ft_readtet.o

FLAGS = -Wall -Wextra -Werror

INCL = libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)  

%.o: %.c
	gcc -c $(FLAGS) -I $(INCL) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

doei: clean
	rm -f *~
	rm -f *#