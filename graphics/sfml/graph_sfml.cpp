//
// snake_smfl.cpp for snake_sfml.cpp in /home/remy/rendu/cpp_arcade/graphics/sfml
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Wed Mar 15 02:55:38 2017 Rémy
// Last update Sun Apr  9 20:46:47 2017 Manu
// Last update Mon Apr  3 17:25:09 2017 yannis
//

#include "graph_sfml.hpp"

sfml::sfml()
{
}

sfml::~sfml()
{

}

void sfml::destroyWindows()
{
  this->win.close();
}

void sfml::createWindows()
{
  this->win.create(sf::VideoMode(800, 800), "Arcade");
  this->win.setFramerateLimit(100);
   _floor_texture.loadFromFile("./ressources/texture/floor_sfml.png");
  _wall_texture.loadFromFile("./ressources/texture/wall_sfml.png");
  _snake_texture.loadFromFile("./ressources/texture/snake_sfml.png");
  _apple_texture.loadFromFile("./ressources/texture/apple_sfml.png");
  _pacman_texture.loadFromFile("./ressources/texture/ppacman_sfml.png");
  _ghost_texture.loadFromFile("./ressources/texture/prghost_sfml.png");
  _dfloor_texture.loadFromFile("./ressources/texture/pfloor_gl.png");
  _dPoint_floor_texture.loadFromFile("./ressources/texture/ppfloor_sfml.png");
  _bwall_texture.loadFromFile("./ressources/texture/pwall_sfml.png");
  _powerup_texture.loadFromFile("./ressources/texture/ppower_up_sfml.png");
  _background_texture.loadFromFile("./ressources/texture/background.png");
  _snake_head_texture.loadFromFile("./ressources/texture/snake_head_sfml.png");
  return;
}

void sfml::clearWindows()
{
  this->win.clear();
}

void sfml::clearWindows2()
{
  return;
}

void sfml::displayWindows()
{
  this->win.display();
}


char sfml::getEventNoBlock(unsigned int duration)
{
  usleep((int)duration * 750);
  sf::Event event;

  while (this->win.pollEvent(event))
    {
      switch (event.type)
	{
	  
	case sf::Event::Closed:
	  this->win.close();
	  break;
	  
	case sf::Event::KeyPressed :
	  switch (event.key.code)
	    {
	    case sf::Keyboard::Escape :
	    case sf::Keyboard::Q :
	      return 'q';
	      this->win.close();
	      break;
	    case sf::Keyboard::Up :
	    case sf::Keyboard::U :
	      return 'u';
	    case sf::Keyboard::Down :
	    case sf::Keyboard::D :
	      return 'd';
	    case sf::Keyboard::Left :
	    case sf::Keyboard::L :
	      return 'l';
	    case sf::Keyboard::Right :
	    case sf::Keyboard::R :
	      return 'r';
	    case sf::Keyboard::Return :
	    case sf::Keyboard::E :
	      return 'e';
	    case sf::Keyboard::Num0 :
	      return '0';
	    case sf::Keyboard::Num1 :
	      return '1';
	    case sf::Keyboard::Num2 :
	      return '2';
	    case sf::Keyboard::Num3 :
	      return '3';
	    case sf::Keyboard::Num4 :
	      return '4';
	    case sf::Keyboard::Num5 :
	      return '5';
	    case sf::Keyboard::Num6 :
	      return '6';
	    case sf::Keyboard::Num7 :
	      return '7';
	    case sf::Keyboard::Num8 :
	      return '8';
	    case sf::Keyboard::Num9 :
	      return '9';
	    case sf::Keyboard::A :
	      return 'a';
	    case sf::Keyboard::B :
	      return 'b';
	    case sf::Keyboard::C :
	      return 'c';
	    case sf::Keyboard::F :
	      return 'f';
	    case sf::Keyboard::G :
	      return 'g';
	    case sf::Keyboard::H :
	      return 'h';
	    case sf::Keyboard::I :
	      return 'i';
	    case sf::Keyboard::J :
	      return 'j';
	    case sf::Keyboard::K :
	      return 'k';
	    case sf::Keyboard::M :
	      return 'm';
	    case sf::Keyboard::N :
	      return 'n';
	    case sf::Keyboard::O :
	      return 'o';
	    case sf::Keyboard::P :
	      return 'p';
	    case sf::Keyboard::S :
	      return 's';
	    case sf::Keyboard::T :
	      return 't';
	    case sf::Keyboard::V :
	      return 'v';
	    case sf::Keyboard::W :
	      return 'w';
	    case sf::Keyboard::X :
	      return 'x';
	    case sf::Keyboard::Y :
	      return 'y';
	    case sf::Keyboard::Z :
	      return 'z';
	    case sf::Keyboard::Period :
	      return '.';
	    }
	  break;
	}
    }
  return(' ');

}

