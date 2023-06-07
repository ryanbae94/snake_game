#ifndef __GAME__
#define __GAME__

#include <vector>
#include "map_displayList.h"

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

//Display::map function
void cell_color_init(); //화면 구성용 Cell Color 지정
void map_set();         //Map 출력력

#endif
