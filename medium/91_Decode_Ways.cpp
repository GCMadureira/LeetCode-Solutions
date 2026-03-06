// if you know how many combinations there are in a string, when you prepend a new digit you can infer in constant time how many combinations the change creates
// 0ms

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string& s) {
        if(s.empty() || s[0] == '0') return 0;

        int res = s[s.size() - 1] != '0', before = 1, current;
        for(int i = s.size() - 2; i >= 0; --i) {
            if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                current = res + before;
            else if (s[i] == '0')
                current = 0;
            else
                current = res;
            
            before = res;
            res = current;
        }

        return res;
    }
};