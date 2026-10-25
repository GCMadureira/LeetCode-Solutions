// simple linear solution using two maps (using only one is possible but more convoluted) and a sliding window approach
// 0ms

#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string& s, string& t) {
        int target['z' + 1] = {0}; // map to count the target amount of each character
        int current['z' + 1] = {0}; // map to count the current amount of each character
        for(int i = 0; i < 'z' + 1; ++i) current[i] = 100;

        int target_count = 0;
        for(char c : t) {
            if(current[c] != 0) ++target_count;
            current[c] = 0;
            target[c] += 1;
        }

        int count = 0, left = 0, right = 0, result_left = 0, result_right = INT_MAX;
        while(right < s.size()) {
            // increment the counter of the current char, the ones not included in t will never matter
            char current_char = s[right];
            if(++current[current_char] == target[current_char]) {
                ++count;
            }

            // found a solution, try to reduce the window size
            if(count == target_count) {
                while(count == target_count) {
                    if(current[s[left]]-- == target[s[left]]) {
                        --count;
                    }
                    ++left;
                }

                // check if the solution found is better than the current one
                if(right - left < result_right - result_left) {
                    result_right = right;
                    result_left = left - 1;
                }
            }

            ++right;
        }

        if(result_right == INT_MAX) {
            result_left = 0;
            result_right = -1;
        }

        return s.substr(result_left, result_right - result_left + 1);
    }
};