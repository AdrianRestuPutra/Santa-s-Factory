#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GiftObject.h"
#include "ConveyorLine.h"

GiftObject *objects[3];

ConveyorLine *bottomConveyors[9];
ConveyorLine *leftConveyors[3];
ConveyorLine *centerConveyors[3];
ConveyorLine *rightConveyors[3];

/**
 * State before playing
 */
void statePrePlay() {
  GiftObject *obj = new GiftObject(arduboy, 128, 42, right_off_arrow);
  objects[0] = obj;

  for (int i = 0; i < 4; i++) {
    bottomConveyors[i] = new ConveyorLine(arduboy, 20 + (40 * i), 42, 40, right_off_arrow, Vector2(-1, 0));
  }

  for (int i = 0; i < 2; i++) {
    leftConveyors[i] = new ConveyorLine(arduboy, 7, (32 * i) + 5, 32, right_off_arrow, Vector2(0, -1));
  }

  for (int i = 0; i < 2; i++) {
    centerConveyors[i] = new ConveyorLine(arduboy, 32, (32 * i) + 5, 32, right_off_arrow, Vector2(0, -1));
  }

  for (int i = 0; i < 2; i++) {
    rightConveyors[i] = new ConveyorLine(arduboy, 57, (32 * i) + 5, 32, right_off_arrow, Vector2(0, -1));
  }
}

/**
 * State playing
 */
void drawLayout();
 
void statePlaying() {
  drawLayout();

  // objects[0]->Update();
}

void drawLayout() {
    /**
    * Draw 3 fixed boxes
    */
    arduboy.fillRect(5,  5, 20, 20, WHITE);
    arduboy.fillRect(30, 5, 20, 20, WHITE);
    arduboy.fillRect(55, 5, 20, 20, WHITE);

    /**
    * Draw center convoyer
    */
    arduboy.fillRect(5, 24, 20, 17, WHITE);
    arduboy.fillRect(30, 24, 20, 17, WHITE);
    arduboy.fillRect(55, 24, 20, 17, WHITE);

    for (int i = 0; i < 2; i++) {
      leftConveyors[i]->Update();
    }

    for (int i = 0; i < 2; i++) {
      centerConveyors[i]->Update();
    }

    for (int i = 0; i < 2; i++) {
      rightConveyors[i]->Update();
    }

    /**
    * Draw bottom convoyer
    */
    arduboy.fillRect(-1, 40, 130, 20, WHITE);

    /**
    * Convoyer animation 
    */
    for (int i = 0; i < 4; i++) {
      bottomConveyors[i]->Update();
    }

    /**
    * Draw top black box
    */
    arduboy.fillRect(0, 0, 128, 5, BLACK);
}

#endif
