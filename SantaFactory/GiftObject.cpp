#include "GiftObject.h"

const static int IMAGE_SIZE = 16;

/**
 * CONSTRUCTOR
 */

GiftObject::GiftObject(Arduboy2 &_arduboy, int _x, int _y, const unsigned char *_bitmap) {
  arduboy = &_arduboy;
 
  bitmap = _bitmap;

  position = Vector2(_x, _y);
  velocity = Vector2(0, 0);

  enabled = true;
}

/**
 * PUBLIC METHOD
 */

void GiftObject::Update() {
  if (!enabled)
    return;
  
  if (position.x >= 128)
    position.x = -16;
  
  updatePosition();
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
  arduboy->drawBitmap(position.x, position.y, bitmap, IMAGE_SIZE, IMAGE_SIZE, WHITE);
}

void GiftObject::updatePosition() {
  position += velocity;
}

