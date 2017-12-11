#ifndef PUSH_OBJECT_H
#define PUSH_OBJECT_H

#include <Arduboy2.h>

#include "Vector2.h"

class PushObject {
  public:
    PushObject(Arduboy2 &arduboy, int y);

    void Update();
    
    int pushCurrentIndex;

  private:
    Arduboy2 *arduboy;
    
    int y;

    void handleInput();
};

#endif
