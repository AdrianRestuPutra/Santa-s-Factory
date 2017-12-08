#include "ConveyorLine.h"

ConveyorLine::ConveyorLine(Arduboy2 &_arduboy, int _x, int _y, int _limit, const uint8_t *_bitmap, Vector2 _velocity) {
  arduboy    = &_arduboy;

  position  = Vector2(_x, _y);
  velocity  = _velocity;
  transform = Vector2(0, 0);

  limit = _limit;

  bitmap = _bitmap;
}

void ConveyorLine::Update() {
  arduboy->fillRect(
    position.x + transform.x, 
    position.y + transform.y, 
    16, 16, BLACK);
  arduboy->drawBitmap(
    position.x + transform.x, 
    position.y + transform.y, 
    bitmap, 16, 16, WHITE);

  transform += velocity;

  if (abs(transform.x + transform.y) >= limit) {
    transform.x = 0;
    transform.y = 0;
  }
}

