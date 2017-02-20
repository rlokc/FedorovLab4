#include <fixedfloat.h>
#include <qdebug.h>

FixedFloat::FixedFloat(float number)
{
    if ((int) number != 0) qDebug() << "Trying to make a 1.15 with nonzero integer part";
}
