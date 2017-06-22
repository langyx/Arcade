//
// Ghost.cpp for  in /home/yannis/tek2/rendu/cpp_arcade/games/Pacman
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Mon Apr  3 00:14:50 2017 yannis
// Last update Sun Apr  9 20:47:21 2017 Manu
//

#include "Ghost.hh"

Ghost::Ghost()
{
  _pos.x = 10;
  _pos.y = 8;
  _old = -1;
}

Ghost::~Ghost()
{
}

void	Ghost::spawn(Map *_map) const
{
  _map->setMap(_pos.x, _pos.y, arcade::TileType::EVIL_DUDE);
}

bool	Ghost::lifeCycle(Map *_map, int __state, std::vector<Ghost *> &__ghosts)
{
  int	__dir;
  t_pos	__new_pos = _pos;

  if (_old == -1)
    _old = 1;
  while ((__new_pos.x == _pos.x && __new_pos.y == _pos.y)
	 || _map->getMap()[__new_pos.y][__new_pos.x] == (int) arcade::TileType::BLOCK
	 || _map->getMap()[__new_pos.y][__new_pos.x] == (int) arcade::TileType::EVIL_DUDE)
    {
      __new_pos.x = _pos.x;
      __new_pos.y = _pos.y;
      __dir = rand() % 4;
      switch (__dir)
	{
	case 3:
	  __new_pos.x += 1;
      break;
	case 2:
	  __new_pos.x -= 1;
	  break;
	case 1:
	  __new_pos.y += 1;
	  break;
	default:
	  __new_pos.y -= 1;
	  break;
	}
    }
  if (_map->getMap()[__new_pos.y][__new_pos.x] == (int) arcade::TileType::OTHER )
    {
      if (__state)
	{
	  for (int i = 0; i < (int)__ghosts.size(); i += 1)
	    {
	      t_pos tmp = __ghosts[i]->getPos();
	      if (tmp.x == __new_pos.x && __new_pos.y == tmp.y)
		{
		  __ghosts.erase(__ghosts.begin() + i);
		  _map->setMap(tmp.x, tmp.y, (arcade::TileType) __ghosts[i]->getOld());
		  break;
		}
	    }
	  return (false);
	}
      else
	return (true);
    }
  else
    {
      _map->setMap(_pos.x, _pos.y, (arcade::TileType) _old);
      _pos.x = __new_pos.x;
      _pos.y = __new_pos.y;
      _old = _map->getMap()[__new_pos.y][__new_pos.x];
      _map->setMap(__new_pos.x, __new_pos.y, arcade::TileType::EVIL_DUDE);
      return (false);
    }
}

t_pos	Ghost::getPos() const
{
  return _pos;
}

int	Ghost::getOld() const
{
  return _old;
}
