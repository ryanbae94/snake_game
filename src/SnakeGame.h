#ifndef __GAME__
#define __GAME__

#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <queue>
#include <vector>

//00. define
#define COLOR_GRAY 8

enum Direction{
  up = -1,
  down = 1,
  left = -2,
  right = 2
};

//01. Snake map
class Display{
  WINDOW * snake_win;
  int height, width, start_row, start_col;
  int timeout;
  void construct(int height, int width, int speed);
public:
  void init();
  void init_coloring();
  void coloring(int stage_num);
  void addBorder();
  void refresh();
  void clear();
};

//02. Snake
class SnakeBody:public Drawing{
public:
  SnakeBody();
  SnakeBody(int y, int x);
};

class Snake{
  std::queue<SnakeBody> prev_pieces;
  Direction cur_direction;

public:
  Snake();
  void addPiece(SnakeBody piece);
  void removePiece();
  SnakeBody tail();
  SnakeBody head();
  Direction getDirection();
  void setDirection(Direction d);
  SnakeBody nextHead();
};

//Game Setting
class SnakeGame{
  Display display;
  bool game_over;
  int stage_count = 0;

public:
  SnakeGame();
  // ~SnakeGame();

  void init();
  void updateState();
  void redraw();
  bool isOver();
  int getStageCount();
};



#endif
