/*
 * Smallpin.cpp
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Smallpin.h"
#include <iostream>
#include <string>

namespace Logic_core
{
  std::ostream& operator<< (std::ostream& os, const Smallpin& b)
  {
    std::string out;
    switch (b.get_color())
    {
      case Smallpin::BLACK: out = "BLACK "; break;
      case Smallpin::WHITE: out = "WHITE "; break;
    }
    return os << out;
  }


}
