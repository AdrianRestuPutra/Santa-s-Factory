#include "GiftObject.h"
#include "Images.h"

const static int IMAGE_SIZE = 16;

/**
 * CONSTRUCTOR
 */

GiftObject::GiftObject(Arduboy2 &_arduboy, int _x, int _y, GameState *_gameState) {
  arduboy = &_arduboy;
  gameState = _gameState;

  position = Vector2(_x, _y);
  velocity = Vector2(-1, 0);

  enabled = false;

  giftType = random(0, 3);
}

/**
 * PUBLIC METHOD
 */

void GiftObject::Update(int *level) {
  if (position.x <= -16) {
    if (enabled) {
      gameState->currentState = STATE_PRE_GAME_OVER;
    }

    if (random(0, *level) == 0)
      enabled = true; 
    position.x = 128;
    giftType = random(0, 3);
  }
  
  updatePosition();

  if (!enabled)
    return;
  
  draw();
}

void GiftObject::SetPosition(int x, int y) {
  position.x = x;
  position.y = y;
}

void GiftObject::SetVelocity(int x, int y) {
  velocity.x = x;
  velocity.y = y;
}

/**
 * PRIVATE METHOD
 */

void GiftObject::draw() {
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

void GiftObject::updatePosition() {
  position += velocity;
}

