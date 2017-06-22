//
// Map.cpp for Map.cpp in /home/remy/rendu/cpp_arcade/map
// 
// Made by Rémy
// Login   <remy.viscaino@epitech.eu>
// 
// Started on  Mon Mar 27 16:27:57 2017 Rémy
// Last update Thu Mar 30 22:51:12 2017 Rémy
//

#include "Map.hh"

Map::Map(const char *file)
{
  _path = file;
  this->width = 0;
  this->height = 0;
  this->loadmap();
}

Map::Map(int width, int height, std::string name)
{
  this->width = width;
  this->height = height;
  this->name = name;
  this->map = NULL;
  this->initMap();
}

Map::~Map()
{
  if (this->map != NULL)
    {
      for(int i = 0; i < this->height; i++)
	delete[] this->map[i];
    }
  delete[] this->map;
}

int	Map::getWidth() const
{
  return this->width;
}

int	Map::getHeight() const
{
  return this->height;
}

void	Map::setMap(int x, int y, arcade::TileType type)
{
  this->map[y][x] = (int) type;
}

void Map::initMap()
{
 
  this->map = new int*[this->height];
  for(int i = 0; i < this->height; i+=1)
    {
      this->map[i] = new int[this->width];
      memset(this->map[i], 0, this->width * sizeof(int));
    }
  if (this->name == "Snake")
    {
      for (int x = 0; x < this->width ; x += 1)
	{
	  this->map[0][x] = 1;
	  this->map[this->height - 1][x] = 1;
	}
      for (int y = 1; y < this->height - 1; y += 1)
	{
	  this->map[y][0] = 1;
	  this->map[y][this->width - 1] = 1;
        }
    }
}

void	Map::Show() const
{
  for (int y = 0; y < this->height; y += 1)
    {
      for (int x = 0; x < this->width; x += 1)
	{
	  std::cout << map[y][x];
	}
      std::cout << std::endl;
    }
}

int **Map::getMap() const
{
  return(this->map);
}


void Map::loadmap()
{
  std::vector<std::string>	buff;
  std::ifstream file(_path);
  std::string	str;
  int		t_height = 0;
 
  while (std::getline(file, str))
    {
      buff.push_back(str);
      t_height += 1;
    }
  file.close();
  this->height = t_height;
  this->width = strlen(buff[0].c_str());
  this->initMap();
  for (int y = 0; y < this->height; y += 1)
    {
      char *cstr = new char [str.length()+1];
      std::strcpy(cstr, buff[y].c_str());
      for (int x = 0; x < this->width ; x += 1)
	this->map[y][x] = (int) cstr[x] - '0';
    }
}
