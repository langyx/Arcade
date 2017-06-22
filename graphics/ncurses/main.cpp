//
// main.cpp for  in /home/manu/TEK2/cpp_arcade/graphics/ncurses
// 
// Made by Manu
// Login   <vallen_e@epitech.net>
// 
// Started on  Wed Mar 15 03:59:08 2017 Manu
// Last update Thu Mar 16 17:55:26 2017 Manu
//

#include "Ncurses.hpp"

int main()
{
  Ncurses bite;

  bite.createWindows();
  //bite.clearWindows();
  //bite.setText(14, 12, "bite");
  bite.createWall(100, 15, 19, 102);
  bite.getEvent();
  return (0);
}
