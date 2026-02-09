// recursive solution to explore every tree branch that represents each combination
// 0ms

#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    const char* buttons[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    int index = 0; // represents the current tree depth level
    char current[5] = {0,0,0,0,0}; // holds the current built string for each iteration
    string digits = "";
    vector<string> result = vector<string>();

    vector<string> letterCombinations(string& digits) {
        int vector_size = 1;
        for(char& c : digits) vector_size *= strlen(buttons[c - '0']);
        result.reserve(vector_size);

        this->digits = digits;
        combinations();

        return result;
    }

    void combinations() {
        // reached the end of one of the branches
        if(index == digits.size()) {
            result.push_back(string(current));
            return;
        }

        // try every possible letter on the current position
        for(int i = 0; i < strlen(buttons[digits[index] - '0']); ++i) {
            current[index++] = buttons[digits[index] - '0'][i];
            combinations();
            --index;
        }
    }
};