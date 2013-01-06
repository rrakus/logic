/*
 * main.cpp
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Bigpinset.h"
#include "Smallpinset.h"
#include <iostream>
#include "Logic_core.h"
#include "Overview.h"
#include "Smallpin.h"
#include "Bigpin.h"
#include "TerminalIO.h"
#include "Game.h"
#include <ctime>

int
main(int argc, char *argv[])
{
  using namespace Logic_core;
  using namespace Logic;

  bool restart = true;
  while (restart)
  {
    Game game = Game(std::time(0), new TerminalIO());
    restart = game.start();
  }
  return 0;
}
