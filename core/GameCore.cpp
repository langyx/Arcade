// GameCore.cpp for GameCore in /home/yannis/tek2/rendu/cpp_arcade/core
//
// Made by yannis
// Login   <yannis.lang@epitech.eu>
//
// Started on  Thu Mar 16 16:22:55 2017 yannis
// Last update Fri Apr 14 13:49:05 2017 Yannis
//

#include "./inc/GameCore.hh"

GameCore::GameCore(const std::string &file_path)
{
  _currentLibPath = file_path;
  _graphicLib = NULL;
  _gameLib = NULL;
  _currentGame = "";
  _server = NULL;
  _serverLoop = NULL;
  _client = NULL;
  _clientLoop = NULL;
  _clientMsgFromServ = "";
  _multiAdvScore = "-1";
}

GameCore::~GameCore()
{
  if (_server != NULL)
    delete _server;
  if (_serverLoop != NULL)
    delete _serverLoop;
  if (_client != NULL)
    delete _client;
  if (_clientLoop != NULL)
    delete _clientLoop;
}

void	GameCore::mainMenu()
{
  std::vector<std::string>::iterator	    it;
  std::vector<std::string>::iterator	    last  = _gameLibs.end();
  last--;
  std::vector<std::string>::iterator	    curs = _gameLibs.begin();
  int					    y = 50;
  int					    x  = 50;

  _currentGame = "";
  while (_currentGame == "")
    {
      _graphic->setTexture(0, 0, 800,800, "background");
      x = 50;
      y = 50;
      for(it = _gameLibs.begin() ; it < _gameLibs.end(); it++) {
	if (it == curs)
	  {
	    this->_graphic->setMextNoRefresh(x, y, ">");
	  }
	this->getGraphic()->setMextNoRefresh(x + 150, y, *it);
	y += 150;
      }
      this->getGraphic()->setMextNoRefresh(x + 150, y, "[enter] to play solo");
      y += 50;
      this->getGraphic()->setMextNoRefresh(x + 150, y, "[h] to host");
      y += 50;
      this->getGraphic()->setMextNoRefresh(x + 150, y, "[j] to join");
      switch (this->getGraphic()->getEventNoBlock(1))
	{
	case 'h':
	  _playerMode = 1;
	  _currentGame = *(curs);
	  break;
	case 'j':
	  _playerMode = 2;
	  _currentGame = *(curs);
	  break;
	case 'u':
	  if (curs == _gameLibs.begin())
	    curs = last;
	  else
	    curs--;
	  break;
	case 'd':
	  if (curs == last)
	    curs = _gameLibs.begin();
	  else
	    curs++;
	  break;
	case 'q':
	  exit(1);
	case '3':
	  this->nextGraphic();
	  break;
	case '2':
	  this->backGraphic();
	  break;
	case 'e':
	  _playerMode = 0;
	  _currentGame = *(curs);
	  break;
	}
      this->getGraphic()->displayWindows();
      this->getGraphic()->clearWindows();
      this->getGraphic()->clearWindows2();
    }
  this->getGraphic()->clearWindows();
  this->getGraphic()->displayWindows();
}

void	GameCore::preLoadP(int y, int x, int y_draw, int x_draw)
{
  if (_game->getMap()->getMap()[y][x] ==
      (int) arcade::TileType::BLOCK)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio, "bwall");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::OBSTACLE)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "dfloor");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::POWERUP)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "powerup");
  else if (_game->getMap()->getMap()[y][x] ==
		       (int) arcade::TileType::OTHER)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "pacman");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::EMPTY)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "dPoint_floor");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::EVIL_DUDE)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "ghost");
}

void	GameCore::preLoadS(int y, int x, int y_draw, int x_draw)
{
  if (_game->getMap()->getMap()[y][x] ==
      (int) arcade::TileType::BLOCK)
    _graphic->createWall(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio);
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::EMPTY)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
				     "floor");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::POWERUP)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
				     (unsigned int) _ratio,
			 "apple");
  else if (_game->getMap()->getMap()[y][x] ==
	   (int) arcade::TileType::OTHER)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "snake");
  else if (_game->getMap()->getMap()[y][x] ==
		       (int) arcade::TileType::MY_SHOOT)
    _graphic->setTexture(x_draw, y_draw,
			 (unsigned int) _ratio,
			 (unsigned int) _ratio,
			 "snake_head");
}

