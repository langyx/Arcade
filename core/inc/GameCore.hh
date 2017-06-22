//
// GameCore.cpp for GameCore in /home/yannis/tek2/rendu/cpp_arcade/core/inc
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Mar 16 16:04:33 2017 yannis
// Last update Fri Apr 14 13:49:40 2017 Yannis
//

#ifndef GAMECORE_CPP_
# define GAMECORE_CPP_

#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <thread> 
#include <pthread.h>

#include "../../interfaces/IGfx.hpp"
#include "../../interfaces/IGame.hh"

#include "../../server/server/server.hh"
#include "../../server/client/client.hh"

#define HPORT "4242"
#define LOCALHOST "LOCALHOST"

class GameCore
{
public:
  GameCore(const std::string &);
  ~GameCore();

  /* GRAPHIQUE */
  void	loadGraphic(const std::string);
  void	nextGraphic();
  void	backGraphic();
  IGfx *getGraphic() const;
  void	drawMap();
  void	drawHeader();
  
  /* GAME */
  void	loadGame(const std::string &);
  IGame *getGame() const;
  void	nextGame();
  void	backGame();
  void	restartGame();
  void	leaveGame();
  
  void	mainLoop();
  void  mainMenu();
  void	endGame();

  /* MULTI */
  void	StartServer();
  void	StartClient();

  void	preLoadS(int y, int x, int y_draw, int x_draw);
  void  preLoadP(int y , int x, int y_draw, int x_draw);
  
private:

  /* GRAPHIQUE */
  int	_ratio;
  IGfx	*_graphic;
  std::string _currentLibPath;
  
  /* GAME */
  IGame *_game;
  std::string _currentGame;
  int	_time;
  
  std::vector<std::string> _graphicLibs {"ncurses", "opengl", "sfml"};
  std::vector<std::string> _gameLibs {"Snake", "Pacman", "Nibbler"};
 
  void	*_graphicLib;
  void	*_gameLib;

  /* MULTI*/
  int		_playerMode; // 0 = play // 1 = host // 2 = join 
  std::string	_multiAdvScore;
  
  TCPServer *_server;
  std::thread *_serverLoop;

  TCPClient *_client;
  std::string _clientMsgFromServ;
  std::thread *_clientLoop;

  const std::string getIp() const;
  /*******/
};

typedef IGfx *gfx_create_t();
typedef IGame *game_create_t();

#endif
