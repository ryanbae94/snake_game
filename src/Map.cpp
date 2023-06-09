#include "SnakeGame.h"
#include "map.h"

void Display::init(){
  int xMax, yMax;
  getmaxyx(stdscr, yMax, xMax);
  snake_win = newwin(25, 25, (yMax/2)-12, (xMax/2)-12);
  keypad(snake_win, true);
}

void Display::init_coloring(){
  init_color(COLOR_GRAY, 500, 500, 500);
  init_pair(1, COLOR_WHITE, COLOR_WHITE); //(0)Blank
  init_pair(2, COLOR_GRAY, COLOR_GRAY);   //(1)Wall
  init_pair(3, COLOR_BLACK, COLOR_BLACK); //(2)Immune Wall
  init_pair(4, COLOR_YELLOW, COLOR_YELLOW); //(3)Snake Head
  init_pair(5, COLOR_BLUE, COLOR_BLUE);   //(4)Snake Body
  init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA); //(5)Gate
  init_pair(7, COLOR_RED, COLOR_RED);   //(6)Poison Item
  init_pair(8, COLOR_GREEN, COLOR_GREEN); //(7)Growth Item
}

void Display::coloring(int stage_num){
  for(int i = 0; i < 25; i++){
    for(int j = 0; j < 25; j++){
      wattron(snake_win, COLOR_PAIR(map[stage_num][i][j] + 1));
      mvwprintw(snake_win, i, j, "-");
      // wattroff(snake_win, COLOR_PAIR(map[stage_num][i][j] + 1));
    }
  }
  wrefresh(snake_win);
}

void Display::addBorder(){
  box(snake_win, 0, 0);
}

void Display::add(Drawing drawing){
  addAt(drawing.getY(), drawing.getX(), drawing.getData());
}

void Display::getEmptyCoordinates(int& y, int& x){
  while((mvwinch(snake_win, y = rand() % 25, x = rand() % 25)) != 0);
}

void Display::addAt(int y, int x, int ch){
  mvwaddch(snake_win, y, x, ch);
}

chtype Display::getInput(){
  return wgetch(snake_win);
}

int Display::getCharAt(int y, int x){
  return mvwinch(snake_win, y, x);
}

void Display::refresh(){
  wrefresh(snake_win);
}

void Display::clear(){
  wclear(snake_win);
  addBorder();
}
