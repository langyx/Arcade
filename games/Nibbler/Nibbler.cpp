//
// Nibbler.cpp for  in /home/manu/TEK2/cpp_arcade/games/Nibbler
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Thu Apr  6 18:54:15 2017 Manu
// Last update Fri Apr 14 15:01:16 2017 Yannis
//

#include "Nibbler.hh"
#include "stdio.h"

Nibbler::Nibbler()
{
  t_pos f_pos;
  f_pos.x = 10;
  f_pos.y = 19;

  this->_map = new Map("./ressources/map/map_nibbler.txt");
  this->_map2 = new Map("./ressources/map/map_nibbler.txt");
  this->_map3 = new Map("./ressources/map/map_nibblerlvl2.txt");
  this->_character = new Character(10, 11, 4);
  this->_character->setCommand(arcade::CommandType::GO_RIGHT);
  _title = "Nibbler";
  this->_score = new Score(_title);
  _die = false;
  _speed = 100;
  _count = true;
  _map->loadmap();
  _map2->loadmap();
  _map3->loadmap();
  this->_map->setMap(f_pos.x, f_pos.y, arcade::TileType::OTHER);
  for (int z = 0; z <= 20; z += 1)
    this->spawn_food();
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  this->initScore();
  _time = 100;
  //_timer = new std::thread(&Nibbler::PlayTimer, this);
}

void	Nibbler::initScore()
{
  _score = new Score(_title);
}

bool	Nibbler::check_food()
{
  int count = 0;
  for (int y = 0; y < _map->getHeight(); y += 1)
    {
      for (int x = 0; x < _map->getWidth(); x += 1)
	{
	  if (_map->getMap()[y][x] == (int) arcade::TileType::POWERUP)
	    {
	      count += 1;
	    }
	}
    }
  if (count <= 1)
    return false;
  else
    return (true);
}

void    Nibbler::spawn_food()
{
  int x = 0;
  int y = 0;

  while (_map->getMap()[y][x] != 0)
    {
      x = rand() % _map->getWidth();
      y = rand() % _map->getHeight();
    }
  _map->setMap(x, y, arcade::TileType::POWERUP);
}

Nibbler::~Nibbler()
{
  if (this->_map != NULL)
    delete this->_map;
  if (this->_map2 != NULL)
    delete this->_map2;
  if (this->_map3 != NULL)
    delete this->_map3;
  if (this->_character != NULL)
    delete this->_character;
  if (this->_score != NULL)
    delete this->_score;
  
}

void	Nibbler::PlayTimer()
{
  _timerOn = true;
  while (_timerOn)
    {
      if (_time <= 0)
	_die = true;
      _time -= 1;
      sleep(1);
    }
}

int	Nibbler::getTime() const
{
  return (-1);
}

const std::string Nibbler::getName() const
{
  return _title;
}

unsigned int Nibbler::getSpeed() const
{
  return _speed;
}

bool Nibbler::isAlive() const
{
  return _die;
}

bool Nibbler::isWin() const
{
  return true;
}

void Nibbler::goUp()
{
  _character->setCommand(arcade::CommandType::GO_UP);
  return ;
}

void Nibbler::goDown()
{
  _character->setCommand(arcade::CommandType::GO_DOWN);
  return ;
}

void Nibbler::goLeft()
{
  _character->setCommand(arcade::CommandType::GO_LEFT);
  return ;
}

void Nibbler::goRight()
{
  _character->setCommand(arcade::CommandType::GO_RIGHT);
  return ;
}

bool    Nibbler::checkingPos(int x, int y)
{
  if (x >= _map->getWidth() || x < 0
      || y >= _map->getHeight() || y < 0)
    {
      _die = true;
      return (false);
    }
  if (_map->getMap()[y][x] == (int) arcade::TileType::OTHER)
    {
      _die = true;
      return (false);
    }
  else if (_map->getMap()[y][x] == (int) arcade::TileType::BLOCK)
    {
      if ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 0 && y == 19) ||
	  (x == 1 && y == 20) || (x == 19 && y == 0) || (x == 20 && y == 1) ||
	  (x == 19 && y == 20) || (x == 20 && y == 19))
	return (true);
      else
	return false;
    }
  else
    {
      if (_map->getMap()[y][x] == (int) arcade::TileType::POWERUP)
        {
	  _score->setCurrent(_score->getCurrent() + 10);
          _character->setLenght(_character->getLenght() + 1);
	  if (this->check_food() == false)
	    {
	      if (_count == true)
		{
		  _time = 100;
		  _map = _map3;
		  _character->setLenght(3);
		  for (int z = 0; z != 20; z += 1)
		    this->spawn_food();
		  _count = false;
		}
	      else
	        {
		  _time = 100;
		  _map = _map2;
        	  _character->setLenght(3);
		  for (int z = 0; z != 20; z += 1)
		    this->spawn_food();
		  _count = true;
		}
	    }
        }
      return (true);
    }
}

