// 0ms

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string addBinary(const string& a, const string& b) {
        string result =  string(max(a.size(), b.size()) + 1, '0');
        bool carry = false;
        for(int i = 0; i < result.size(); ++i) {
            // count how many 1s we are summing
            int count = (int(a.size()) - 1 - i >= 0 ? a[a.size() - 1 - i] - '0' : 0) + (int(b.size()) - 1 - i >= 0 ? b[b.size() - 1 - i] - '0' : 0) + carry;
            carry = count > 1; // if there are more than one '1', then there is a carry over
            result[result.size() - 1 - i] += count % 2; // the current number is '1' if count is odd, is '0' otherwise
        }

        int pos = 0;
        while(pos < result.size() - 1 && result[pos] == '0') ++pos;
        return result.substr(pos, result.size() - pos);
    }
};