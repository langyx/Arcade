//
// Map.hh for Map.hh in /home/remy/rendu/cpp_arcade/map
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Mon Mar 27 16:25:59 2017 Rémy
// Last update Tue Mar 28 14:58:32 2017 yannis
//

#ifndef MAP_HH_
#define MAP_HH_

#include <string>
#include <cstring>
#include <string.h>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "../Protocol.hpp"

class Map
{
public:

  Map(int width, int height, std::string name);
  Map(const char *);
  ~Map();

  int** getMap() const;

  void initMap();
  void loadmap();

  int	getWidth() const;
  int	getHeight() const;

  void	setMap(int x, int y, arcade::TileType type);
  void	Show() const;
  
private:

  int width;
  int height;
  int **map;

  std::string _path;
  std::string name;
};

#endif
