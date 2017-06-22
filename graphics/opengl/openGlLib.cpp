//
// openGlLib.cpp for openGL in /home/yannis/tek2/rendu/cpp_arcade/graphics/opengl
//
// Made by yannis
// Login   <yannis.lang@epitech.eu>
//
// Started on  Wed Mar 15 03:09:33 2017 yannis
// Last update Sun Apr  9 20:33:19 2017 Manu
//

#include "openGlLib.hpp"

OpenGlLib::OpenGlLib()
{
  TTF_Init();
  Sans = TTF_OpenFont("./graphics/sfml/arial.ttf", 100);
  _renderer = NULL;
  _win = NULL;
  _wall_texture = NULL; 
  _floor_texture = NULL;
  _apple_texture = NULL;
  _snake_texture = NULL;
  _pacman_texture = NULL;
  _ghost_texture = NULL;
  _dfloor_texture = NULL;
  _dPoint_floor_texture = NULL;
  _bwall_texture = NULL;
  _powerup_texture = NULL;
  _background_texture = NULL;
  _snake_head_texture = NULL;
}

OpenGlLib::~OpenGlLib()
{
}

void OpenGlLib::createWindows()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "Failed to init SDL\n";
      return;
    }
  _win = SDL_CreateWindow("Arcade <3 YL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
  if (!_win)
    {
      std::cout << "Unable to create window\n";
      return;
    }
  _renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  _wall_texture = IMG_LoadTexture(_renderer,
				  "./ressources/texture/wall_gl.jpg");
  _floor_texture = IMG_LoadTexture(_renderer,
				   "./ressources/texture/floor_gl.jpg");
  _pacman_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/ppacman_gl.png");
  _ghost_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/prghost_gl.png");
  _dfloor_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/pfloor_gl.png");
  _dPoint_floor_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/ppfloor_gl.png");
  _bwall_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/pwall_gl.png");
  _powerup_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/ppower_up_gl.png");
  _background_texture = IMG_LoadTexture(_renderer,
				    "./ressources/texture/background.png");
  _snake_head_texture = IMG_LoadTexture(_renderer,
					"./ressources/texture/snake_head_gl.png");
  SDL_GL_SwapWindow(_win);
}


void OpenGlLib::clearWindows2()
{
  return;
}

void OpenGlLib::clearWindows()
{
  SDL_RenderClear(_renderer);
}

void OpenGlLib::displayWindows()
{
  SDL_RenderPresent(_renderer);
}

void OpenGlLib::destroyWindows()
{
  SDL_Quit();
}

char OpenGlLib::getEventNoBlock(unsigned int duration)
{
  SDL_Event event;
  
  SDL_WaitEventTimeout(&event, duration);
  switch(event.type)
    {
    case SDL_QUIT:
      return 'q';
    case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
	{
	case SDLK_PERIOD:
	  return '.';
        case SDLK_ESCAPE:
	case SDLK_q :
	  return 'q';
	case 233: case SDLK_2:
	  return '2';
	case 38:
	  return '1';
	case 167:
	  return '6';
	case 232:
	  return '7';
	case 33:
	  return '8';
	case 224:
	  return '0';
	case 59:
	  return '.';
	case 34: case SDLK_3:
	  return '3';
	case 39: case SDLK_4:
	  return '4';
	case 40: case SDLK_5:
	  return '5';
	case SDLK_6 :
	  return '6';
	case SDLK_7 :
	  return '7';
	case 231: case SDLK_9:
	  return '9';
	case SDLK_UP:
	case SDLK_u :
	  return 'u';
	case SDLK_DOWN:
	case SDLK_d :
	  return 'd';
	case SDLK_RIGHT:
	case SDLK_r :
	  return 'r';
	case SDLK_LEFT:
	case SDLK_l :
	  return 'l';
	case SDLK_RETURN:
	case SDLK_e :
	  return 'e';
	case SDLK_j:
	  return 'j';
	case SDLK_a:
	  return 'a';
	case SDLK_b:
	  return 'b';
	case SDLK_c:
	  return 'c';
	case SDLK_f:
	  return 'f';
	case SDLK_g:
	  return 'g';
	case SDLK_h:
	  return 'h';
	case SDLK_i:
	  return 'i';
	case SDLK_k:
	  return 'k';
	case SDLK_m:
	  return 'm';
	case SDLK_n:
	  return 'n';
	case SDLK_o:
	  return 'o';
	case SDLK_p:
	  return 'p';
	case SDLK_s:
	  return 's';
	case SDLK_t:
	  return 't';
	case SDLK_v:
	  return 'v';
	case SDLK_w:
	  return 'w';
	case SDLK_x:
	  return 'x';
	case SDLK_y:
	  return 'y';
	case SDLK_z:
	  return 'z';
	}
    }
  return (' ');
}

