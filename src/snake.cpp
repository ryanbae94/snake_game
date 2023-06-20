#include "SnakeGame.h"

void Snake::addPiece(SnakeBody piece){
  prev_pieces.push(piece);
}

void Snake::removePiece(){
  prev_pieces.pop();
}

SnakeBody Snake::tail(){
  return prev_pieces.front();
}

SnakeBody Snake::head(){
  return prev_pieces.back();
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
