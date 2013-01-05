/*
 * Smallpinset.h
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#include "Smallpin.h"
#include "Logic_core.h"

#ifndef SMALLPINSET_H_
#define SMALLPINSET_H_

namespace Logic_core
{

  class Smallpinset
  {
  public:
    Smallpinset();
    virtual
    ~Smallpinset();

    Smallpinset(const Smallpinset&);

    // Add smallpin to this set
    Smallpinset&
    add(const Smallpin&);

    // get color in the set
    Smallpin::Colors
    operator [](int) const;

  private:
    Smallpin* pins[num_pins];
    int have_n_set;

  };

}

#endif /* SMALLPINSET_H_ */
