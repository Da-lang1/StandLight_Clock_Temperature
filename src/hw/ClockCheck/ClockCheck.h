#ifndef CLCOKCHECK_H
#define CLCOKCHECK_H

#include "time.h"

#pragma once

class ClockCheck
{
private:
    time_t prevSec;

public:
    ClockCheck();
    virtual ~ClockCheck();
    bool isUpdate();

};

#endif