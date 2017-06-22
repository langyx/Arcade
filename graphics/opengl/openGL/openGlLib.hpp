//
// openGlLib.hpp for openGLL in /home/yannis/tek2/rendu/cpp_arcade/graphics/opengl
//
// Made by yannis
// Login   <yannis.lang@epitech.eu>
//
// Started on  Wed Mar 15 03:09:46 2017 yannis
// Last update Thu Apr  6 22:37:28 2017 Rémy
//

#ifndef OPENGLLIB_HPP_
# define OPENGLLIB_HPP_

# include <iostream>

#include "./openGL/SDL.h"
#include "./openGL/SDL_ttf.h"
#include "./openGL/glew.h"
#include "./openGL/SDL_surface.h"
#include "./openGL/SDL_image.h"
#include "./IGfx.hpp"

class OpenGlLib : public IGfx
{
private:
  SDL_Window *_win;
  SDL_GLContext _context;
  SDL_Renderer *_renderer;
  SDL_Texture  *_wall_texture;
  SDL_Texture  *_floor_texture;
  SDL_Texture  *_apple_texture;
  SDL_Texture  *_snake_texture;
  
  TTF_Font	*Sans;

  std::string  _font = "./ressources/font/regular.ttf";
  
  
public:
  OpenGlLib();
  virtual ~OpenGlLib();

  virtual void createWindows();
  virtual void clearWindows();
  virtual void displayWindows();

  virtual char getEvent();
  //  virtual char getEventNoBlock(unsigned int duration);
  
  virtual void createWall(int x, int y, unsigned int height, unsigned int width);
  virtual void setMext(int x, int y, const std::string &txt);
  virtual void setTexture(int x, int y, unsigned int height, unsigned int width , const std::string &file);
};

#endif
