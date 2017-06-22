##
## Makefile for openGLARCADE in /home/yannis/tek2/rendu/cpp_arcade/graphics/opengl
## 
## Made by yannis
## Login   <yannis.lang@epitech.eu>
## 
## Started on  Wed Mar 15 02:55:11 2017 yannis
## Last update Mon Apr  3 02:00:04 2017 yannis
##

CC			= g++ -fPIC -shared

NAME			= ../lib_arcade_Pacman.so

RM			= rm -rf

SRC			= Pacman.cpp \
			  Ghost.cpp \
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
