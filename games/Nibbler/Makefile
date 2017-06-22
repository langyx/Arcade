##
## Makefile for  in /home/manu/TEK2/cpp_arcade/games/Nibbler
## 
## Made by Manu
## Login   <vallen_e@epitech.net>
## 
## Started on  Thu Apr  6 18:58:04 2017 Manu
## Last update Thu Apr  6 18:58:34 2017 Manu
##


CC			= g++ -fPIC -shared

NAME			= ../lib_arcade_Nibbler.so

RM			= rm -rf

SRC			= Nibbler.cpp \
			  ../../map/Map.cpp \
			  ../../character/Character.cpp \
			  ../../score/Score.cpp

CXXFLAGS	+= 	-Wall
CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	-std=c++11


LDXXFLAGS	+=

all:			$(NAME)

$(NAME):
			$(CC) $(CXXFLAGS) $(SRC) $(LDXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
