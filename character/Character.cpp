//
// Character.cpp for  in /home/yannis/tek2/rendu/cpp_arcade/character
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Mon Mar 27 16:48:46 2017 yannis
// Last update Tue Mar 28 02:26:37 2017 yannis
//

#include "Character.hh"

uint16_t	Character::getLenght() const
{
  return _lenght;
}

Character::Character(uint16_t x, uint16_t y, uint16_t lenght)
{
  _pos.x = x;
  _pos.y = y;
  _lenght = lenght;
  _command = arcade::CommandType::PLAY;
}

Character::~Character()
{
  
}

void	Character::setPos(int x, int y)
{
  _pos.x = x;
  _pos.y = y;
}

void	Character::setLenght(uint16_t lenght)
{
  _lenght = lenght;
}

void    Character::setCommand(arcade::CommandType command)
{
  _command = command;
}

arcade::Position      Character::getPos() const
{
  return (_pos);
}

arcade::CommandType   Character::getCommand() const
{
  return _command;
}
