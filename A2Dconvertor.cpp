#include "cc_battery_range.hpp"

int A2D_arrayToValue(const int *val, int nBits)
{
    int dval = 0;
    for (int i = 0; i < nBits; ++i)
    {
        dval <<= 1;
        if (val[i] != 0)
        {
            dval += 1;
        }
    }
    return dval;
}
