#ifndef __SNAKE_BODY__
#define __SNAKE_BODY__

#include <vector>

enum PART {
    HEAD,
    TAIL
};

class SnakeBody {
private:
    int positionX;
    int positionY;
    PART part;

public:
    SnakeBody(int y = 10, int x = 10, PART p = HEAD);

    int getPositionX() const {
        return positionX;
    }

    int getPositionY() const {
        return positionY;
    }

    void setPositionX(int p) {
        positionX = p;
    }

    void setPositionY(int p) {
        positionY = p;
    }

    PART getPart() const {
        return part;
    }
};

class Snake {
private:
    int bodyLength;
    std::vector<SnakeBody> body;

public:
    Snake(int size = 3, int startY = 10, int startX = 10);
    SnakeBody& operator[](int idx);

    int getBodyLength() const {
        return bodyLength;
    }

    void addBody();
    void removeBody();
};

#endif
