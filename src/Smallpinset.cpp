/*
 * Smallpinset.cpp
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Smallpinset.h"

namespace Logic_core
{

  Smallpinset::Smallpinset()
  {
    for (int i = 0; i < num_pins; i++)
      {
        pins[i] = 0;
        have_n_set = 0;
      }

  }

  Smallpinset::Smallpinset(const Smallpinset& f)
  {
    for (int i = 0; i < num_pins; i++)
      {
        if (i < f.have_n_set)
          pins[i] = new Smallpin(f.pins[i]->get_color());
        else
          pins[i] = 0;
      }
    have_n_set = f.have_n_set;
  }

  Smallpinset::~Smallpinset()
  {
    for (int i = 0; i < num_pins; i++)
      {
        delete pins[i];
      }
  }

  Smallpinset&
  Smallpinset::add(const Smallpin& s)
  {
    pins[have_n_set++] = new Smallpin(s);
    return *this;
  }

  Smallpin::Colors
  Smallpinset::operator[](int i) const
  {
    if (i >= have_n_set)
      throw Out_of_range();
    return pins[i]->get_color();
  }

  bool all_correct(const Smallpinset& s)
  {
    try
    {
      for (int i = 0; i < num_pins; i++)
      {
        if (s[i] != Smallpin::BLACK) return false;
      }
    }
    catch (Out_of_range& oor)
    {
      return false;
    }
    return true;
  }
}
