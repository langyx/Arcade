//
// Score.cpp for  in /home/yannis/tek2/rendu/cpp_arcade/score
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Mar 30 11:34:32 2017 yannis
// Last update Fri Apr  7 18:27:59 2017 Manu
//

#include "Score.hh"

Score::Score(const std::string &title)
{
  _game = "./score/" + title + ".score";
  _best = 0;
  _current = 0;
  this->loadFile();
}

Score::~Score()
{
}

void	Score::setCurrent(unsigned int news)
{
  _current = news;
}

unsigned int	Score::getBest() const
{
  return _best;
}

unsigned int	Score::getCurrent() const
{
  return _current;
}

void	Score::writeScore(const std::string &player)
{
  std::ofstream _output(_game, std::ios::ate|std::ios::app);
  _output << (int) _current;
  _output << ";";
  if (player.size() == 0)
    _output << "Guest" << std::endl;
  else
    _output << player << std::endl;   
  _output.close();
}

void	Score::loadFile()
{
  std::vector<std::string>	buff;
  std::string			line_buff;

  _file.open(_game, std::ios::out|std::ios::in);
  if (!_file.is_open())
    _file.open(_game, std::ios::out|std::ios::in|std::ios::trunc);
  while (std::getline(_file, line_buff))
    buff.push_back(line_buff);
  _file.close();
  for (int i = 0; (unsigned int) i < buff.size() ; i += 1)
    {
      std::vector<std::string> temp;
      temp = explode(buff[i], ';');
      _all_score.push_back((unsigned int)std::atoi(temp[0].c_str()));
      _all_player.push_back(temp[1]);
    }
  for (int i = 0; (unsigned int) i < _all_score.size() ; i += 1)
    if (_all_score[i] > _best)
      _best = _all_score[i];
}

std::vector<unsigned int>     Score::getAllScore() const
{
  return _all_score;
}

std::vector<std::string>     Score::getAllPlayer() const
{
  return _all_player;
}

std::vector<std::string> explode(std::string const & s, char delim)
{
  std::vector<std::string> result;
  std::istringstream iss(s);

  for (std::string token; std::getline(iss, token, delim); )
    result.push_back(std::move(token));
  return result;
}
