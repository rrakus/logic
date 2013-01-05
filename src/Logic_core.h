/*
 * Logic_core.h
 *
 *  Created on: Dec 30, 2012
 *      Author: rrakus
 */

#ifndef LOGIC_CORE_H_
#define LOGIC_CORE_H_

#include <utility>
#include <iostream>

namespace Logic_core
{
  // There are 5 pins to guess
  const int num_pins = 5;

  // There are 10 chances to win
  const int num_chances = 10;

  // compare two sets, result stored in Smallpinset
  // first argument is generated set
  // second argument is user defined set
  class Smallpinset compare(const class Bigpinset&, const class Bigpinset&);

  // Return true if all are blacks
  bool all_correct(const class Smallpinset&);


  // send to ostream color name
  std::ostream& operator<< (std::ostream&, const class Bigpin&);

  std::ostream& operator<< (std::ostream&, const class Smallpin&);

  class Out_of_range
  {

  };

  typedef std::pair<Bigpinset, Smallpinset> BSPair;
}

#endif /* LOGIC_CORE_H_ */