void	GameCore::drawMap()
{
  int x_draw = 50;
  int y_draw = 100;
  
  _ratio = sqrt((700 * 700) / ((_game->getMap()->getHeight()) *
			       (_game->getMap()->getWidth())));
  for (int y = 0; y < _game->getMap()->getHeight(); y += 1)
    {
      x_draw = 50;
      for (int x = 0; x < _game->getMap()->getWidth(); x += 1)
	{
	  if (_game->getName() == "Snake" || _game->getName() == "Nibbler")
	    this->preLoadS(y, x, y_draw, x_draw);
	  if (_game->getName() == "Pacman")
	    this->preLoadP(y, x, y_draw, x_draw);
	  x_draw += _ratio;
	}
      y_draw += _ratio;
    } 
 this->getGraphic()->displayWindows();
 this->getGraphic()->clearWindows();
}

void	GameCore::drawHeader()
{
  int	x = 50;
  int	y = 50;

  _graphic->setMextNoRefresh(x, y, "Score :");
  x += 150;
  _graphic->setMextNoRefresh(x, y, std::to_string(this->_game->getScore()->getCurrent()));
  if (_game->getTime() != -1)
    {
      x += 100;
      _graphic->setMextNoRefresh(x, y, std::to_string(_game->getTime()));
      x += 40;
      _graphic->setMextNoRefresh(x, y, "s.");
    }
  if (_multiAdvScore != "-1")
    {
      x += 100;
      _graphic->setMextNoRefresh(x, y, "Opponent :");
      x += 214;
      _graphic->setMextNoRefresh(x, y, _multiAdvScore);
    }
}

const std::string GameCore::getIp() const
{
  std::string	newIp = "";
  char		buff;
  
  this->getGraphic()->clearWindows();
  while ((buff = this->_graphic->getEventNoBlock(10)) != 'e')
    {
      if (buff != ' ')
	newIp += buff;
      this->getGraphic()->setMextNoRefresh(50, 50, "Enter server ip :");
      this->getGraphic()->setMextNoRefresh(50, 250, newIp);
      this->getGraphic()->displayWindows();
      usleep(1000);
      this->getGraphic()->clearWindows();
    }
  return (newIp);
}

void	GameCore::StartServer()
{
  std::cout << _server->start() << std::endl;
}

void	GameCore::StartClient()
{
  while (this->_game->isAlive() == false)
    {
      _clientMsgFromServ = _client->send(std::to_string((int) _game->getScore()->getCurrent()));
      _multiAdvScore = _clientMsgFromServ;
    }
  _clientMsgFromServ = _client->send("-1");
}

