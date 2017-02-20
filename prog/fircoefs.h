#ifndef FIRCOEFS_H
#define FIRCOEFS_H

#include<Fixed.h>

#define FILTER_ORDER 16

typedef Fixed<1, 15> FixedFP;

const FixedFP coef_f[FILTER_ORDER]={
    0.001225308062266132,
    0.015740555692236518,
    0.029024498550312527,
    0.049774811325381078,
    0.073280437925365316,
    0.096243409038715144,
    0.11459351501547727,
    0.12480233350832041,
    0.12480233350832041,
    0.11459351501547727,
    0.096243409038715144,
    0.073280437925365316,
    0.049774811325381078,
    0.029024498550312527,
    0.015740555692236518,
    0.001225308062266132
};

#endif // FIRCOEFS_H
