##
## Makefile for  in /home/manu/TEK2/cpp_arcade/graphics/ncurses
## 
## Made by Manu
## Login   <vallen_e@epitech.net>
## 
## Started on  Wed Mar 15 02:56:56 2017 Manu
## Last update Sun Apr  9 20:29:26 2017 Manu
##

CC			= g++ -fPIC -shared

NAME			= ../lib_arcade_ncurses.so

RM			= rm -rf

SRC			= Ncurses.cpp \

CXXFLAGS	=	-Wall
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	-std=c++11


LDXXFLAGS	+=	-lncurses

all:			$(NAME)

$(NAME):
			$(CC) $(SRC) $(LDXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
