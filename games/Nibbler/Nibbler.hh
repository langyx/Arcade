//
// Nibbler.hh for  in /home/manu/TEK2/cpp_arcade/games/Nibbler
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Thu Apr  6 18:54:05 2017 Manu
// Last update Sun Apr  9 23:15:15 2017 Yannis
//

#ifndef NIBBLER_HH_
#define NIBBLER_HH_

#include <unistd.h>
#include <iostream>
#include <thread>

#include "../../score/Score.hh"
#include "../../interfaces/IGame.hh"
#include "../../character/Character.hh"
#include "../../map/Map.hh"
#include "../../Protocol.hpp"

typedef struct	s_pos
{
  int x;
  int y;
}		t_pos;

class Nibbler : public IGame
{
public:
  Nibbler();
  ~Nibbler();

  virtual const std::string getName() const;
  virtual unsigned int getSpeed() const;

  void spawn_food();
  void ClearMapPlayer();
  void initScore();
  void check_direction(t_pos *new_pos);
  bool check_food();

  void PlayTimer();
  
  virtual bool isAlive() const;
  virtual bool isWin() const;
  virtual void goUp();
  virtual void goDown();
  virtual void goLeft();
  virtual void goRight();
  bool checkingPos(int x, int y);
  virtual void showMap() const;
  virtual void          loop_moving();
  virtual Map                   *getMap()               const;
  virtual Character             *getCharacter()         const;
  virtual Score                 *getScore() const;
  virtual int			getTime() const;
  
private:
  std::string _title;
  Character *_character;
  int _speed;
  Map *_map;
  Map *_map2;
  Map *_map3;
  bool _die;
  Score *_score;
  std::vector<t_pos> h_tail;
  int **_tmp;
  bool _count;

  int		_time;
  bool		_timerOn;
  std::thread	*_timer;
};

#endif
