#include <iostream>
#include <string>
#include <vector>  
#include <map>
#include <algorithm>
#include <iterator>

#define A2D_12BitArrayToValue(nBitValues) A2D_arrayToValue(nBitValues, 12)

std::map<std::string, int> detectampRanges(std::vector<int> samples);
void printOutput();
std::vector<std::string> ampRanges(std::vector<int> samples);
int A2D_arrayToValue(const int *val, int nBits);
