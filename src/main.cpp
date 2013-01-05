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

void
dump(Logic_core::Smallpinset& s)
{
  using namespace Logic_core;
  try
    {
      for (int i = 0; i < Logic_core::num_pins; i++)
        {
          switch (s[i])
            {
          case Smallpin::WHITE:
            std::cout << "WHITE ";
            break;
          case Smallpin::BLACK:
            std::cout << "BLACK ";
            break;
          default:
            std::cout << "UNKNOWN color in Smallpin ";
            break;
            }
        }
    }
  catch (Out_of_range&)
    {
      return;
    }
  return;
}

void
dump(Logic_core::Bigpinset& b)
{
  using namespace Logic_core;
  try
    {
      for (int i = 0; i < Logic_core::num_pins; i++)
        {
          switch (b[i])
            {
          case Bigpin::RED:
            std::cout << "RED ";
            break;
          case Bigpin::GREEN:
            std::cout << "GREEN ";
            break;
          case Bigpin::BLUE:
            std::cout << "BLUE ";
            break;
          case Bigpin::WHITE:
            std::cout << "WHITE ";
            break;
          case Bigpin::BLACK:
            std::cout << "BLACK ";
            break;
          case Bigpin::GREY:
            std::cout << "GREY ";
            break;
          case Bigpin::YELLOW:
            std::cout << "YELLOW ";
            break;
          case Bigpin::BROWN:
            std::cout << "BROWN ";
            break;
          default:
            std::cout << "UNKOWN color in Bigping ";
            break;
            }
        }
    }
  catch (Out_of_range&)
    {
      return;
    }
  return;
}

void
dump(Logic_core::Overview& o)
{
  using namespace Logic_core;
  try
    {
      std::cout << "You should guess this:\n";
      Bigpinset tg = o.get_to_guess();
      dump(tg);
      std::cout << "\n";
      std::cout << "You tried:\n";
      for (int i = 0; i < num_chances; i++)
        {
          BSPair *p = o[i];
          dump(p->first);
          std::cout << "--- ";
          dump(p->second);
          std::cout << "\n";
        }
    }
  catch (Out_of_range&)
    {
      return;
    }
  return;
}

int
main(int argc, char *argv[])
{
  using namespace Logic_core;
  using namespace Logic;

  int t = std::time(0);
  TerminalIO *tio = new TerminalIO();
  Game game = Game(t, tio);
  while (game.start());
  return 0;
}
