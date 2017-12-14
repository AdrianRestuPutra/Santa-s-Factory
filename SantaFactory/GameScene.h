#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GiftObject.h"
#include "ConveyorLine.h"
#include "PushObject.h"
#include "PushedObject.h"

GiftObject *objects[6];

ConveyorLine *bottomConveyors[4];
ConveyorLine *leftConveyors[2];
ConveyorLine *centerConveyors[2];
ConveyorLine *rightConveyors[2];

PushObject *pushObject;

PushedObject *pushedObjects[5];

const int pushPositions[3] = {7, 32, 57};

int score = 0;
int level = 3;

/**
 * State before playing
 */
void initiateGameScene(GameState *gameState) {
  for (int i = 0; i < 6; i++) {
    objects[i] = new GiftObject(arduboy, 128 + i * (8 + 16), 42, gameState);
  }

  for (int i = 0; i < 4; i++) {
    bottomConveyors[i] = new ConveyorLine(arduboy, 20 + (40 * i), 42, 40, conveyor_left, Vector2(-1, 0));
  }

  for (int i = 0; i < 2; i++) {
    leftConveyors[i] = new ConveyorLine(arduboy, 7, (32 * i) + 5, 32, conveyor_up, Vector2(0, -1));
  }

  for (int i = 0; i < 2; i++) {
    centerConveyors[i] = new ConveyorLine(arduboy, 32, (32 * i) + 5, 32, conveyor_up, Vector2(0, -1));
  }

  for (int i = 0; i < 2; i++) {
    rightConveyors[i] = new ConveyorLine(arduboy, 57, (32 * i) + 5, 32, conveyor_up, Vector2(0, -1));
  }

  pushObject = new PushObject(arduboy, 57);

  for (int i = 0; i < 5; i++) {
    pushedObjects[i] = new PushedObject(arduboy, gameState);
  }

  score = 0;
  level = 2;
}

void statePrePlaying(GameState *gameState) {
  for (int i = 0; i < 6; i++) delete objects[i];
  for (int i = 0; i < 4; i++) delete bottomConveyors[i];
  for (int i = 0; i < 2; i++) delete leftConveyors[i];
  for (int i = 0; i < 2; i++) delete centerConveyors[i];
  for (int i = 0; i < 2; i++) delete rightConveyors[i];
  delete pushObject;
  for (int i = 0; i < 5; i++) delete pushedObjects[i];

  initiateGameScene(gameState);
  gameState->currentState = STATE_PLAYING;
}

/**
 * State playing
 */
void drawLayout();
void drawPushObject();
void drawBoxIndicator();
void handleInput();
 
void statePlaying() {
  handleInput();
  
  drawLayout();

  for (int i = 0; i < 6; i++)
    objects[i]->Update(&level);
  
  pushObject->Update();

  for (int i = 0; i < 5; i++)
    pushedObjects[i]->Update(&score);

  drawBoxIndicator();

  if (score > 0) {
    level = max((2 - (score / 15)), 0);
  }
}

void handleInput() {
  if (arduboy.justPressed(A_BUTTON)) {
    int currentIndex = pushObject->pushCurrentIndex;

    for (int i = 0; i < 6; i++) {
      if (objects[i]->enabled && abs(objects[i]->position.x - pushPositions[currentIndex]) < 10) {
        objects[i]->enabled = false;

        for (int j = 0; j < 5; j++) {
          if (!pushedObjects[j]->enabled) {
            pushedObjects[j]->Trigger(objects[i]->giftType, currentIndex);
            break;
          }
        }
        break;
      }
    }
  }
}

void drawLayout() {
  arduboy.drawBitmap(110, 20, steel_image, 16, 64, WHITE);
  arduboy.drawBitmap(85, 30, steel_image, 16, 64, WHITE);
  
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
  arduboy.fillRect(75, 39, (128 - 75), 22, BLACK);
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


  arduboy.drawBitmap(80, 7, score_box, 8, 8, WHITE);
  
  arduboy.setCursor(90, 7);
  arduboy.print(":");
  arduboy.print(score);
}

void drawBoxIndicator() {
  arduboy.fillRect(6, 6, 18, 18, BLACK);
  arduboy.drawBitmap(7, 7, love_gift, 16, 16, WHITE);

  arduboy.fillRect(31, 6, 18, 18, BLACK);
  arduboy.drawBitmap(32, 7, cylinder_gift, 16, 16, WHITE);

  arduboy.fillRect(56, 6, 18, 18, BLACK);
  arduboy.drawBitmap(57, 7, candy_gift, 16, 16, WHITE);
}

/**
 * GAME OVER
 */

int gameOverDelay = 30;

void statePreGameOver(GameState *gameState) {
  gameOverDelay = 30;
  gameState->currentState = STATE_GAME_OVER;
}

void stateGameOver(GameState *gameState) {
  if(gameOverDelay > 0)
    arduboy.digitalWriteRGB(RGB_ON, RGB_OFF, RGB_OFF);

  arduboy.drawBitmap(0, 0, game_over_image, 128, 64, WHITE);

  int charLength = (15 * 5);
  if (score < 10) charLength += 5;
  else if (score < 100) charLength += 10;
  else if (score < 1000) charLength += 15;
  else charLength += 20;

  arduboy.setCursor(55 - (charLength / 2), 50);
  arduboy.print("YOU WRAP ");
  arduboy.print(score);
  arduboy.print(" GIFTS");
  
  if (gameOverDelay-- > 0)
    return;

  arduboy.digitalWriteRGB(RGB_OFF, RGB_OFF, RGB_OFF);
  
  if (arduboy.justPressed(A_BUTTON))
    gameState->currentState = STATE_MAIN_MENU;
}

#endif
