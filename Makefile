##
## Makefile for arcade in /home/yannis/tek2/rendu/cpp_arcade/core
## 
## Made by yannis
## Login   <yannis.lang@epitech.eu>
## 
## Started on  Thu Mar 16 14:06:37 2017 yannis
## Last update Sun Apr  9 20:29:02 2017 Manu
##

SRC	=  ./core/GameCore.cpp \
	   ./map/Map.cpp \
	   main.cpp     \
	   ./score/Score.cpp \
	   ./server/server/server.cpp \
	   ./server/client/client.cpp

NAME	= arcade

CXXFLAGS  =  -std=c++11 -W -Wall -Wextra #-Werror 

LDXXFLAGS = -lpthread -ldl -lm -Wl,-rpath=./graphics

CC	= g++ -g3

OBJ	= $(SRC:.cpp=.o)

all: $(NAME) subdir

subdir:
	$(MAKE) re -C ./graphics/opengl
	$(MAKE) re -C ./graphics/ncurses
	$(MAKE) re -C ./graphics/sfml
	$(MAKE) re -C ./games/Snake
	$(MAKE) re -C ./games/Pacman
	$(MAKE) re -C ./games/Nibbler

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./graphics/opengl
	$(MAKE) fclean -C ./graphics/ncurses
	$(MAKE) fclean -C ./graphics/sfml
	$(MAKE) fclean -C ./games/Snake
	$(MAKE) fclean -C ./games/Pacman
	$(MAKE) fclean -C ./games/Nibbler

re: fclean all
