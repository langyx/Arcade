//
// server.hh for  in /home/yannis/work/TcpSocketC/server
// 
// Made by Yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Apr  6 11:26:05 2017 Yannis
// Last update Fri Apr  7 12:50:43 2017 Yannis
//

#ifndef SERVER_H_
# define SERVER_H_

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>


class	TCPServer
{
  
public:
  TCPServer(const std::string &port);
  ~TCPServer();

  const std::string		start();
  void				talk(int sock);

  void	setServMsg(const std::string &msg);
  const std::string getClientMsg() const;
  void    setRun(bool __run);

private:
  int		_port;
  std::string	_servmsg;
  std::string	_clientmsg;
  bool		_run;
};

#endif
