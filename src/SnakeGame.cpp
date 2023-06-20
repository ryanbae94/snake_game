#include "SnakeGame.h"

void SnakeGame::handleNextBody(SnakeBody next){
  if(growthItem != NULL){
    switch (display.getCharAt(next.getY(), next.getX())) {
      case 7:
        getGrowth();
        break;
      case 0:{
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        display.add(BlankData(emptyRow, emptyCol));
        snake.removeBody();
        break;
      }
    }
  }

  if(poisonItem != NULL){
    switch (display.getCharAt(next.getY(), next.getX())) {
      case 7:
        getPoison();
        break;
      case 0:{
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        display.add(BlankData(emptyRow, emptyCol));
        snake.removeBody();
        break;
      }
    }
  }

  display.add(next);
  snake.addBody(next);
}

void SnakeGame::createGrowth(){
  int x, y;
  display.getEmptyCoordinates(y, x);
  growthItem = new GrowthItem(y, x);
  display.add(*growthItem);
}

void SnakeGame::getGrowth(){
  delete growthItem;
  growthItem = NULL;
}

void SnakeGame::createPoison(){
  int x, y;
  display.getEmptyCoordinates(y, x);
  poisonItem = new PoisonItem(y, x);
  display.add(*poisonItem);
}

void SnakeGame::getPoison(){
  delete poisonItem;
  poisonItem = NULL;
}

SnakeGame::SnakeGame(){
  init();
}

SnakeGame::~SnakeGame(){
  delete growthItem;
  delete poisonItem;
}

void SnakeGame::init(){
  growthItem = NULL;
  poisonItem = NULL;
  display.init();
  display.init_coloring();
  display.coloring(stage_count);
  game_over = false;
  srand(time(NULL));
  snake.setDirection(down);

  handleNextBody(SnakeBody(1, 1));
  handleNextBody(snake.nextHead());
  handleNextBody(snake.nextHead());
  handleNextBody(snake.nextHead());

  if(growthItem == NULL)
    createGrowth();
  if(poisonItem == NULL)
    createPoison();
}

void SnakeGame::processInput(){
  int input = display.getInput();
  switch (input) {
    case KEY_UP:
      snake.setDirection(up);
      break;
    case KEY_DOWN:
      snake.setDirection(down);
      break;
    case KEY_RIGHT:
      snake.setDirection(right);
      break;
    case KEY_LEFT:
      snake.setDirection(left);
      break;
    default:
      break;
  }
}

void SnakeGame::updateState(){
  handleNextBody(snake.nextHead());
}

void SnakeGame::redraw(){
  display.refresh();

  if(growthItem == NULL)
    createGrowth();
  if(poisonItem == NULL)
    createPoison();
}

bool SnakeGame::isOver(){
  return game_over;
}

int SnakeGame::getStageCount(){
  return stage_count;
}
