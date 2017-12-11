#include "PushedObject.h"
#include "Images.h"

const static int IMAGE_SIZE = 16;
const static int pushPositions[3] = {7, 32, 57};

PushedObject::PushedObject(Arduboy2 &_arduboy) {
  arduboy = &_arduboy;

  enabled = false;
}

void PushedObject::Trigger(int _giftType, int _pushIndex) {
  giftType = _giftType;
  pushIndex = _pushIndex;

  position = Vector2(pushPositions[_pushIndex], 30);

  enabled = true;
}

void PushedObject::Update() {
  if (!enabled) 
    return;

  if (position.y > 7) {
    position.y -= 1;
  } else {
    enabled = false;
  }
  
  arduboy->fillRect(position.x - 1, position.y - 1, IMAGE_SIZE + 2, IMAGE_SIZE + 2, BLACK);
  switch(giftType) {
    case 0:
      arduboy->drawBitmap(position.x, position.y, love_gift, IMAGE_SIZE, IMAGE_SIZE, WHITE);
      break;
    case 1:
      arduboy->drawBitmap(position.x, position.y, cylinder_gift, IMAGE_SIZE, IMAGE_SIZE, WHITE);
      break;
    case 2:
      arduboy->drawBitmap(position.x, position.y, candy_gift, IMAGE_SIZE, IMAGE_SIZE, WHITE);
      break;
  }
}

