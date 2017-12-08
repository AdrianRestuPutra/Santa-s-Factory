#include <Arduboy2.h>
#include <ArduboyTones.h>

// Santa Factory Library
#include "Images.h"
#include "GiftObject.h"

using namespace std;

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

GiftObject *objects[5];

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();

  GiftObject *obj = new GiftObject(arduboy, 0, 0, right_off_arrow);
  objects[0] = obj;
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  
  arduboy.clear();

  objects[0]->Update();
  //arduboy.setCursor(0, 0);
  //arduboy.print("BOOM");

  arduboy.display();
}
