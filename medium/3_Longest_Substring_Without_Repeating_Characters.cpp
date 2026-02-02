// standart sliding window solution
// 0ms

#include <string>
using namespace std;

#define MAX(a, b) a < b ? b : a

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        bool present[256]; // used as a map/set for efficiency
        for(int i = 0; i < 256; ++i) present[i] = false;

        // left and right represent the sliding window
        int result = 0, left = 0, right = 0;
        for(; right < s.size(); ++right) {
            if(present[s[right]]) {
                result = MAX(result, right - left);
                while(s[left] != s[right]) present[s[left++]] = false;
                ++left;
            }
            else present[s[right]] = true;
        }

        return MAX(result, right - left);
    }
};