#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "cc_battery_range.hpp"

TEST_CASE("TEST_CASE 1") {
  std::vector<int> samples{3, 3, 4, 5, 10, 11, 12};
  auto objectofranges = ampRanges(samples);
  REQUIRE(objectofranges.size() == 2);
  REQUIRE(objectofranges[0] == "10-12, 3");
  REQUIRE(objectofranges[1] == "3-5, 4");
}

TEST_CASE("TEST_CASE 2") {
  std::vector<int> samples{1,2,4,3};
  auto objectofranges = ampRanges(samples);
  REQUIRE(objectofranges.size() == 1);
  REQUIRE(objectofranges[0] == "1-4, 4");
}

TEST_CASE("TEST_CASE 3") {
    std::vector<int> samples {1,3,4,2,6,7,9,8,12,11,13};
    auto objectofranges = ampRanges(samples);
    REQUIRE(objectofranges.size() == 3);
    REQUIRE(objectofranges[0] == "1-4, 4");
    REQUIRE(objectofranges[2] == "6-9, 4");
    REQUIRE(objectofranges[1] == "11-13, 3");
}

TEST_CASE("TEST_CASE 4") {
    std::vector<int> samples {1,1,1,1,1,1};
    auto objectofranges = ampRanges(samples);
    REQUIRE(objectofranges.size() == 1);
    REQUIRE(objectofranges[0] == "1-1, 6");
}

TEST_CASE("A2D TEST_CASE 5")
{
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,0};
        int exptectedValue = 0;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,1};
        int exptectedValue = 1;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,1,1,1, 1,1,0,1, 0,0,0,0};
        int exptectedValue = 2000;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,0};
        int exptectedValue = 4094;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,1};
        int exptectedValue = 4095;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
}
