//
// Score.hh for score in /home/yannis/tek2/rendu/cpp_arcade/score
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Mar 30 11:22:11 2017 yannis
// Last update Tue Apr  4 18:50:09 2017 Yannis
//

#ifndef SCORE_HH_
#define SCORE_HH_

#include <fstream>
#include <sstream>
#include <string>
#include <ostream>
#include <iostream>
#include <utility>
#include <vector>

class	Score
{
public:
  Score(const std::string &title);
  ~Score();

  void		setCurrent(unsigned int);
  void		loadFile();
  
  unsigned int	getBest() const;
  unsigned int	getCurrent() const;

  void		writeScore(const std::string &player);

  std::vector<unsigned int>	getAllScore() const;
  std::vector<std::string>	getAllPlayer() const;
private:
  std::string			_game;
  unsigned int			_current;
  unsigned int			_best;
  std::vector<unsigned int>	_all_score;
  std::vector<std::string>	_all_player;

  std::ifstream			_file;
};

std::vector<std::string> explode(std::string const & s, char delim);

#endif
