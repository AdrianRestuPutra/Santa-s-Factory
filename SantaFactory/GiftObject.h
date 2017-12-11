#ifndef GIFT_OBJECT_H
#define GIFT_OBJECT_H

#include <Arduboy2.h>

#include "Vector2.h"

class GiftObject {
  public:
    GiftObject();
    GiftObject(Arduboy2 &arduboy, int x, int y);
    
    void SetPosition(int x, int y);
    void SetVelocity(int x, int y);
    void Update();

    bool enabled;
    
    Vector2 position;
    
    int giftType;

  private:
    Arduboy2 *arduboy;

    Vector2 velocity;

    void draw();
    void updatePosition();
};

#endif