void	GameCore::mainLoop()
{
  std::string	lib_game_path = "./games/lib_arcade_";

  if (_graphicLib == NULL)
    {
      this->loadGraphic("");
      this->getGraphic()->createWindows();
    }
  this->mainMenu();
  lib_game_path += _currentGame + ".so";
  this->loadGame(lib_game_path);
  if (_playerMode == 1)
    {
      _server = new TCPServer(HPORT);
      _serverLoop = new std::thread(&GameCore::StartServer, this);
      
      int lWait = 0;
      while (_server->getClientMsg() == "none")
	{
	  this->getGraphic()->setMextNoRefresh(50, 50, "Waiting for player");
	  switch (lWait)
	    {
	    case 0:
	      this->getGraphic()->setMextNoRefresh(700, 50, ".");
	      break;
	    case 1:
	      this->getGraphic()->setMextNoRefresh(700, 50, "..");
	      break;
	    default:
	      this->getGraphic()->setMextNoRefresh(700, 50, "...");
	      lWait = -1;
	      break;
	    }
	  this->getGraphic()->displayWindows();
	  usleep(100000);
	  lWait += 1;
	  this->getGraphic()->clearWindows();
	}
    }
  else if (_playerMode == 2)
    {
      _client = new TCPClient(this->getIp(), HPORT);
      this->getGraphic()->clearWindows();
      this->getGraphic()->setMextNoRefresh(50, 50, "Launching ...");
      this->getGraphic()->displayWindows();
      sleep(2);
      this->getGraphic()->clearWindows();
      _clientLoop  = new std::thread(&GameCore::StartClient, this);
    }
  while(this->_game->isAlive() == false)
    {
      if (_playerMode == 1)
	{
	  _server->setServMsg(std::to_string((int) _game->getScore()->getCurrent()));
	  _multiAdvScore = _server->getClientMsg();
	}
      switch (this->_graphic->getEventNoBlock(_game->getSpeed()))
	{
	case 'u' :
	  this->_game->goUp();
	  break;
	case 'd' :
	  this->_game->goDown();
	  break;
	case 'l' :
	  this->_game->goLeft();
	  break;
	case 'r' :
	  this->_game->goRight();
	  break;
	case '3':
	  this->nextGraphic();
	  break;
	case '2':
	  this->backGraphic();
	  break;
	case '4':
	  this->backGame();
	  break;
	case '5':
	  this->nextGame();
	  break;
	case '8':
	  this->restartGame();
	  break;
	case '9':
	  this->leaveGame();
	  break;
	case 'q':
	  this->_graphic->destroyWindows();
	  exit(0);
	  break;
        }
      this->_game->loop_moving();
      this->drawHeader();
      this->drawMap();
    }
  this->getGraphic()->clearWindows2();
  if (_playerMode != 0)
    {
      std::string __temp;
      if (_playerMode == 1)
	{
	  __temp = _multiAdvScore;
	  while (_multiAdvScore != "-2")
	    {
	      _multiAdvScore = _server->getClientMsg();
	      __temp = _multiAdvScore;
	    }
	  _server->setServMsg("end");
	  _server->setRun(false);
	  _serverLoop->join();
	  delete _server;
	  delete _serverLoop;
	  _serverLoop = NULL;
	  _server = NULL;
	}
      else
	{
	  std::string buff;
	  while ((buff = _client->send("-2")) != "end")
	    {
	      std::size_t found, foundM;
	      found = buff.find("ERROR");
	      foundM = buff.find("Error");
	      if (found != std::string::npos || foundM != std::string::npos)
		break;
	      __temp = buff;
	    }
	  _clientLoop->join();
	  delete _client;
	  delete _clientLoop;
	  _client = NULL;
	  _clientLoop = NULL;
	}
      this->getGraphic()->clearWindows();
      if (_playerMode == 1)
	{
	  if (__temp == "-1")
	    this->getGraphic()->setMextNoRefresh(50, 50, "You Loose");
	  else
	    this->getGraphic()->setMextNoRefresh(50, 50, "You Win");
	}
      else
	{
	  if (__temp == "0")
	    this->getGraphic()->setMextNoRefresh(50, 50, "You Win");
	  else
	    this->getGraphic()->setMextNoRefresh(50, 50, "You Loose");
	}
      this->getGraphic()->displayWindows();
      while (this->_graphic->getEvent() == ' ');
    }
  else
    this->endGame();
  _playerMode = 0;
  this->mainLoop();
}

void GameCore::endGame()
{
  char buff;
  std::string text = "";
  int x = 350;
  int y = 50;
  std::vector<unsigned int> indxScore = _game->getScore()->getAllScore();
  std::vector<std::string> indxPlayer = _game->getScore()->getAllPlayer();

  while ((buff = this->_graphic->getEventNoBlock(1)) != 'e')
    {
      int index_vect = indxScore.size() -1;
      _graphic->setTexture(0, 0, 800,800, "background");
      x = 350;
      y = 50;
      if (buff != ' ')
	text += buff;
      this->_graphic->setMextNoRefresh(x, y, "GAME OVER  !");
      y += 100;
      this->_graphic->setMextNoRefresh(x, y, "YOUR SCORE : ");
      x += 175;
      this->_graphic->setMextNoRefresh(x, y,
			      std::to_string(this->_game->getScore()->getCurrent()));
      y += 100;
      x = 350;
      this->_graphic->setMextNoRefresh(x, y, "THREE LAST SCORE");
      y += 100;
      x = 200;
      for (int i = 0; i < 3; i += 1)
	{
	  if ((int)indxScore.size() > 3)
	    {
	      this->_graphic->setMextNoRefresh(x, y, std::to_string(indxScore[index_vect]));
	      this->_graphic->setMextNoRefresh(x + 150, y, indxPlayer[index_vect]);
	    }
	  y += 100;
	  index_vect -= 1;
	}
      x += 100;
      this->_graphic->setMextNoRefresh(x, y, text);
      this->_graphic->displayWindows();
      if (_currentLibPath != "./graphics/lib_arcade_ncurses.so")
	this->_graphic->clearWindows();
      usleep(50000);
    }
  this->_game->getScore()->writeScore(text);
}

