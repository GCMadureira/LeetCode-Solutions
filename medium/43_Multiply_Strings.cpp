// not my best solution, it is pretty bad
// 11ms

#include <string>
using namespace std;

// assumes num1 always has space
void sum(string& num1, const string& num2) {
    int index1 = num1.size() - 1, index2 = num2.size() - 1, carry = 0;
    while(index2 >= 0) {
        num1[index1] += num2[index2] - '0' + carry;
        if(num1[index1] > '9') {
            num1[index1] -= 10;
            carry = 1;
        }
        else carry = 0;

        --index1; --index2;
    }

    while(carry == 1) {
        num1[index1] += 1;
        if(num1[index1] > '9') num1[index1] -= 10;
        else carry = 0;
    }
}

class Solution {
public:
    string multiply(string& num1, string& num2) {
        string res = string(num1.size() + num2.size(), '0');

        int value1 = 0, value2 = 0;
        for(char c : num1) value1 += c - '0';
        for(char c : num2) value2 += c - '0';
        if(value2 < value1) {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }

        num2.reserve(num2.size() + num1.size());

        for(int i = num1.size() - 1; i >= 0; --i) {
            for(int j = 0; j < num1[i] - '0'; ++j) sum(res, num2);
            num2.push_back('0');
        }

        int pos = 0;
        for(; pos < res.size() - 1; ++pos) if(res[pos] != '0') break;

        return res.substr(pos, res.size() - pos);
    }
};