#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../include/units.h"

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
  return 0;
}