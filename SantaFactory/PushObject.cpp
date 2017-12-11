#include "PushObject.h"
#include "Images.h"

const static int Y_BASE = 57;

const static int pushPositions[3] = {7, 32, 57};

PushObject::PushObject(Arduboy2 &_arduboy, int _y) {
  arduboy = &_arduboy;
  
  y = _y;
  pushCurrentIndex = 0;
}

void PushObject::handleInput() {
  if (arduboy->justPressed(RIGHT_BUTTON)) {
    pushCurrentIndex = (pushCurrentIndex + 1) % 3;
  }

  if (arduboy->justPressed(LEFT_BUTTON)) {
    pushCurrentIndex = ((pushCurrentIndex - 1) + 3) % 3;
  }

  if (y == Y_BASE && arduboy->justPressed(A_BUTTON)) {
    y = 45;
  }
}

void PushObject::Update() {
  if (y < Y_BASE)
    y += 2;
  if (y > Y_BASE)
    y = Y_BASE;
  
  handleInput();
  
  arduboy->fillRect(pushPositions[pushCurrentIndex], y, 16, 32, BLACK);
  arduboy->drawBitmap(pushPositions[pushCurrentIndex], y, push_image, 16, 32, WHITE);
}

