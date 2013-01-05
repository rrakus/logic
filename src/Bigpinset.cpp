/*
 * Bigpinset.cpp
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Bigpinset.h"
#include "Logic_core.h"

namespace Logic_core
{

  Bigpinset::Bigpinset()
  {
    for (int i = 0; i < num_pins; i++)
      {
        pins[i] = 0;
      }
    have_n_pins = 0;
  }

  Bigpinset::~Bigpinset()
  {
    for (int i = 0; i < num_pins; i++)
      {
        delete pins[i];
      }
  }

  Bigpinset::Bigpinset(const Bigpinset& b)
  {
    copy(b);
  }

  void
  Bigpinset::copy(const Bigpinset& b)
  {
    for (int i = 0; i < num_pins; i++)
      {
        if (i <= b.have_n_pins)
          pins[i] = new Bigpin(b.pins[i]->get_color());
        else
          pins[i] = 0;
      }
    have_n_pins = b.have_n_pins;
  }

  Bigpinset &
  Bigpinset::operator =(const Bigpinset& b)
  {
    if (this != &b)
      copy(b);
    return *this;
  }

  Bigpinset&
  Bigpinset::add(const Bigpin& b)
  {
    pins[have_n_pins++] = new Bigpin(b);
    return *this;
  }

  Bigpinset&
  Bigpinset::add(const Bigpin::Colors& c)
  {
    pins[have_n_pins++] = new Bigpin(c);
    return *this;
  }

  Bigpin::Colors
  Bigpinset::operator [](int i) const
  {
    if (i >= have_n_pins)
      throw Out_of_range();
    return pins[i]->get_color();
  }

  void
  Bigpinset::randomize()
  {
    for (int i = num_pins - 1; i >= 0; i--)
      {
        if (pins[i])
          {
            delete pins[i];
            have_n_pins--;
          }
        pins[i] = new Bigpin();
        have_n_pins++;
      }
  }

  Smallpinset
  compare(const Bigpinset& g, const Bigpinset& u)
  {
    bool gused[num_pins];
    bool uused[num_pins];
    Smallpinset s;
    // first check for blacks
    for (int i = 0; i < num_pins; i++)
      {
        gused[i] = uused[i] = false;
        if (*(u.pins[i]) == *g.pins[i])
          {
            s.add(Smallpin(Smallpin::BLACK));
            uused[i] = gused[i] = true;
          }
      }
    // now check for whites
    for (int i = 0; i < num_pins; i++)
      {
        if (uused[i])
          continue;
        for (int j = 0; j < num_pins; j++)
          {
            if (gused[j])
              continue;
            if (*(u.pins[i]) == *g.pins[j])
              {
                s.add(Smallpin(Smallpin::WHITE));
                uused[i] = gused[j] = true;
                break;
              }
          }
      }
    return s;
  }

}
