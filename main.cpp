//
// main.cpp for Core in /home/yannis/tek2/rendu/cpp_arcade/core
// 
// Made by yannis
// Login   <yannis.lang@epitech.eu>
// 
// Started on  Thu Mar 16 16:54:47 2017 yannis
// Last update Sat Apr  8 00:36:13 2017 Yannis
//

#include "./core/inc/GameCore.hh"

int	main(int ac, char **av)
{
  if(ac == 2)
    {
      std::string	graphPath(av[1]);
      GameCore core(graphPath);
      core.mainLoop();
      return (EXIT_SUCCESS);
    }
  else
    std::cerr << "Usage " << av[0] << " [lib_name]" << std::endl;
  return (EXIT_FAILURE);
}
