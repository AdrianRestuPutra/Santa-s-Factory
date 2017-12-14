#ifndef GIFT_OBJECT_H
#define GIFT_OBJECT_H

#include <Arduboy2.h>

#include "Vector2.h"
#include "GameState.h"

class GiftObject {
  public:
    GiftObject();
    GiftObject(Arduboy2 &arduboy, int x, int y, GameState *gameState);
    
    void SetPosition(int x, int y);
    void SetVelocity(int x, int y);
    void Update(int *level);

    bool enabled;
    
    Vector2 position;
    
    int giftType;

  private:
    Arduboy2 *arduboy;

    Vector2 velocity;

    GameState *gameState;

    void draw();
    void updatePosition();
};

#endif
