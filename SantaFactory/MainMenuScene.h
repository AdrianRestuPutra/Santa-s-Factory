
#include "Images.h"

const int MAIN_MENU_TOTAL = 3;

int mainMenuIndex = 0;

void statePreMainMenu(GameState *gameState) {
  mainMenuIndex = 0;
  
  gameState->currentState = STATE_MAIN_MENU;
}

void stateMainMenu(GameState *gameState) {
  arduboy.drawBitmap(0, 0, main_menu, 128, 64, WHITE);

  if (arduboy.justPressed(LEFT_BUTTON))
    mainMenuIndex = ((mainMenuIndex - 1) + MAIN_MENU_TOTAL) % MAIN_MENU_TOTAL;
  if (arduboy.justPressed(RIGHT_BUTTON))
    mainMenuIndex = (mainMenuIndex + 1) % MAIN_MENU_TOTAL;

  arduboy.drawBitmap(10, 47, left_indicator, 8, 8, WHITE);
  arduboy.drawBitmap(56, 47, right_indicator, 8, 8, WHITE);
  
  if (mainMenuIndex == 0) {
    arduboy.setCursor(23, 47);
    arduboy.print("START");
  } else if (mainMenuIndex == 1) {
    arduboy.setCursor(20, 47);
    arduboy.print(" HELP");
  } else if (mainMenuIndex == 2) {
    arduboy.setCursor(20, 47);
    arduboy.print("CREDIT");
  }

  if (arduboy.justPressed(A_BUTTON)) {
    if (mainMenuIndex == 0)
      gameState->currentState = STATE_PRE_PLAYING;
    if (mainMenuIndex == 1)
      gameState->currentState = STATE_HELP;
    if (mainMenuIndex == 2)
      gameState->currentState = STATE_CREDIT;
  }
}

void stateCredit(GameState *gameState) {
  arduboy.drawBitmap(0, 10, credit_image, 128, 64, WHITE);
  
  if (arduboy.justPressed(B_BUTTON))
    gameState->currentState = STATE_MAIN_MENU;
}

void stateHelp(GameState *gameState) {
  arduboy.drawRect(33, 1, 62, 62, WHITE);
  arduboy.drawBitmap(34, 2, qr_code, 60, 60, WHITE);

  if (arduboy.justPressed(B_BUTTON))
    gameState->currentState = STATE_MAIN_MENU;
}

