#include "SnakeGame.h"

SnakeBody::SnakeBody(){
  this->x = this->y = 0;
  this->data = 4;
}

SnakeBody::SnakeBody(int y, int x){
  this->x = x;
  this->y = y;
  this->data = 4;
}

Snake::Snake(){
  cur_direction = down;
}

void Snake::addBody(SnakeBody body){
  prev_bodies.push(body);
}

void Snake::removeBody(){
  prev_bodies.pop();
}

SnakeBody Snake::tail(){
  return prev_bodies.front();
}

SnakeBody Snake::head(){
  return prev_bodies.back();
}

Direction Snake::getDirection(){
  return cur_direction;
}

void Snake::setDirection(Direction d){
  if(cur_direction + d != 0)
    cur_direction = d;
}

SnakeBody Snake::nextHead(){
  int row = head().getY();
  int col = head().getX();

  switch (cur_direction) {
    case down:
      row++;
      break;
    case up:
      row--;
      break;
    case left:
      col--;
      break;
    case right:
      col++;
      break;
  }

  return SnakeBody(row, col);
}
