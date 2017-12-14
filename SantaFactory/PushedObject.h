#ifndef PUSHED_OBJECT_H
#define PUSHED_OBJECT_H

#include <Arduboy2.h>
#include "Vector2.h"
#include "Images.h"
#include "GameState.h"

class PushedObject {
  public:
    PushedObject(Arduboy2 &arduboy, GameState *gameState);

    void Trigger(int giftType, int pushIndex);
    void Update(int *score);

    bool enabled;

  private:
    Arduboy2 *arduboy;
    GameState *gameState;
    
    int giftType;
    int pushIndex;
    Vector2 position;
};

#endif
