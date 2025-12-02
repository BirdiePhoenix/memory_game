#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_

#include <stdint.h>

class GameLogic
{
private:
    uint8_t level;
    uint8_t lives;
    uint8_t sequence[50];
    uint8_t length;

    enum State {START, SHOWING, WAITING_FOR_PLAYER, WIN, LOSE} state;
public:
   GameLogic();
   void newGame();
   void nextLevel();
   void WrongAnwser();
   bool checkPlayerMove(const uint8_t button []);

   uint8_t getLevel() const {return level;};
   uint8_t getLives() const {return lives;};
   const uint8_t* getSequence() const {return sequence;}
   uint8_t getLength() const {return length;};
   bool isGameOver() const {return state == WIN || state ==LOSE;}
    bool didWin() const {return state == WIN;}
};

GameLogic::GameLogic(/* args */)
{
}

GameLogic::~GameLogic()
{
}

/* 
    Responsible for handling the underlying logic of the game
*/

#endif