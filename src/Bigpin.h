/*
 * Bigpin.h
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#ifndef BIGPIN_H_
#define BIGPIN_H_

#include <iostream>

namespace Logic_core
{

  // Bigpin represents object which should be guessed
  class Bigpin
  {
  public:
    enum Colors
    {
      RED = 0, GREEN, BLUE, WHITE, BLACK, YELLOW, BROWN, GREY,
    };

  private:
    Colors color;

    // Make sure this is really true!
    static const int colormax = GREY;

    friend std::ostream& operator<< (std::ostream&, const Bigpin&);

  public:
    // pass desired color
    Bigpin(Colors c) :
      color(c)
    {
    }
    ;

    // create new Bigpin with random color
    Bigpin();

    Bigpin(const Bigpin& b) :
      color(b.color)
    {
    }

    const Colors
    get_color() const
    {
      return color;
    }

    // compare if colors of Bigpins are the same
    bool
    operator==(Bigpin);

  };
}

#endif /* BIGPIN_H_ */
