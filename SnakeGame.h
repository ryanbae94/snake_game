#ifndef __GAME__
#define __GAME__

#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <queue>
#include <vector>

class Snake;

class SnakeGame {
    Display display;
    bool game_over;
    int stage_count = 0;

class Display{
  WINDOW * snake_win;
  int height, width, start_row, start_col;
  int timeout;
  void construct(int height, int width, int speed);
public:
  void init();
  void init_coloring();
  void coloring(int stage_num);
  void refresh();
};

public:
    SnakeGame(){
        display = Display();
        init();
    }

    void init(){
        display.init();
        display.init_coloring();
        display.coloring(stage_count);
        game_over = false;
    }

        void makeGate();
        void clearGate();
        bool isMakingGateNow(int n);
};



#endif
