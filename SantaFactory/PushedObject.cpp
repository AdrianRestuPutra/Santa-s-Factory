#include "PushedObject.h"

const static int IMAGE_SIZE = 16;
const static int pushPositions[3] = {7, 32, 57};

PushedObject::PushedObject(Arduboy2 &_arduboy, GameState *_gameState) {
  arduboy = &_arduboy;
  gameState = _gameState;

  enabled = false;
}

void PushedObject::Trigger(int _giftType, int _pushIndex) {
  giftType = _giftType;
  pushIndex = _pushIndex;

  position = Vector2(pushPositions[_pushIndex], 30);

  enabled = true;
}

void PushedObject::Update(int *score) {
  if (!enabled) 
    return;

  if (position.y > 7) {
    position.y -= 1;
  } else {
    if (enabled) {
      if (giftType != pushIndex) {
        gameState->currentState = STATE_PRE_GAME_OVER;
      } else {
        *score += 1;
      }
    }
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

