// The solution is more complex than it could be but oh well
// 0ms

#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    char format[4] = "%nd";
    char* ip;
    int ip_size;
    vector<string> res;
    int dot_pos[3];
    int layer;

    // search a tree of combinations
    void combinations() {
        int prev_dot_pos;
        if(layer == 0) prev_dot_pos = 0;
        else prev_dot_pos = dot_pos[layer - 1];

        if(layer == 3) {
            int last;

            if(sscanf(ip + prev_dot_pos, "%d", &last) == 0) return;
            if(ip_size - prev_dot_pos > 1 && ip[prev_dot_pos] == '0') return; // leading zero
            if(last < 0 || last > 255) return; // not a possible solution

            // build the string, too lazy to think of a better way
            string solution;
            for(int i = 0; i < dot_pos[0]; ++i) solution.push_back(ip[i]);
            solution.push_back('.');
            for(int i = dot_pos[0]; i < dot_pos[1]; ++i) solution.push_back(ip[i]);
            solution.push_back('.');
            for(int i = dot_pos[1]; i < dot_pos[2]; ++i) solution.push_back(ip[i]);
            solution.push_back('.');
            for(int i = dot_pos[2]; i < ip_size; ++i) solution.push_back(ip[i]);

            res.push_back(solution);
            return;
        }

        int current;
        for(int i = 1; i <= 3; ++i) {
            if(ip_size - prev_dot_pos - i < 3 - layer) break; // no solution

            format[1] = (char)('0' + i);
            if(sscanf(ip + prev_dot_pos, format, &current) == 0) break; // could not find a number
            if(i > 1 && ip[prev_dot_pos] == '0') break; // leading zero
            if(current < 0 || current > 255) break; // no solution

            dot_pos[layer] = prev_dot_pos + i;
            ++layer;
            combinations();
            --layer;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ip_size = s.size();
        char temp[ip_size + 1];
        strcpy(temp, s.c_str());
        ip = temp;
        layer = 0;
        combinations();
        return res;
    }
};