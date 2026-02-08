// another roman numbers problem, another hardcoded dictionary
// 0ms

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    inline static const unordered_map<char, int> mapping= {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int romanToInt(string& s) {
        int result = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            result += mapping.at(s[i]);
            if(mapping.at(s[i]) < mapping.at(s[i + 1])) result -= mapping.at(s[i]) * 2;
        }

        return result + mapping.at(s[s.size() - 1]);
    }
};