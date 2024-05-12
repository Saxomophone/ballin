#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>


int initialiseSDL() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "Failed to initialize the SDL2 library\n";
      return -1;
  }
  return 0;
}

SDL_Window* createWindow(const int width, const int height) {
  SDL_Window* window = SDL_CreateWindow("SDL2 Window",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        width,
                                        height,
                                        0);

  if(!window)
    {
        std::cout << "Failed to create window\n";
        exit(-1);
    }
  
  return window;
}

SDL_Surface* createSurface(SDL_Window* window) {
  SDL_Surface* window_surface = SDL_GetWindowSurface(window);

  if (!window_surface) {
    std::cout << "Failed to get the surface from the window\n";
    exit(-1);
  }

  return window_surface;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!renderer) {
    std::cout << "Failed to create renderer\n";
    exit(-1);
  }

  return renderer;
}