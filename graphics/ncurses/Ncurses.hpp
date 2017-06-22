//
// Ncurses.hpp for  in /home/manu/TEK2/cpp_arcade/graphics/ncurses
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Wed Mar 15 02:58:27 2017 Manu
// Last update Tue Apr  4 22:23:36 2017 Manu
//

#ifndef NCURSES_HPP_
# define NCURSES_HPP_

#include "../../interfaces/IGfx.hpp"
#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

class Ncurses : public IGfx
{
public:
  Ncurses();
  virtual ~Ncurses();
  virtual void createWindows();
  virtual void clearWindows();
  virtual void clearWindows2();
  virtual void displayWindows();
  virtual void destroyWindows();

  virtual char getEvent();
  virtual char getEventNoBlock(unsigned int duration);

  virtual void createWall(int x, int y, unsigned int height, unsigned int width);
  virtual void setMext(int x, int y, const std::string &txt);
  virtual void setMextNoRefresh(int x, int y, const std::string &txt);
  virtual void setTexture(int x, int y, unsigned int height, unsigned int width , const std::string &file);
private:
  WINDOW *_neww;
};

#endif
