// Iterate thorugh the digits in reverse storing the carry like a ripple adder
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int leading = 0;
        ++digits[digits.size() - 1];
        for(int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += leading;
            if(digits[i] < 10) 
                return digits;
            else {
                digits[i] = digits[i]%10;
                leading = 1;
            }
        }

        if(leading == 1)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};