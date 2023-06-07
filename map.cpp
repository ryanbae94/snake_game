#include "Game.h"

//Map Display Color Setting
void cell_color_init(){
  init_color(COLOR_GRAY, 500, 500, 500);

  init_pair(1, COLOR_GRAY, COLOR_GRAY);   //(1)Wall
  init_pair(2, COLOR_BLACK, COLOR_BLACK); //(2)Immune Wall
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW); //(3)Snake Head
  init_pair(4, COLOR_BLUE, COLOR_BLUE);   //(4)Snake Body
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA); //(5)Gate
  init_pair(6, COLOR_RED, COLOR_RED);   //(6)Poison Item
  init_pair(7, COLOR_GREEN, COLOR_GREEN); //(7)Growth Item
  init_pair(8, COLOR_WHITE, COLOR_WHITE); //(8)Blank

  init_pair(9, COLOR_GRAY, COLOR_WHITE); //End
}

//Map display = win1
void map_set(){
  for(int i = 0; i < 25; i++)
    for(int j = 0; j < 25; j++){
      int cell_color = map[stage_level][i][j];
      if(cell_color == 8) cell_color = 0;
      wattron(win1, COLOR_PAIR(cell_color));
      mvprintw(win1, i, j, "0");
      wattroff(win1, COLOR_PAIR(cell_color));
    }
  wrefresh(win1);
}

//Board 구현
