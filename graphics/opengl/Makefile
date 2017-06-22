##
## Makefile for openGLARCADE in /home/yannis/tek2/rendu/cpp_arcade/graphics/opengl
## 
## Made by yannis
## Login   <yannis.lang@epitech.eu>
## 
## Started on  Wed Mar 15 02:55:11 2017 yannis
## Last update Thu Mar 30 02:39:08 2017 yannis
##

CC			= g++ -fPIC -shared

NAME			= ../lib_arcade_opengl.so

RM			= rm -rf

SRC			=	openGlLib.cpp

CXXFLAGS	+= 	-Wall
CXXFLAGS	+=	#-Werror
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	##-I./include
CXXFLAGS	+=	-std=c++11


LDXXFLAGS	+=	-L./lib -lY2 -lSDL2_ttf -lGL -lSDL2_image -I./inc/ 

all:			$(NAME)

$(NAME):
			$(CC) $(CXXFLAGS) $(SRC) $(LDXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
