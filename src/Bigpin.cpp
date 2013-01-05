/*
 * Bigpin.cpp
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Bigpin.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

namespace Logic_core
{

  Bigpin::Bigpin()
  {
    color = Colors(std::rand() % colormax);
  }

  bool
  Bigpin::operator ==(Bigpin b)
  {

    return color == b.color;
  }

  std::ostream& operator<< (std::ostream& os, const Bigpin& b)
  {
    std::string out;
    switch (b.get_color())
    {
      case Bigpin::RED: out = "RED "; break;
      case Bigpin::GREEN: out = "GREEN "; break;
      case Bigpin::BLUE: out = "BLUE "; break;
      case Bigpin::BLACK: out = "BLACK "; break;
      case Bigpin::BROWN: out = "BROWN "; break;
      case Bigpin::WHITE: out = "WHITE "; break;
      case Bigpin::GREY: out = "GREY "; break;
      case Bigpin::YELLOW: out = "YELLOW "; break;
    }
    return os << std::setw(7) << out;
  }

}
