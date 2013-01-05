/*
 * Overview.cpp
 *
 *  Created on: Dec 30, 2012
 *      Author: rrakus
 */

#include "Overview.h"

namespace Logic_core
{

  Overview::Overview(const Bigpinset& b)
  {
    to_guess = b;
    num_lines = 0;
    for (int i = 0; i < num_chances; i++)
      {
        tries[i] = 0;
      }
  }

  Overview::~Overview()
  {
    for (int i = 0; i < num_chances; i++)
      {
        delete tries[i];
      }
  }

  Overview&
  Overview::add_line(const BSPair& p)
  {
    BSPair *np = new BSPair();
    np->first = p.first;
    np->second = p.second;
    tries[num_lines++] = np;
    return *this;
  }

  Overview&
  Overview::add_line(const Bigpinset& b, const Smallpinset& s)
  {
    tries[num_lines++] = new BSPair(b, s);
    return *this;
  }

  Bigpinset Overview::get_to_guess() const
  {
    return to_guess;
  }

  BSPair *
  Overview::operator [](int i) const
  {
    if (i >= num_lines)
      throw Out_of_range();
    return tries[i];
  }
}
