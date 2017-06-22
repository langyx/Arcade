//
// Snake.hh for  in /home/manu/TEK2/cpp_arcade/games/snake
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Mon Mar 27 17:39:37 2017 Manu
// Last update Sun Apr  9 23:02:17 2017 Yannis
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

#include "../../score/Score.hh"
#include "../../interfaces/IGame.hh"
#include "../../character/Character.hh"
#include "../../map/Map.hh"
#include "../../Protocol.hpp"
#include <unistd.h>
#include <iostream>

typedef struct	s_pos
{
  int	x;
  int	y;
}		t_pos;	

class Map;
class Character;

class Snake : public IGame
{
public:
  Snake();
  ~Snake();

  void spawn_food();
  void initScore();
  
  virtual const std::string	getName() const;
  virtual unsigned int		getSpeed() const;
  virtual bool			isAlive() const;
  virtual bool			isWin() const;
  virtual void			goUp();
  virtual void			goDown();
  virtual void			goLeft();
  virtual void			goRight();
  virtual void			loop_moving();
  bool				checkingPos(int x, int y);
  void				ClearMapPlayer(); 
  virtual void			showMap() const;
  virtual Map			*getMap() const;
  virtual Character		*getCharacter() const;
  virtual Score			*getScore() const;

  virtual int			getTime() const;
  
private:
  std::string _title;
  
  Map	*_map;
  Character *_character;
  Score	*_score;

  int	_speed;
  std::vector<t_pos>	h_tail;

  bool	_die;
};

#endif
