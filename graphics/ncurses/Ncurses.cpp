//
// Ncurses.cpp for  in /home/manu/TEK2/cpp_arcade/graphics/ncurses
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Wed Mar 15 02:58:18 2017 Manu
// Last update Sun Apr  9 20:29:47 2017 Manu
// Last update Sat Mar 25 02:37:06 2017 yannis
//

#include "Ncurses.hpp"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void Ncurses::destroyWindows()
{
  refresh();
  endwin();
  if (isendwin() == TRUE)
    printf("Terminal delete correctly in destroyer funct\n");
  return ;
}

void Ncurses::createWindows()
{
  initscr();
  if (!has_colors())
    printw("Can't use color\n");
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_RED, COLOR_RED);
  init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(7, COLOR_GREEN, COLOR_GREEN);
  init_pair(8, COLOR_WHITE, COLOR_WHITE);
  init_pair(9, COLOR_BLACK, COLOR_BLACK);
  curs_set(0);
  noecho();
  return ;
}

void Ncurses::clearWindows()
{
  int x = 0;
  int y = 0;
  int height = 0;
  int width = 0;

  getmaxyx(stdscr, height, width);
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  if (((mvinch(y, x)&A_COLOR &A_CHARTEXT) != '#') && ((mvinch(y, x)&A_COLOR &A_CHARTEXT) != ' ') && ((mvinch(y, x)&A_COLOR &A_CHARTEXT) != '*') &&
              ((mvinch(y, x)&A_COLOR &A_CHARTEXT) != 'x') && ((mvinch(y, x)&A_COLOR &A_CHARTEXT) != 'Z') && ((mvinch(y, x)&A_COLOR &A_CHARTEXT) != 'o') && (mvinch(y, x)&A_COLOR &A_CHARTEXT != 'w'))
	    mvaddch(y, x, ' ');
	  x += 1;
	}
      y += 1;
    }
}

void Ncurses::clearWindows2()
{
  int x = 0;
  int y = 0;
  int height = 0;
  int width = 0;

  getmaxyx(stdscr, height, width);
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  mvaddch(y, x, ' ');
	  x += 1;
	}
      y += 1;
    }
}

void Ncurses::displayWindows()
{
  refresh();
}

char Ncurses::getEvent()
{
  int key;

  keypad(stdscr, true);
  key = getch();
  switch (key)
    {
    case KEY_UP : 
    case 'u' :
      return 'u';
    case KEY_DOWN :
    case 'd' :
      return 'd';
    case KEY_LEFT :
    case 'l':
      return 'l';
    case KEY_RIGHT :
    case 'r' :
      return 'r';
    case 27 :
    case 'q' :
      return 'q';
    case 48 :
      return '0';
    case 49 :
      return '1';
    case 50 :
      return '2';
    case 51 :
      return '3';
    case 52 :
      return '4';
    case 53 :
      return '5';
    case 54 :
      return '6';
    case 55 :
      return '7';
    case 56 :
      return '8';
    case 57 :
      return '9';
    case 10 :
    case 'e' :
      return 'e';
    case 97 :
      return 'a';
    case 98 :
      return 'b';
    case 99 :
      return 'c';
    case 102 :
      return 'f';
    case 103 :
      return 'g';
    case 104 :
      return 'h';
    case 105 :
      return 'i';
    case 106 :
      return 'j';
    case 107 :
      return 'k';
    case 109 :
      return 'm';
    case 110 :
      return 'n';
    case 111 :
      return 'o';
    case 112 :
      return 'p';
    case 115 :
      return 's';
    case 116 :
      return 't';
    case 118 :
      return 'v';
    case 119 :
      return 'w';
    case 120 :
      return 'x';
    case 121 :
      return 'y';
    case 122 :
      return 'z';
    case 46 :
      return '.';
    }
  return ' ';
}

