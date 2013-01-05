/*
 * Game.h
 *
 *  Created on: Dec 31, 2012
 *      Author: rrakus
 */

#ifndef GAME_H_
#define GAME_H_

#include "Logic_core.h"
#include "Overview.h"
#include "IODevice.h"

namespace Logic
{

  // The main class of the game
  class Game
  {
  public:
    // Create a new game
    // Pass seed for random number generator
    // and your desired Device adapter (the game will destroy it)
    Game(unsigned int, IODevice*);

    virtual
    ~Game();

    // Starts the game
    // Returns true if user want to play again
    bool start();

  private:
    Logic_core::Overview *o;
    IODevice *device;
  };

}

#endif /* GAME_H_ */
