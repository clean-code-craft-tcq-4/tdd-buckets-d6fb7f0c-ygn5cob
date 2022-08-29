#include "cc_battery_range.hpp"

int A2D_arrayToValue(const int val[12])
{
    int dval = 0;
    for (int i = 0; i < 12; ++i)
    {
        dval <<= 1;
        if (val[i] != 0)
        {
            dval += 1;
        }
    }
    return dval;
}
