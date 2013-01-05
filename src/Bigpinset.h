/*
 * Bigpinset.h
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#ifndef BIGPINSET_H_
#define BIGPINSET_H_

#include "Bigpin.h"
#include "Smallpinset.h"
#include "Logic_core.h"

namespace Logic_core
{

  // set of [num_pins] big pins
  class Bigpinset
  {
  public:
    Bigpinset();

    Bigpinset(const Bigpinset&);

    virtual
    ~Bigpinset();

    // add copy of specified pin to set
    Bigpinset&
    add(const Bigpin&);

    // create and add pin defined by color
    Bigpinset&
    add(const Bigpin::Colors&);

    Bigpin::Colors
    operator[](int) const;

    Bigpinset&
    operator=(const Bigpinset&);

    // (re)creates [num_pins] random colors
    void
    randomize();

  private:
    Bigpin* pins[num_pins];
    int have_n_pins;

    friend Smallpinset
    compare(const Bigpinset&, const Bigpinset&);

    //copy from Bigpinset to this
    void
    copy(const Bigpinset&);
  };
}

#endif /* BIGPINSET_H_ */
