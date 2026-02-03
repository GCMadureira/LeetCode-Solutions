// simple O(n) solution
// 0ms

#include <string>
using namespace std;

class Solution {
public:
    string convert(string& s, int numRows) {
        if(numRows == 1) return s;

        string result;
        result.reserve(s.size());
        const int zigZagSize = numRows*2 - 2;

        // the first row
        for(int i = 0; i < s.size(); i += zigZagSize) result.push_back(s[i]);

        // the middle rows
        for(int outter = 1; outter < numRows - 1; ++outter) {
            for(int i = outter; i < s.size(); i += zigZagSize) {
                result.push_back(s[i]); // first character in row=outter for this zig zag
                if(i + zigZagSize - 2*outter < s.size()) result.push_back(s[i + zigZagSize - 2*outter]); // second character
            }
        }

        // the last row
        for(int i = numRows - 1; i < s.size(); i += zigZagSize) result.push_back(s[i]);

        return result;
    }
};