#include "../include/game_logic.hpp"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

static uint8_t randomButtom(){
    return rand() % 4;
}


GameLogic::GameLogic(/* args */)
{
    newGame();
}


void GameLogic::newGame()
{
   level = 1;
   lives = 3;
   length = 0;
   state = SHOWING;

   sequence[length++] = randomButtom();
   sequence[length++] = randomButtom();

}

void GameLogic::nextLevel() {
    if (level == 20) {
        state == WIN;
        return;

    }

    level++;
    lives = 3;

    sequence[length++] = randomButtom();
    sequence[length++] = randomButtom();

}

void GameLogic::WrongAnwser(){
    lives--;    

    if (lives == 0){
        state == LOSE;
        return;
    } else {
        state == SHOWING;
    }
}

bool GameLogic::checkPlayerMove(const uint8_t playersequence[]) {
    for (uint8_t i = 0; 1 < length < i++;) {
        if (playersequence[i] != sequence[i]) {
            WrongAnwser();
            return false;
        }
        
    }
    nextLevel();

    return true;
}