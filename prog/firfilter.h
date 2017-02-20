#ifndef FIRFILTER_H
#define FIRFILTER_H

#include <Fixed.h>
#include <fircoefs.h>
#include <deque>


class FIRFilter
{
public:
    FIRFilter();

    std::deque<FixedFP> getOutput(std::deque<FixedFP> input);

private:


//    std::deque<FixedFP> output;

};

#endif // FIRFILTER_H
