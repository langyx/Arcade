##
## Makefile for openGLARCADE in /home/yannis/tek2/rendu/cpp_arcade/graphics/opengl
## 
## Made by yannis
## Login   <yannis.lang@epitech.eu>
## 
## Started on  Wed Mar 15 02:55:11 2017 yannis
## Last update Wed Mar 15 04:31:01 2017 Rémy
##
CC		= g++ -fPIC -shared

NAME		= ../lib_arcade_sfml.so

RM		= rm -rf

SRC		=	graph_sfml.cpp \

##CXXFLAGS	=	-Wall
##CXXFLAGS	+=	-Werror
##CXXFLAGS	+=	-Wextra
##CXXFLAGS	+=	-I./include
CXXFLAGS	+=	-std=c++11


LDXXFLAGS	+=	-lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

all:			$(NAME)

$(NAME):
			$(CC) $(CXXFLAGS) $(SRC) $(LDXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
