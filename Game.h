#ifndef __GAME__
#define __GAME__

#include <vector>

class Snake;

class Game {
    public:
        Game(int height, int width);
        ~Game();

        void makeGate();
        void clearGate();
        bool isMakingGateNow(int n);

    private:
        Snake *snake;
};

#endif