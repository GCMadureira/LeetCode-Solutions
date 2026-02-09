// standard tree branch exploration, at any decision point, you can close or open a parenthese
// 0ms

#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    // as always, defining the recursion variables here prevents unnecessary stack allocation (it is not clean though)
    int n = 0;
    int closed = 0;
    int open = 0;
    char current[17] = {0};
    int index = 0;
    vector<string> result = vector<string>();

    vector<string> generateParenthesis(int n) {
        this->n = n;
        result.reserve(pow(2, n)); // more than enough space but I am too tired to calculate the exact ammount needed
        combinations();
        return result;
    }

    void combinations() {
        // reached the end of a branch
        if(index == n*2) {
            result.push_back(current);
            return;
        }

        // try to open
        if(open < n) {
            ++open;
            current[index++] = '(';
            combinations();
            --open; --index;
        }

        //try to close
        if(closed < open) {
            ++closed;
            current[index++] = ')';
            combinations();
            --closed; --index;
        }
    }
};