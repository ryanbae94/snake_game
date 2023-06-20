#ifndef __SNAKEGAME__
#define __SNAKEGAME__

#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <queue>

//00. define
#define COLOR_GRAY 8

enum Direction{
  up = -1,
  down = 1,
  left = -2,
  right = 2
};

//02.Snake & Item
class Drawing{
public:
  Drawing(){
    y = x = 0;
    data = 8;
  }
  Drawing(int y, int x, int ch);
  int getX();
  int getY();
  int getData();

protected:
  int y, x, data;
};

class GrowthItem:public Drawing{
public:
  GrowthItem(int y, int x);
};

class PoisonItem:public Drawing{
public:
  PoisonItem(int y, int x);
};

class BlankData:public Drawing{
public:
  BlankData(int y, int x);
};

class SnakeBody:public Drawing{
public:
  SnakeBody();
  SnakeBody(int y, int x);
  void setData(int data);
};

class Snake{
  std::queue<SnakeBody> prev_bodies;
  Direction cur_direction;

public:
  Snake();
  void addBody(SnakeBody body);
  void removeBody();
  SnakeBody tail();
  SnakeBody head();
  Direction getDirection();
  void setDirection(Direction d);
  SnakeBody nextHead();
};

// 01. Snake map
class Display{
  WINDOW * snake_win;
  int height, width, start_row, start_col;
  int timeout;

public:
  void init();
  void init_coloring();
  void coloring(int stage_num);
  void addBorder();
  void add(Drawing drawing);
  void addAt(int y, int x, int ch);
  chtype getInput();
  void getEmptyCoordinates(int& y, int& x);
  int getCharAt(int y, int x);
  void refresh();
  void clear();
};

class SnakeGame{
  Display display;
  bool game_over;
  int stage_count = 0;
  Snake snake;
  PoisonItem *poisonItem;
  GrowthItem *growthItem;

  void handleNextBody(SnakeBody next);
  void createGrowth();
  void getGrowth();
  void createPoison();
  void getPoison();

public:
  SnakeGame();
  ~SnakeGame();

  void init();
  void processInput();
  void updateState();
  void redraw();
  bool isOver();
  int getStageCount();
};

#endif
