//
// clien.hh for  in /home/yannis/work/TcpSocketC/client
// 
// Made by Yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Apr  6 10:33:04 2017 Yannis
// Last update Thu Apr  6 20:27:23 2017 Yannis
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class TCPClient
{
public :
  TCPClient(const std::string &host_name, const std::string &port);
  ~TCPClient();

  const std::string	send(const std::string &message) const;
  
private:
  std::string	_hostname;
  int		_hostport;
};
  
#endif
