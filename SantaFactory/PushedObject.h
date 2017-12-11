#ifndef PUSHED_OBJECT_H
#define PUSHED_OBJECT_H

#include <Arduboy2.h>
#include "Vector2.h"

class PushedObject {
  public:
    PushedObject(Arduboy2 &arduboy);

    void Trigger(int giftType, int pushIndex);
    void Update();

    bool enabled;

  private:
    Arduboy2 *arduboy;
    int giftType;
    int pushIndex;
    Vector2 position;
};

#endif
