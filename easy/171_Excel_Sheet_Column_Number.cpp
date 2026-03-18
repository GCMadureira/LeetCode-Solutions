// unecessary offset logic but I am too tired to code well
// 0ms
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(const string& columnTitle) {
        int result = 0;
        long offset = 1;
        for(int i = columnTitle.size() - 1; i >= 0; --i) {
            result += (columnTitle[i] - 'A' + 1)*offset;
            offset *= 26;
        }

        return result;
    }
};