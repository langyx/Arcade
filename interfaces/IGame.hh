//
// Igame.hh for  in /home/manu/TEK2/cpp_arcade/games
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Mon Mar 27 17:42:16 2017 Manu
// Last update Sun Apr  9 22:59:21 2017 Yannis
//

#ifndef IGAME_HH_
#define IGAME_HH_

#include <string>
#include "../character/Character.hh"
#include "../map/Map.hh"
#include "../score/Score.hh"

class IGame
{
public:

  virtual ~IGame() {}

  virtual bool isAlive() const = 0;
  virtual bool isWin() const = 0;
  virtual void goUp() = 0;
  virtual void goDown() = 0;
  virtual void goLeft() = 0;
  virtual void goRight() = 0;

  virtual void          loop_moving() = 0;
  virtual Character       *getCharacter() const = 0;
  virtual Map             *getMap()  const = 0;
  virtual Score		  *getScore() const = 0;
  virtual void		showMap() const = 0;

  virtual const std::string getName() const = 0;
  virtual unsigned int getSpeed() const = 0;

  virtual int		getTime() const = 0;
};

#endif
