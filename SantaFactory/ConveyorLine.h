#ifndef CONVEYOR_LINE_H
#define CONVEYOR_LINE_H

#include "Vector2.h"
#include <Arduboy2.h>

class ConveyorLine {
  public:
    ConveyorLine(Arduboy2 &arduboy, int x, int y, int limit, const uint8_t *bitmap, Vector2 velocity);

    void Update();
    

  private:
    Arduboy2 *arduboy;

    Vector2 position;
    Vector2 velocity;
    Vector2 transform;

    int limit;

    const uint8_t *bitmap;
};

#endif
