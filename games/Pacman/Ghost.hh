//
// Ghost.hh for  in /home/yannis/tek2/rendu/cpp_arcade/games/Pacman
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Mon Apr  3 00:09:13 2017 yannis
// Last update Mon Apr  3 17:36:17 2017 yannis
//

#ifndef GHOST_HH_
#define GHOST_HH_

#include <string>
#include <vector>
#include <stdlib.h>
#include "../../Protocol.hpp"
#include "../../map/Map.hh"

typedef struct s_pos
{
  int x;
  int y;

}       t_pos;

class	Ghost
{
public:
  Ghost();
  ~Ghost();

  void	spawn(Map *map) const;
  bool	lifeCycle(Map *_map, int __state, std::vector<Ghost *> &__ghosts);
  t_pos	getPos() const;
  int	getOld() const;
  
private:
  t_pos	_pos;
  int	_old;
};

#endif
