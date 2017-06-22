/*
** server.c for server in /home/yannis/work/TcpSocketC/server
** 
** Made by Yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Thu Apr  6 09:47:37 2017 Yannis
// Last update Fri Apr  7 18:50:29 2017 Yannis
*/

#include "server.hh"

TCPServer::TCPServer(const std::string &port)
{
  _port = htons(atoi(port.c_str()));
  _servmsg = "none";
  _clientmsg = "none";
  _run = true;
}

TCPServer::~TCPServer()
{
}

void	TCPServer::setRun(bool __run)
{
  _run  = __run;
}

const std::string	TCPServer::start()
{
  int sockfd, newsockfd; //pid;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  const int trueFlag = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0)
    return "error setsockopt";
  
  if (sockfd < 0)
    return ("ERROR opening socket");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = _port;
  
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0)
    {
      printf("Error: unable to bind\n");
      printf("Error code: %d\n", errno);
      return ("ERROR on binding");
    }
  
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  while (_run)
    {
      newsockfd = accept(sockfd,
			 (struct sockaddr *) &cli_addr, &clilen);
      if (newsockfd < 0)
	return ("ERROR on accept");
      std::thread process(&TCPServer::talk, this, newsockfd);
      process.join();
      close(newsockfd);
    }
  close(sockfd);
  return "never";
}

void	TCPServer::talk(int sock)
{
  int n;
  char buffer[256];
  
  bzero(buffer,256);
  n = read(sock,buffer,255);
  if (n < 0)
    {
      std::cerr << "Error during talk" << std::endl;
      return;
    }
  _clientmsg = std::string(buffer, strlen(buffer));
  n = write(sock, _servmsg.c_str(), _servmsg.size());
  if (n < 0)
    std::cerr << "Error during talk" << std::endl;
}

void	TCPServer::setServMsg(const std::string &msg)
{
  _servmsg = msg;
}

const std::string TCPServer::getClientMsg() const
{
  return (_clientmsg);
}

