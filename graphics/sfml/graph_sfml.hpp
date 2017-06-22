//
// graph_sfml.hpp for graph_sfml.hpp in /home/remy/rendu/cpp_arcade/graphics/sfml
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Wed Mar 15 03:08:32 2017 Rémy
// Last update Fri Apr  7 17:08:38 2017 Rémy
//

#include "../../interfaces/IGfx.hpp" 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <SFML/Audio.hpp>

#ifndef GRAPH_SFML_HPP_
#define GRAPH_SFML_HPP_

class sfml : public IGfx
{
public:
  sfml();
  virtual ~sfml();
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
  //  virtual void playSound(bool loop, const std::string &sound);

private:
  sf::RenderWindow win;
  sf::Texture _wall_texture;
  sf::Texture _floor_texture;
  sf::Texture _apple_texture;
  sf::Texture _snake_texture;
  sf::Texture _pacman_texture;
  sf::Texture _ghost_texture;
  sf::Texture _dfloor_texture;
  sf::Texture _dPoint_floor_texture;
  sf::Texture _bwall_texture;
  sf::Texture _powerup_texture;
  sf::Texture _background_texture;
  sf::Texture _snake_head_texture;
  //  sf::SoundBuffer _Pacman_music;
  //sf::SoundBuffer _Snake_music;
  
  
};

#endif