void Nibbler::showMap() const
{
  _map->Show();
}

Score *Nibbler::getScore() const
{
  return _score;
}

void    Nibbler::ClearMapPlayer()
{
  for (int y = 0; y < _map->getHeight(); y += 1)
    {
      for (int x = 0; x < _map->getWidth(); x += 1)
        {
	  if (_map->getMap()[y][x] == (int) arcade::TileType::OTHER)
	    _map->setMap(x, y, arcade::TileType::EMPTY);
        }
    }
}

void	Nibbler::check_direction(t_pos *new_pos)
{
  if (new_pos->x == 1 && new_pos->y == 0 && _character->getCommand() == arcade::CommandType::GO_UP)
    {
      new_pos->x += 1;
      new_pos->y += 1;
      _character->setCommand(arcade::CommandType::GO_RIGHT);
    }
  else if (new_pos->x == 0 && new_pos->y == 1 && _character->getCommand() == arcade::CommandType::GO_LEFT)
    {
      new_pos->x += 1;
      new_pos->y += 1;
      _character->setCommand(arcade::CommandType::GO_DOWN);
    }
  else if (new_pos->x == 1 && new_pos->y == 20 && _character->getCommand() == arcade::CommandType::GO_DOWN)
    {
      new_pos->x += 1;
      new_pos->y -= 1;
      _character->setCommand(arcade::CommandType::GO_RIGHT);
    }
  else if (new_pos->x == 0 && new_pos->y == 19 && _character->getCommand() == arcade::CommandType::GO_LEFT)
    {
      new_pos->x += 1;
      new_pos->y -= 1;
      _character->setCommand(arcade::CommandType::GO_UP);
    }
  else if (new_pos->x == 19 && new_pos->y == 0 && _character->getCommand() == arcade::CommandType::GO_UP)
    {
      new_pos->x -= 1;
      new_pos->y += 1;
      _character->setCommand(arcade::CommandType::GO_LEFT);
    }
  else if (new_pos->x == 20 && new_pos->y == 1 && _character->getCommand() == arcade::CommandType::GO_RIGHT)
    {
      new_pos->x -= 1;
      new_pos->y += 1;
      _character->setCommand(arcade::CommandType::GO_DOWN);
    }
  else if (new_pos->x == 19 && new_pos->y == 20 && _character->getCommand() == arcade::CommandType::GO_DOWN)
    {
      new_pos->x -= 1;
      new_pos->y -= 1;
      _character->setCommand(arcade::CommandType::GO_LEFT);
    }
  else if (new_pos->x == 20 && new_pos->y == 19 && _character->getCommand() == arcade::CommandType::GO_RIGHT)
    {
      new_pos->x -= 1;
      new_pos->y -= 1;
      _character->setCommand(arcade::CommandType::GO_UP);
    }
}

void    Nibbler::loop_moving()
{
  t_pos new_pos;
  int   ht_size = this->h_tail.size() - 1;

  if (ht_size < 0)
    ht_size += 1;
  new_pos = h_tail[ht_size];

  switch (_character->getCommand())
    {
    case arcade::CommandType::GO_UP :
      if (this->checkingPos(h_tail[ht_size].x, h_tail[ht_size].y - 1))
        new_pos.y -= 1;
      break;
    case arcade::CommandType::GO_DOWN :
      if (this->checkingPos(h_tail[ht_size].x, h_tail[ht_size].y + 1))
        new_pos.y += 1;
      break;
    case arcade::CommandType::GO_LEFT :
      if (this->checkingPos(h_tail[ht_size].x - 1, h_tail[ht_size].y))
        new_pos.x -= 1;
      break;
    case arcade::CommandType::GO_RIGHT :
      if (this->checkingPos(h_tail[ht_size].x + 1, h_tail[ht_size].y))
        new_pos.x += 1;
      break;
    default:
      break;
    }
  check_direction(&new_pos);
  if (new_pos.x != h_tail[ht_size].x || new_pos.y != h_tail[ht_size].y)
    {
      h_tail.push_back(new_pos);
      int j = h_tail.size() - 1;
      this->ClearMapPlayer();
      for (int i = 0; i < _character->getLenght() ; i += 1)
	{
	  if (i == 0)
	    _map->setMap(h_tail[j].x, h_tail[j].y, arcade::TileType::MY_SHOOT);
	  else
	    _map->setMap(h_tail[j].x, h_tail[j].y, arcade::TileType::OTHER);
	  j -= 1;
	}
    }
  if (_die)
    {
      _timerOn = false;
      //      _timer->join();
      //delete _timer;
    }
}

Map *Nibbler::getMap() const
{
  return _map;
}

Character *Nibbler::getCharacter() const
{
  return _character;
}

extern "C" Nibbler *create()
{
  return (new Nibbler());
}
