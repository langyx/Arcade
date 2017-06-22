//
// IGfx.hpp for igfc in /home/yannis/tek2/rendu/cpp_arcade/interfaces
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Wed Mar 15 03:01:23 2017 yannis
// Last update Tue Apr  4 20:37:36 2017 Yannis
//

#ifndef IGFX_HPP_
#define IGFX_HPP_

#include <string>

class IGfx
{
public:
  enum MColor
    {
    red,
    green,
    blue
    };
  
  virtual ~IGfx() {}
 
  virtual void createWindows() = 0;
  virtual void clearWindows() = 0;
  virtual void clearWindows2() = 0;
  virtual void displayWindows() = 0;
  virtual void destroyWindows() = 0;
  
  virtual char getEvent() = 0;
  virtual char getEventNoBlock(unsigned int duration) = 0;
  
  virtual void createWall(int x, int y, unsigned int height, unsigned int width) = 0;
  virtual void setMext(int x, int y, const std::string &txt) = 0;
  virtual void setMextNoRefresh(int x, int y, const std::string &txt) = 0;
  virtual void setTexture(int x, int y, unsigned int height, unsigned int width , const std::string &file) = 0;
  //  virtual void playSound(bool loop, const std::string &sound) = 0;
};

#endif
