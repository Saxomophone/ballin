#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../include/units.h"
#include "../include/SDL_Boilerplate.h"

using namespace units::literals;
using namespace units;
using namespace units::length;
using namespace units::time;
using namespace units::area;
using namespace units::velocity;
using namespace units::mass;
using namespace units::acceleration;
using namespace units::force;
using namespace units::math;

#define GRAVITY 9.8     // m/s^2
#define DRAG_COEFF 0.47 // drag coefficient for a sphere

class Ball {
  public:
    Ball(meter_t x, meter_t y, meter_t z, gram_t mass, std::vector<meters_per_second_t> velocity) : x(x), y(y), z(z), mass(mass), velocity(velocity) {}
    meter_t x, y, z;
    gram_t mass;
    std::vector<meters_per_second_t> velocity;
};


void checkValidVelocity(std::vector<meters_per_second_t> velocity) {
    if (velocity.size() != 3) {
        throw std::invalid_argument("Velocity vector must have 3 components");
    }
}

int main() {
  Ball ball(0_m, 0_m, 0_m, 1_kg, {0_mps, 0_mps, 0_mps});
  std::cout << "Ball created at (" << ball.x.value() << ", " << ball.y.value() << ", " << ball.z.value() << ")" << std::endl;
  
  //SDL Setup
  initialiseSDL();
  SDL_Window* window = createWindow(800, 800);
  SDL_Surface* window_surface = createSurface(window);
  SDL_Renderer* renderer = createRenderer(window);
  int window_width, window_height;
  bool checkStep = true;

  // Event loop
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN) {
          if (event.key.keysym.sym == SDLK_SPACE) {
            checkStep = true;
          }
        }
    }

    if (checkStep) {

      SDL_GetRendererOutputSize(renderer, &window_width, &window_height);
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer); // Clear the renderer to a solid color

      // Code goes here

      SDL_RenderPresent(renderer);

      checkStep = false;
    }
  }
  
  

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}