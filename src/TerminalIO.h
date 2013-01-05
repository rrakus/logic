/*
 * TerminalIO.h
 *
 *  Created on: Dec 31, 2012
 *      Author: rrakus
 */

#ifndef TERMINALIO_H_
#define TERMINALIO_H_

#include "IODevice.h"
#include "Overview.h"
#include "Bigpinset.h"
#include "Smallpinset.h"
#include "Bigpin.h"
#include "Smallpin.h"
#include "Logic_core.h"
#include <string>

namespace Logic
{
  using namespace Logic_core;
  class TerminalIO : public Logic::IODevice
  {
  public:
    TerminalIO();

    virtual ~TerminalIO();

    void show(const Logic_core::Overview&, bool);
    Bigpinset read();
    bool play_again();
    void win();

  private:
    void print(const BSPair*);
    void print(const Bigpinset&);
    void print(const Smallpinset&);
    void print(const Smallpin&);
    void print(const Bigpin&);
    void print_hidden();
    Bigpinset& try_add(Bigpinset&, const std::string &);
    class Not_valid_color {};
  };

}

#endif /* TERMINALIO_H_ */
