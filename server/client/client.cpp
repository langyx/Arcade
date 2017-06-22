/*
** client.c for client in /home/yannis/work/TcpSocketC/client
** 
** Made by Yannis
** Login   <yannis.lang@epitech.eu>
** 
** Started on  Thu Apr  6 09:49:22 2017 Yannis
// Last update Fri Apr  7 11:24:12 2017 Yannis
*/

#include "client.hh"

TCPClient::TCPClient(const std::string &host_name, const std::string &port)
{
  _hostname = host_name;
  _hostport = htons(atoi(port.c_str()));
}

TCPClient::~TCPClient()
{
}

const std::string     TCPClient::send(const std::string &message) const
{
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    return "ERROR opening socket";
  server = gethostbyname(_hostname.c_str());
  if (server == NULL)
    return "ERROR, no such host";
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  //  bcopy((char *)server->h_addr,
  //	(char *)&serv_addr.sin_addr.s_addr,
  //	server->h_length);
  serv_addr.sin_port = _hostport;
  serv_addr.sin_addr.s_addr = inet_addr(_hostname.c_str());
  usleep(1000);
  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    return "Error connecting";
  n = write(sockfd,message.c_str(),strlen(message.c_str()));
  if (n < 0)
    return "Error writting to socket";
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
    return "Error reading from socket";
  close(sockfd);
  return (buffer);
}