char OpenGlLib::getEvent()
{
  SDL_Event event;

  SDL_WaitEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      return 'q';
    case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
	{
	case SDLK_PERIOD:
	  return '.';
        case SDLK_ESCAPE:
	case SDLK_q :
	  return 'q';
	case 38:
	  return '1';
	case 167:
	  return '6';
	case 232:
	  return '7';
	case 33:
	  return '8';
	case 224:
	  return '0';
	case 59:
	  return '.';
	case 233: case SDLK_2:
	  return '2';
	case 34: case SDLK_3:
	  return '3';
	case 39: case SDLK_4:
	  return '4';
	case 40: case SDLK_5:
	  return '5';
	case SDLK_6 :
	  return '6';
	case SDLK_7 :
	  return '7';
	case 231: case SDLK_9:
	  return '9';
	case SDLK_UP:
	case SDLK_u :
	  return 'u';
	case SDLK_DOWN:
	case SDLK_d :
	  return 'd';
	case SDLK_RIGHT:
	case SDLK_r :
	  return 'r';
	case SDLK_LEFT:
	case SDLK_l :
	  return 'l';
	case SDLK_RETURN:
	case SDLK_e :
	  return 'e';
	case SDLK_j:
	  return 'j';
	case SDLK_a:
	  return 'a';
	case SDLK_b:
	  return 'b';
	case SDLK_c:
	  return 'c';
	case SDLK_f:
	  return 'f';
	case SDLK_g:
	  return 'g';
	case SDLK_h:
	  return 'h';
	case SDLK_i:
	  return 'i';
	case SDLK_k:
	  return 'k';
	case SDLK_m:
	  return 'm';
	case SDLK_n:
	  return 'n';
	case SDLK_o:
	  return 'o';
	case SDLK_p:
	  return 'p';
	case SDLK_s:
	  return 's';
	case SDLK_t:
	  return 't';
	case SDLK_v:
	  return 'v';
	case SDLK_w:
	  return 'w';
	case SDLK_x:
	  return 'x';
	case SDLK_y:
	  return 'y';
	case SDLK_z:
	  return 'z';
	}
    }
  return (' ');
}

void OpenGlLib::setMext(int x, int y, const std::string &txt)
{
  if (Sans == NULL)
    std::cout << "ERROR OPENING FONT = " << TTF_GetError() << std::endl;
  SDL_Color White = {255, 255, 255, 100};
  std::string temp = txt;
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, txt.c_str(), White);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
  SDL_Rect Message_rect;
  Message_rect.x = x;
  Message_rect.y = y;
  Message_rect.w = 22 * txt.size();
  Message_rect.h = 50;
  SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
  SDL_RenderPresent(_renderer);
}

void OpenGlLib::setMextNoRefresh(int x, int y, const std::string &txt)
{
  if (Sans == NULL)
    std::cout << "ERROR OPENING FONT = " << TTF_GetError() << std::endl;
  SDL_Color White = {255, 255, 255, 100};
  std::string temp = txt;
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, txt.c_str(), White);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
  SDL_Rect Message_rect;
  Message_rect.x = x;
  Message_rect.y = y;
  Message_rect.w = 22 * txt.size();
  Message_rect.h = 50;
  SDL_RenderCopy(_renderer, Message, NULL, &Message_rect);
}

void OpenGlLib::createWall(int x, int y,
			   unsigned int height,
			   unsigned int width)
{
  SDL_Rect s_rect;

  if (_wall_texture == NULL)
    std::cout << "Texture not load";
  s_rect.x = x;
  s_rect.y = y;
  s_rect.w = height;
  s_rect.h = width; 
  SDL_RenderCopy(_renderer, _wall_texture, NULL, &s_rect);
}

void OpenGlLib::setTexture(int x, int y, unsigned int height, unsigned int width , const std::string &file)
{
  SDL_Texture * s = NULL;
  if (file == "floor")
    s = _floor_texture;
  else if (file == "apple")
    {
      if (_apple_texture == NULL)
	{
	  _apple_texture =
	    IMG_LoadTexture(_renderer,
			    "./ressources/texture/apple_gl.jpg");
	}
      s = _apple_texture;
    }
    else if (file == "snake")
      {
	if (_snake_texture == NULL)
	  {
	    _snake_texture =
	      IMG_LoadTexture(_renderer,
			      "./ressources/texture/snake_gl.jpg");
	  }
	s = _snake_texture;
      }
    else if (file == "pacman")
      s = _pacman_texture;
    else if (file == "ghost")
      s = _ghost_texture;
    else if (file == "dfloor")
      s = _dfloor_texture;
    else if (file == "dPoint_floor")
      s = _dPoint_floor_texture;
    else if (file == "bwall")
      s = _bwall_texture;
    else if (file == "powerup")
      s = _powerup_texture;
    else if (file == "background")
      s = _background_texture;
    else if (file == "snake_head")
      s = _snake_head_texture;
    else
      s = IMG_LoadTexture(_renderer, file.c_str());
  if (s == NULL)
    std::cout << "FAILED TO FIND THE IMAGE== " << file << std::endl; 
   SDL_Rect s_rect;
  s_rect.x = x;
  s_rect.y = y;
  s_rect.w = height;
  s_rect.h = width;
  SDL_RenderCopy(_renderer, s, NULL, &s_rect);
}

extern "C" IGfx *create()
{
  return (new OpenGlLib());
}
