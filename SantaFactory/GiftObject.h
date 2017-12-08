#ifndef GIFT_OBJECT_H
#define GIFT_OBJECT_H

#include <Arduboy2.h>

#include "Vector2.h"

class GiftObject {
  public:
    GiftObject();
    GiftObject(Arduboy2 &arduboy, int x, int y, const uint8_t *bitmap);
    
    void SetPosition(int x, int y);
    void SetVelocity(int x, int y);
    void Update();

    bool enabled;

  private:
    Arduboy2 *arduboy;
   
    const uint8_t *bitmap;

    Vector2 position;
    Vector2 velocity;

    void draw();
    void updatePosition();
};

#endif
