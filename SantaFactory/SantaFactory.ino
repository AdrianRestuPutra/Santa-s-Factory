#include <Arduboy2.h>
#include <ArduboyTones.h>

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

// Santa Factory Library
#include "GameState.h"
#include "Images.h"

#include "MainMenuScene.h"
#include "GameScene.h"

using namespace std;

GameState *gameState;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(36);
  arduboy.initRandomSeed();

  gameState = new GameState();
  initiateGameScene(gameState);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();

  switch (gameState->currentState) {
    case STATE_CREDIT:
      stateCredit(gameState);
      break;
    case STATE_PRE_PLAYING:
      statePrePlaying(gameState);
      break;
    case STATE_PLAYING:
      statePlaying();
      break;
    case STATE_MAIN_MENU:
      stateMainMenu(gameState);
      break;
    case STATE_PRE_GAME_OVER:
      statePreGameOver(gameState);
      break;
    case STATE_GAME_OVER:
      stateGameOver(gameState);
      break;
    case STATE_HELP:
      stateHelp(gameState);
      break;
  }

  arduboy.display();
}
