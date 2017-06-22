//
// Pacman.hh for Pacman.hh in /home/remy/rendu/cpp_arcade/games/Pacman
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Tue Mar 28 15:35:18 2017 Rémy
// Last update Sun Apr  9 23:09:07 2017 Yannis
//

#ifndef PACMAN_HH_
#define PACMAN_HH_

#include <unistd.h>
#include <iostream>

#include <thread>
#include "Ghost.hh"
#include "../../score/Score.hh"
#include "../../interfaces/IGame.hh"
#include "../../character/Character.hh"
#include "../../map/Map.hh"
#include "../../Protocol.hpp"

class Pacman : public IGame
{
public:
  Pacman();
  ~Pacman();

  virtual const std::string getName() const;
  virtual unsigned int getSpeed() const;

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

  virtual int getTime() const;
  
  void  GhostMoving();
  void	spawnPower();
  void	checkEndRound();

  void	PlayTimer();
  
private:
  std::string _title;
  Character *_character;
  int _speed;
  Map *_map;
  bool _die;
  Score *_score;
  int	_oldCase;
  bool	_etat;
  int	_powerTime;
  int	_powerTimeReaming;

  unsigned int	_time;
  bool		_timerOn;
  std::thread   *_timer;

  int			_nbGhost;
  std::vector<Ghost *>	_ghosts;
};

#endif
