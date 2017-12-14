#ifndef GAME_STATE_H
#define GAME_STATE_H

const static int STATE_PLAYING = 0;
const static int STATE_PRE_GAME_OVER = 1;
const static int STATE_MAIN_MENU = 2;
const static int STATE_PRE_PLAYING = 3;
const static int STATE_CREDIT = 4;

class GameState {
  public:
    GameState() {
      currentState = STATE_MAIN_MENU;
    }

    int currentState;
};

#endif
