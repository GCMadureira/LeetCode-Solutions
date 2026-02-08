// laziest solution possible
// 0ms

#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    inline static const unordered_map<int, char*> mapping = {
        {3000, "MMM"},
        {2000, "MM"},
        {1000, "M"},
        {900, "CM"},
        {800, "DCCC"},
        {700, "DCC"},
        {600, "DC"},
        {500, "D"},
        {400, "CD"},
        {300, "CCC"},
        {200, "CC"},
        {100, "C"},
        {90, "XC"},
        {80, "LXXX"},
        {70, "LXX"},
        {60, "LX"},
        {50, "L"},
        {40, "XL"},
        {30, "XXX"},
        {20, "XX"},
        {10, "X"},
        {9, "IX"},
        {8, "VIII"},
        {7, "VII"},
        {6, "VI"},
        {5, "V"},
        {4, "IV"},
        {3, "III"},
        {2, "II"},
        {1, "I"},
    };

    string intToRoman(int num) {
        string result;
        result.reserve(15);

        int divisor = pow(10, int(log10(num)));
        while(num > 0) {
            int value = (num/divisor)*divisor;
            divisor /= 10;
            if(value == 0) continue;
            result.append(mapping.at(value));
            num -= value;
        }

        return result;
    }
};