char sfml::getEvent()
{
  sf::Event event;
  
  while (this->win.pollEvent(event))
    {
      switch (event.type)
	{
	  
	case sf::Event::Closed:
	  this->win.close();
	  break;
	  
	case sf::Event::KeyPressed :

	  switch (event.key.code)
	    {
	    case sf::Keyboard::Escape :
	    case sf::Keyboard::Q :
	      return 'q';
	      this->win.close();
	      break;
	      case sf::Keyboard::Up :
	    case sf::Keyboard::U :
	      return 'u';
	    case sf::Keyboard::Down :
	    case sf::Keyboard::D :
	      return 'd';
	    case sf::Keyboard::Left :
	    case sf::Keyboard::L :
	      return 'l';
	    case sf::Keyboard::Right :
	    case sf::Keyboard::R :
	      return 'r';
	    case sf::Keyboard::Return :
	    case sf::Keyboard::E :
	      return 'e';
	    case sf::Keyboard::Num0 :
	      return '0';
	    case sf::Keyboard::Num1 :
	      return '1';
	    case sf::Keyboard::Num2 :
	      return '2';
	    case sf::Keyboard::Num3 :
	      return '3';
	    case sf::Keyboard::Num4 :
	      return '4';
	    case sf::Keyboard::Num5 :
	      return '5';
	    case sf::Keyboard::Num6 :
	      return '6';
	    case sf::Keyboard::Num7 :
	      return '7';
	    case sf::Keyboard::Num8 :
	      return '8';
	    case sf::Keyboard::Num9 :
	      return '9';
	    case sf::Keyboard::A :
	      return 'a';
	    case sf::Keyboard::B :
	      return 'b';
	    case sf::Keyboard::C :
	      return 'c';
	    case sf::Keyboard::F :
	      return 'f';
	    case sf::Keyboard::G :
	      return 'g';
	    case sf::Keyboard::H :
	      return 'h';
	    case sf::Keyboard::I :
	      return 'i';
	    case sf::Keyboard::J :
	      return 'j';
	    case sf::Keyboard::K :
	      return 'k';
	    case sf::Keyboard::M :
	      return 'm';
	    case sf::Keyboard::N :
	      return 'n';
	    case sf::Keyboard::O :
	      return 'o';
	    case sf::Keyboard::P :
	      return 'p';
	    case sf::Keyboard::S :
	      return 's';
	    case sf::Keyboard::T :
	      return 't';
	    case sf::Keyboard::V :
	      return 'v';
	    case sf::Keyboard::W :
	      return 'w';
	    case sf::Keyboard::X :
	      return 'x';
	    case sf::Keyboard::Y :
	      return 'y';
	    case sf::Keyboard::Z :
	      return 'z';
	    case sf::Keyboard::Period :
	      return '.';
	    }

	  break;
	}
    }
  return(' ');
}

void sfml::createWall(int x, int y, unsigned int height, unsigned int width)
{
  this->setTexture(x, y, height, width, "wall");
}

void sfml::setMext(int x, int y, const std::string &txt)
{
  sf::Font font;
  if (!font.loadFromFile("./ressources/font/regular.ttf"))
    {
     
    }
  sf::Text text;

  text.setFont(font);
  text.setString(txt);
  text.setCharacterSize(24);
  text.setPosition(x, y);
  this->win.draw(text);
  this->displayWindows();
}

void sfml::setTexture(int x, int y, unsigned int height, unsigned int width, const std::string &file)
{
  float _width;
  float _height;

  sf::Texture *texture;

  if (file == "floor")
    texture = &_floor_texture;
  else if (file == "apple")
    texture = &_apple_texture;
  else if (file == "snake")
    texture = &_snake_texture;
  else if (file == "wall")
    texture = &_wall_texture;
  else if (file == "pacman")
    texture = &_pacman_texture;
  else if (file == "ghost")
    texture = &_ghost_texture;
  else if (file == "dfloor")
    texture = &_dfloor_texture;
  else if (file == "dPoint_floor")
    texture = &_dPoint_floor_texture;
  else if (file == "bwall")
    texture = &_bwall_texture;
  else if (file == "powerup")
    texture = &_powerup_texture;
  else if (file == "background")
    texture = &_background_texture;
  else if (file == "snake_head")
    texture = &_snake_head_texture;
  else
    {
      texture = new sf::Texture;
      texture->loadFromFile(file);
    }

  texture->setSmooth(true);
  _width = (float)width / texture->getSize().x;
  _height = (float)height / texture->getSize().y;
  sf::Sprite sprite(*texture);
 
  sprite.setPosition(sf::Vector2f(x, y));
  sprite.setScale(sf::Vector2f(_width, _height));
  this->win.draw(sprite);
}

void sfml::setMextNoRefresh(int x, int y, const std::string &txt)
{
 sf::Font font;
  if (!font.loadFromFile("./ressources/font/regular.ttf"))
    {
     
    }
  sf::Text text;

  text.setFont(font);
  text.setString(txt);
  text.setCharacterSize(24);
  text.setPosition(x, y);
  this->win.draw(text);
}

extern "C" IGfx *create()
{
  return (new sfml());
}
