#include "SnakeGame.h"

SnakeGame::SnakeGame(){
    init();
}

void SnakeGame::init(){
    display.init();
    display.init_coloring();
    display.coloring(stage_count);
    game_over = false;
}

void SnakeGame::updateState(){
  
}

void SnakeGame::redraw(){
  display.refresh();
}

bool SnakeGame::isOver(){
  return game_over;
}

int SnakeGame::getStageCount(){
  return stage_count;
}
