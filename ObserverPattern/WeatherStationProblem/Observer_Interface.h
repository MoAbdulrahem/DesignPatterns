#ifndef _Observer_h
#define _Observer_h
#include "Subject_Interface.h"

class Observer{
    virtual ~Observer() = default;
    virtual void update(double t, double h, double p) = 0;
};

#endif