/*
 * Smallpin.h
 *
 *  Created on: Dec 29, 2012
 *      Author: rrakus
 */

#ifndef SMALLPIN_H_
#define SMALLPIN_H_

#include <iostream>

namespace Logic_core
{

  class Smallpin
  {

  public:
    enum Colors
    {
      BLACK, WHITE
    };
    Smallpin(Colors c) :
      color(c)
    {
    }
    ;

    Smallpin(const Smallpin& s) :
      color(s.color)
    {
    }
    ;

    // return what color it has
    Colors
    get_color() const
    {
      return color;
    }

  private:
    Colors color;

    friend std::ostream& operator<< (std::ostream&, const Smallpin&);

  };

}

#endif /* SMALLPIN_H_ */
