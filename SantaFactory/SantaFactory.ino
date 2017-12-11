#include <Arduboy2.h>
#include <ArduboyTones.h>

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

// Santa Factory Library
#include "Images.h"
#include "GameScene.h"

using namespace std;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(36);
  arduboy.initRandomSeed();

  statePrePlay();
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();

  statePlaying();

  arduboy.display();
}