char Ncurses::getEventNoBlock(unsigned int duration)
{
  int key;

  keypad(stdscr, true);
  timeout((int)duration + 5);
  key = getch();
    switch (key)
    {
    case KEY_UP : 
    case 'u' :
      return 'u';
    case KEY_DOWN :
    case 'd' :
      return 'd';
    case KEY_LEFT :
    case 'l':
      return 'l';
    case KEY_RIGHT :
    case 'r' :
      return 'r';
    case 27 :
    case 'q' :
      return 'q';
    case 48 :
      return '0';
    case 49 :
      return '1';
    case 50 :
      return '2';
    case 51 :
      return '3';
    case 52 :
      return '4';
    case 53 :
      return '5';
    case 54 :
      return '6';
    case 55 :
      return '7';
    case 56 :
      return '8';
    case 57 :
      return '9';
    case 10 :
    case 'e' :
      return 'e';
    case 97 :
      return 'a';
    case 98 :
      return 'b';
    case 99 :
      return 'c';
    case 102 :
      return 'f';
    case 103 :
      return 'g';
    case 104 :
      return 'h';
    case 105 :
      return 'i';
    case 106 :
      return 'j';
    case 107 :
      return 'k';
    case 109 :
      return 'm';
    case 110 :
      return 'n';
    case 111 :
      return 'o';
    case 112 :
      return 'p';
    case 115 :
      return 's';
    case 116 :
      return 't';
    case 118 :
      return 'v';
    case 119 :
      return 'w';
    case 120 :
      return 'x';
    case 121 :
      return 'y';
    case 122 :
      return 'z';
    case 46 :
      return '.';
    }
    return ' ';
}

void Ncurses::createWall(int x, int y, unsigned int height, 
			 __attribute__((unused)) unsigned int width)
{
  attron(COLOR_PAIR(1));
  mvprintw(y / height, x / height, "x");
  attroff(COLOR_PAIR(1));
}

void Ncurses::setMextNoRefresh(int x, int y, const std::string &txt)
{
  this->setMext(x, y, txt);
  return;
}

void Ncurses::setMext(int x, int y, const std::string &txt)
{
  int maxy, maxx;
  int resy, resx;

  getmaxyx(stdscr, maxy, maxx);
  resy = (800 / maxy);
  resx = (800 / maxx);
  if (txt != " " && txt != "*" && txt != "#" && txt != "x" && txt != "Z" &&
      txt != "o" && txt != "<" && txt != "w")
    mvprintw((y / resy), (x / resx), txt.c_str());
  else
    {
      if (txt == "#")
	{
	  attron(COLOR_PAIR(2));
	  mvprintw(y, x, txt.c_str());
	  attroff(COLOR_PAIR(2));
	}
      else if (txt == "Z" || txt == "w")
	{
	  attron(COLOR_PAIR(6));
	  mvprintw(y, x, txt.c_str());
	  attroff(COLOR_PAIR(6));
	  }
      else if (txt == "o" || txt == "<")
	{
	  attron(COLOR_PAIR(7));
	  mvprintw(y, x, txt.c_str());
	  attroff(COLOR_PAIR(7));
	}
      else if (txt == "x")
	{
	  attron(COLOR_PAIR(1));
	  mvprintw(y, x, txt.c_str());
	  attroff(COLOR_PAIR(1));
	}
      else if (txt == "*")
	{
	  attron(COLOR_PAIR(9));
	  mvprintw(y, x, txt.c_str());
	  attroff(COLOR_PAIR(9));
	}
      else
	{
	  attron(COLOR_PAIR(8));
	  mvprintw(y, x, txt.c_str());
	  attron(COLOR_PAIR(8));
	}
    }
}

void Ncurses::setTexture(int x, int y, unsigned int height, __attribute__((unused)) unsigned int width , const std::string &file)
{
  std::string file2;
  std::string texture;

  if (file == "floor")
    texture = " ";
  else if (file == "apple")
    texture = "<";
  else if (file == "snake")
    texture = "#";
  else if (file == "pacman")
    texture = "Z";
  else if (file == "ghost")
    texture = "#";
  else if (file == "dfloor")
    texture = " ";
  else if (file == "dPoint_floor")
    texture = "*";
  else if (file == "bwall")
    texture = "x";
  else if (file == "powerup")
    texture = "o";
  else if (file == "snake_head")
    texture = "w";
  setMext(x / height, y / height, texture);
}

extern "C" IGfx *create()
{
  return (new Ncurses());
}
