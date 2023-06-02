#include "Game.h"
#include "Snake.h"

#include <vector>
#include <iostream>

Game::Game(int height, int width) {
    snake = new Snake(3, 10, 10);
}

Game::~Game() {
    delete snake;
}

void Game::makeGate() {
}

void Game::clearGate() {
}

bool Game::isMakingGateNow(int n) {
}

