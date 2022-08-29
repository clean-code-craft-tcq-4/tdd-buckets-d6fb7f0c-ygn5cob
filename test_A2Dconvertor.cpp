#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "cc_battery_range.hpp"

TEST_CASE("A2D TEST_CASE 4")
{
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,0};
        int exptectedValue = 0;
        REQUIRE(A2D_arrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,1};
        int exptectedValue = 1;
        REQUIRE(A2D_arrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,1,1,1, 1,1,0,1, 0,0,0,0};
        int exptectedValue = 2000;
        REQUIRE(A2D_arrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,0};
        int exptectedValue = 4094;
        REQUIRE(A2D_arrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,1};
        int exptectedValue = 4095;
        REQUIRE(A2D_arrayToValue(a2dBitValues) == exptectedValue);
    }
}
