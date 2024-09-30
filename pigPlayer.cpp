//
// Created by thetr on 9/18/2024.
//

#include "pigPlayer.h"
#include <iostream>

void pigPlayer::stop() {
    gameTotal += turnTotal;
    dieValue = 0;
    turnTotal = 0;
}

void pigPlayer::roll() {
    dieValue = rand() % 6 + 1;
    turnTotal += dieValue;
}

void pigPlayer::resetTurnTotal() {
    turnTotal = 0;
}

int pigPlayer::getDieValue() {
    return dieValue;
}

int pigPlayer::getTurnTotal() {
    return turnTotal;
}

int pigPlayer::getTotal() {
    return gameTotal;
}
