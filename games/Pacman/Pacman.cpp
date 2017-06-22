//
// Pacman.cpp for Pacman.cpp in /home/remy/rendu/cpp_arcade/games/Pacman
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Tue Mar 28 16:02:37 2017 Rémy
// Last update Fri Apr 14 14:15:20 2017 Yannis
//

#include "Pacman.hh"

Pacman::Pacman()
{
  this->_map = new Map("./ressources/map/map.txt");
  this->_character = new Character(10, 11, 1);
  this->_character->setCommand(arcade::CommandType::GO_RIGHT);
  _title = "Pacman";
  this->_score = new Score(_title);
  _die = false;
  _etat = false;
  _speed = 1;
  _map->loadmap();
  _oldCase = 2;
  _nbGhost = 4;
  _powerTime = 100;
  _powerTimeReaming = 0;
  _time = 1;
}

Pacman::~Pacman()
{
  if (this->_map != NULL)
    delete this->_map;
  if (this->_character != NULL)
    delete this->_character;
  if (this->_score != NULL)
    delete this->_score;
}

int	Pacman::getTime() const
{
  return (-1);
}

void	Pacman::PlayTimer()
{
  _timerOn = true;
  while (_timerOn)
    {
      _time += 1;
      sleep(1);
    }
}

const std::string Pacman::getName() const
{
  return _title;
}

unsigned int Pacman::getSpeed() const
{
  return _speed;
}

bool Pacman::isAlive() const
{
  return _die;
}

bool Pacman::isWin() const
{
  return true;
}

void Pacman::goUp()
{
  _character->setCommand(arcade::CommandType::GO_UP);
  return ;
}

void Pacman::goDown()
{
  _character->setCommand(arcade::CommandType::GO_DOWN);
  return ;
}

void Pacman::goLeft()
{
  _character->setCommand(arcade::CommandType::GO_LEFT);
  return ;
}

void Pacman::goRight()
{
  _character->setCommand(arcade::CommandType::GO_RIGHT);
  return ;
}

bool Pacman::checkingPos(int x, int y)
{
  if (x >= _map->getWidth() || x < 0
      || y >= _map->getHeight() || y < 0)
    return (false);
  if (_map->getMap()[y][x] == (int) arcade::TileType::BLOCK)
    return(false);
  else if (_map->getMap()[y][x] == (int) arcade::TileType::EVIL_DUDE)
    {
      if (_etat == false)
	{
	  _die = true;
	  return (false);
	}
      else
	{
	  for (int i = 0; i < (int)_ghosts.size(); i += 1)
	    {
	      t_pos tmp = _ghosts[i]->getPos();
	      if (tmp.x == x && tmp.y == y)
		{
		  _ghosts.erase(_ghosts.begin() + i);
		  _map->setMap(tmp.x, tmp.y, (arcade::TileType) _ghosts[i]->getOld());
		  _score->setCurrent(_score->getCurrent() + 142);
		  break;
		}
	    }
	  return true;
	}
    }
  else if (_map->getMap()[y][x] == (int) arcade::TileType::POWERUP)
    {
      _map->setMap(x, y, (arcade::TileType) 2);
      _etat = true;
      _powerTimeReaming = 0;
      return true;
    }
  else
    return(true);
}

void Pacman::showMap() const
{
  _map->Show();
}


Score *Pacman::getScore() const
{
  return _score;
}

void Pacman::checkEndRound()
{
  int countFood = 0;
  
  for (int y = 0; y < _map->getHeight(); y += 1)
    {
      for (int x = 0;  x < _map->getWidth(); x += 1)
	{
          if (_map->getMap()[y][x] == 0)
	    countFood += 1;
        }
    }
  if (countFood == 0)
    {
      _nbGhost += 1;
      _ghosts.clear();
      _map->loadmap();
    }
  return;
}

void Pacman::loop_moving()
{
  _powerTimeReaming += 1;
  if (_powerTimeReaming == _powerTime)
    {
      _etat = false;
      _powerTimeReaming = 0;
    }
  this->GhostMoving();
  if (_die)
    {
      _timerOn = false;
      return;
    }
  t_pos new_pos;
  arcade::Position currentPos;
  
  currentPos = _character->getPos();
  new_pos.x = currentPos.x;
  new_pos.y = currentPos.y;
  switch (_character->getCommand())
    {
    case arcade::CommandType::GO_UP :
      if (this->checkingPos(new_pos.x, new_pos.y - 1) != false)
	new_pos.y -= 1;
      break;
    case arcade::CommandType::GO_DOWN :
      if (this->checkingPos(new_pos.x, new_pos.y + 1) != false)
	new_pos.y += 1;
      break;
    case arcade::CommandType::GO_LEFT :
      if (this->checkingPos(new_pos.x - 1, new_pos.y) != false)
	new_pos.x -= 1;
      break;
    case arcade::CommandType::GO_RIGHT :
      if (this->checkingPos(new_pos.x + 1, new_pos.y) != false)
	new_pos.x += 1;
      break;
    default:
      break;
    }
  this->_character->setPos(new_pos.x, new_pos.y);
  _map->setMap(currentPos.x, currentPos.y, (arcade::TileType) _oldCase);
  _oldCase = _map->getMap()[new_pos.y][new_pos.x];
  if (_oldCase == 0)
    {
      _score->setCurrent(_score->getCurrent() + 42);
      _oldCase = 2;
    }
  _map->setMap(new_pos.x, new_pos.y, arcade::TileType::OTHER);
  this->checkEndRound();
   usleep(90000);
}

void	Pacman::GhostMoving()
{
  int	__NbGhostSpawned = _ghosts.size();

  for (int i = 0; i < __NbGhostSpawned; i += 1)
    if (_ghosts[i]->lifeCycle(_map, _etat, _ghosts))
      _die = true;
  if (_nbGhost != __NbGhostSpawned && _map->getMap()[8][9] == (int) arcade::TileType::BLOCK
      && _map->getMap()[7][9] != (int) arcade::TileType::EVIL_DUDE
      && _map->getMap()[7][11] != (int) arcade::TileType::EVIL_DUDE
      && _map->getMap()[7][10] != (int) arcade::TileType::EVIL_DUDE)
      //&& _time % 7 == 0)
    {
      _ghosts.push_back(new Ghost());
      _ghosts[_ghosts.size() - 1]->spawn(_map);
    }
}

Map *Pacman::getMap() const
{
  return _map;
}

Character *Pacman::getCharacter() const
{
  return _character;
}

extern "C" Pacman *create()
{
  return (new Pacman());
}