void	GameCore::nextGame()
{
  std::vector<std::string>::iterator        it;
  std::vector<std::string>::iterator        last  = _gameLibs.end();
  last -= 1;
  std::string				    newPath = "./games/lib_arcade_";

  if (_currentGame == newPath + *last + ".so")
    newPath += *_gameLibs.begin() + ".so";
  else
    {
      for(it = _gameLibs.begin() ; it < _gameLibs.end(); it += 1)
	{
	  if (newPath + *it + ".so" == _currentGame)
	    {
	      it += 1;
	      newPath += *it + ".so";
	      break;
	    }
	}
    }
  _currentGame = newPath;
  this->loadGame(newPath);
  return;
}

void	GameCore::leaveGame()
{
  this->mainLoop();
}

void	GameCore::restartGame()
{
  this->loadGame(_currentGame);
}

void	GameCore::backGame()
{
  std::vector<std::string>::iterator        it;
  std::vector<std::string>::iterator        last  = _gameLibs.end();
  last--;
  std::string				    newPath = "./games/lib_arcade_";

  if (_currentGame == newPath + *_gameLibs.begin() + ".so")
    newPath += *last + ".so";
  else
    {
      for(it = _gameLibs.begin() ; it < _gameLibs.end(); it++)
	{
	  if (newPath + *it + ".so" == _currentGame)
	    {
	      it--;
	      newPath += *it + ".so";
	      break;
	    }
	}
    }
  _currentGame = newPath;
  this->loadGame(newPath);
}

void	GameCore::nextGraphic()
{
  std::vector<std::string>::iterator        it;
  std::vector<std::string>::iterator        last  = _graphicLibs.end();
  last--;
  std::string				    newPath = "./graphics/lib_arcade_";

  if (_currentLibPath == newPath + *last + ".so")
    newPath += *_graphicLibs.begin() + ".so";
  else
    {
      for(it = _graphicLibs.begin() ; it < _graphicLibs.end(); it += 1)
	{
	  if (newPath + *it + ".so" == _currentLibPath)
	    {
	      it += 1;
	      newPath += *it + ".so";
	      break;
	    }
	}
    }
  _graphic->destroyWindows();
  _currentLibPath = newPath;
  this->loadGraphic(newPath);
  this->getGraphic()->createWindows();
  return;
}

void	GameCore::backGraphic()
{
  std::vector<std::string>::iterator        it;
  std::vector<std::string>::iterator        last  = _graphicLibs.end();
  last--;
  std::string				    newPath = "./graphics/lib_arcade_";

  if (_currentLibPath == newPath + *_graphicLibs.begin() + ".so")
    newPath += *last + ".so";
  else
    {
      for(it = _graphicLibs.begin() ; it < _graphicLibs.end(); it++)
	{
	  if (newPath + *it + ".so" == _currentLibPath)
	    {
	      it--;
	      newPath += *it + ".so";
	      break;
	    }
	}
    }
  _graphic->destroyWindows();
  _currentLibPath = newPath;
  this->loadGraphic(newPath);
  this->getGraphic()->createWindows();
  return;
}

void    GameCore::loadGraphic(std::string file_path)
{
  gfx_create_t	*new_gfx_create;

  if (file_path == "")
    file_path = _currentLibPath;
  if (_graphicLib != NULL)
    dlclose(_graphicLib);
  _currentLibPath = file_path;
  if ((_graphicLib = dlopen(file_path.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cerr << "(Erreur) Ouverture de : " << file_path << std::endl;
      exit(EXIT_FAILURE);
      return;
    }
  if ((new_gfx_create = (gfx_create_t *)dlsym(_graphicLib, "create")) == NULL)
    {
      dlclose(_graphicLib);
      std::cerr << "(Erreur) Chargement du symbole create" << std::endl;
      exit(EXIT_FAILURE);
      return;
    }
  _graphic = new_gfx_create();
}


IGfx *GameCore::getGraphic() const
{
  return _graphic;
}

void	GameCore::loadGame(const std::string &file_path)
{
  game_create_t	*game_create;

  if (_gameLib != NULL)
    dlclose(_gameLib);
  _currentGame = file_path;
  if ((_gameLib = dlopen(file_path.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cerr << "(Erreur) Ouverture de : " << file_path << std::endl;
      exit(EXIT_FAILURE);
      return;
    }
  if ((game_create = (game_create_t *)dlsym(_gameLib, "create")) == NULL)
    {
      dlclose(_gameLib);
      std::cerr << "(Erreur) Chargement du symbole create" << std::endl;
      exit(EXIT_FAILURE);
      return;
    }
  _game = game_create();
}

IGame *GameCore::getGame() const
{
  return _game;
}
