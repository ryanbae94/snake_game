#include "SnakeGame.h"

int Drawing::getX(){
  return x;
}

int Drawing::getY(){
  return y;
}

int Drawing::getData(){
  return data;
}

GrowthItem::GrowthItem(int y, int x){
  this->y = y;
  this->x = x;
  this->data = 7;
}

PoisonItem::PoisonItem(int y, int x){
  this->y = y;
  this->x = x;
  this->data = 6;
}

BlankData::BlankData(int y, int x){
  this->y = y;
  this->x = x;
  this->data = 0;
}
