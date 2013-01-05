/*
 * IODevice.h
 *
 *  Created on: Dec 31, 2012
 *      Author: rrakus
 */

#ifndef IODEVICE_H_
#define IODEVICE_H_

#include "Overview.h"
#include "Bigpinset.h"

namespace Logic
{

  class IODevice
  {
  public:
    virtual ~IODevice() {};
    virtual void show(const Logic_core::Overview&, bool) = 0;
    virtual Logic_core::Bigpinset read() = 0;
    virtual bool play_again() = 0;
    virtual void win() = 0;
  };

}

#endif /* IODEVICE_H_ */
