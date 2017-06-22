//
// Character.hh for  in /home/yannis/tek2/rendu/cpp_arcade/character
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Mon Mar 27 16:37:40 2017 yannis
// Last update Tue Mar 28 01:52:42 2017 yannis
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

#include "../Protocol.hpp"

class Character
{
public:
  Character(uint16_t x, uint16_t y, uint16_t lenght);
  ~Character();

  arcade::Position	getPos() const;
  void			setPos(int x, int y);
  void			setLenght(uint16_t lenght);
  void			setCommand(arcade::CommandType command);
  uint16_t		getLenght() const;
  arcade::CommandType	getCommand() const;
  
private:
  arcade::Position	_pos;
  uint16_t		_lenght;
  arcade::CommandType	_command;
};

#endif
