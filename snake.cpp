#include "Snake.h"

SnakeBody::SnakeBody(int y, int x, PART p) : positionY(y), positionX(x), part(p) {}

Snake::Snake(int size, int startY, int startX) : bodyLength(size) {
    for (int i = 0; i < size; i++) {
        SnakeBody s;
        if (i == 0) {
            s = SnakeBody(startY, startX, HEAD);
        }
        else {
            s = SnakeBody(startY, ++startX, TAIL);
        }
        body.push_back(s);
    }
}

void Snake::addBody() {
    int y = body[bodyLength - 1].getPositionY();
    int x = body[bodyLength - 1].getPositionX();
    SnakeBody b(y, x, TAIL);
    body.push_back(b);
    bodyLength++;
}

void Snake::removeBody() {
    bodyLength--;
    body.pop_back();
}

SnakeBody& Snake::operator[](int index) {
    return body[index];
}