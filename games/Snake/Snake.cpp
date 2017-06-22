//
// Snake.cpp for  in /home/manu/TEK2/cpp_arcade/games/snake
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Mon Mar 27 17:56:08 2017 Manu
// Last update Sun Apr  9 23:05:09 2017 Yannis
//

#include "Snake.hh"

Snake::Snake()
{
  _title =  "Snake";
  _die = false;
  _speed = 110;

  this->_map = new Map(20, 20, _title);
  this->_character = new Character(198, 200, 4);
  this->_character->setCommand(arcade::CommandType::GO_RIGHT);
 
  t_pos f_pos;
  f_pos.x = 10;
  f_pos.y = 10;
  this->_map->setMap(f_pos.x, f_pos.y, arcade::TileType::OTHER);
  
  this->spawn_food();
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  f_pos.x += 1;
  h_tail.push_back(f_pos);
  this->initScore();
}

Snake::~Snake()
{
  if (this->_map != NULL)
    delete this->_map;
  if (this->_character != NULL)
    delete this->_character;
}

void	Snake::initScore()
{
  _score = new Score(_title);
}

const std::string Snake::getName() const
{
  return _title;
}

unsigned int Snake::getSpeed() const
{
  return _speed;
}

int	Snake::getTime() const
{
  return (-1);
}

void	Snake::spawn_food()
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

bool Snake::isAlive() const
{
  return _die;
}

bool Snake::isWin() const
{
  return true;
}

Score	*Snake::getScore() const
{
  return _score;
}

void Snake::goUp()
{
  _character->setCommand(arcade::CommandType::GO_UP);
  return ;
}

void Snake::goDown()
{
  _character->setCommand(arcade::CommandType::GO_DOWN);
  return ;
}

void Snake::goLeft()
{
  _character->setCommand(arcade::CommandType::GO_LEFT);
  return ;
}

void Snake::goRight()
{
  _character->setCommand(arcade::CommandType::GO_RIGHT);
  return ;
}

bool	Snake::checkingPos(int x, int y)
{
  if (x >= _map->getWidth() || x < 0
      || y >= _map->getHeight() || y < 0)
    {
      _die = true;
      return (false);
    }
  if (_map->getMap()[y][x] == (int) arcade::TileType::BLOCK
      || _map->getMap()[y][x] == (int) arcade::TileType::OTHER)
    {
      _die = true;
      return (false);
    }
  else
    {
      if (_map->getMap()[y][x] == (int) arcade::TileType::POWERUP)
	{
	  _character->setLenght(_character->getLenght() + 1);
	  _score->setCurrent(_score->getCurrent() + 10);
	  _speed -= 2;
	  this->spawn_food();
	}
      return (true);
    }
}

void	Snake::ClearMapPlayer()
{
  for (int y = 0; y < _map->getHeight(); y += 1)
    {
      for (int x = 0; x < _map->getWidth(); x += 1)
	{
	  if (_map->getMap()[y][x] == (int) arcade::TileType::OTHER || 
	      _map->getMap()[y][x] == (int) arcade::TileType::MY_SHOOT)
	    _map->setMap(x, y, arcade::TileType::EMPTY);
	}
    }
}

void	Snake::loop_moving()
{
  t_pos	new_pos;
  int	ht_size = this->h_tail.size() - 1;


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

void	Snake::showMap() const
{
  _map->Show();
}

Map	*Snake::getMap() const
{
  return _map;
}

Character	*Snake::getCharacter() const
{
  return _character;
}

extern "C" IGame *create()
{
  return (new Snake());
}
