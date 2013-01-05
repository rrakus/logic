/*
 * Game.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: rrakus
 */

#include "Game.h"
#include "Bigpinset.h"
#include "Overview.h"
#include <cstdlib>
#include "Logic_core.h"

namespace Logic
{
  Game::Game(unsigned int s, IODevice* d) : device(d)
  {
    using namespace Logic_core;
    std::srand(s);
    Bigpinset b;
    b.randomize();
    o = new Overview(b);
  }

  bool Game::start()
  {
    using namespace Logic_core;
    device->show(*o, false);
    for (int i = 0; i < num_chances; i++)
    {
      Bigpinset btry = device->read();
      Smallpinset sps = compare(btry, o->get_to_guess());
      o->add_line(btry, sps);
      if (all_correct(sps))
      {
        device->show(*o, true);
        device->win();
        return device->play_again();
      }
      device->show(*o, false);
    }
    device->show(*o, true);
    return device->play_again();
  }

  Game::~Game()
  {
    delete o;
    delete device;
  }
}
