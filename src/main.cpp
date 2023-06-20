#include "SnakeGame.h"
using namespace std;

int main()
{
  initscr();
  refresh();
  noecho();
  curs_set(0);

  start_color();
  SnakeGame game;

  while(!game.isOver()){
    game.processInput();
    game.updateState();
    game.redraw();
  }

  getch();
  endwin();

  return 0;
}
