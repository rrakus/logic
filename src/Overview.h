/*
 * Overview.h
 *
 *  Created on: Dec 30, 2012
 *      Author: rrakus
 */

#ifndef OVERVIEW_H_
#define OVERVIEW_H_

#include "Smallpinset.h"
#include "Bigpinset.h"
#include "Logic_core.h"
#include <utility>

namespace Logic_core
{

  class Overview
  {
  public:
    // Have to start big pin set indicating what should be guessed
    Overview(const Bigpinset&);
    virtual
    ~Overview();

    Overview& add_line(const Bigpinset&, const Smallpinset&);

    Overview& add_line(const BSPair&);

    Bigpinset get_to_guess() const;

    BSPair* operator[](int) const;

  private:
    Bigpinset to_guess;
    BSPair* tries[num_chances];
    int num_lines;
  };

}

#endif /* OVERVIEW_H_ */
