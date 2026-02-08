// simple solution
// 0ms

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return string();

        string& example = strs[0];
        int size = 0;
        
        bool flag = true;
        while(size < example.size()) {
            for(int i = 1; i < strs.size(); ++i) {
                if(size >= strs[i].size() || example[size] != strs[i][size]) {
                    goto end;
                }
            }

            ++size;
        }

        end:
        return example.substr(0, size);
    }
};