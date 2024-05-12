#pragma once

#ifndef SDL_BOILERPLATE_H
#define SDL_BOILERPLATE_H
#include <SDL2/SDL.h>

int initialiseSDL();
SDL_Window* createWindow(const int width, const int height);
SDL_Surface* createSurface(SDL_Window* window);
SDL_Renderer* createRenderer(SDL_Window* window);

#endif