// once again, STL has a stupid amount of optimization
// 0ms

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string& haystack, string& needle) {
        return haystack.find(needle);
    }
};


/*
// First solution, is O(n * m)
// 54ms
class Solution {
public:
    int strStr(string& haystack, string& needle) {
        for(int hs_index = 0; hs_index < haystack.size(); ++hs_index) {
            if(haystack[hs_index] == needle[0]) {
                int match = 1;
                for(; match < needle.size(); ++match) if(haystack[hs_index + match] != needle[match]) break;
                

                if(match == needle.size()) return hs_index;
            }
        }

        return -1;
    }
};
*/

/*
// Second solution, attempt at optimization, but apparently the extra branches created
// due to the added if statement mess branch prediction on the CPU and the misses actually
// make it a worse solution. Additionally, since the acceses to haystack are not linear anymore, it also
// messes up caching prediction, adding more time penalties.
// 109ms
class Solution {
public:
    int strStr(string& haystack, string& needle) {
        int match = 1, next_hs = INT_MAX;
        for(int hs_index = 0; hs_index < haystack.size(); ++hs_index) {
            if(haystack[hs_index] == needle[0]) {
                match = 1; next_hs = INT_MAX;
                for(; match < needle.size(); ++match) {
                    if(haystack[hs_index + match] == needle[0]) next_hs = min(hs_index + match, next_hs);
                    if(haystack[hs_index + match] != needle[match]) break;
                }

                if(match == needle.size()) return hs_index;

                if(next_hs == INT_MAX) hs_index += match;
                else hs_index = next_hs - 1;
            }
        }

        return -1;
    }
};
*/

/*
// Third attempt using the C++ STL. Apparently the people who created it were real geniuses huh...
// Even creating substrings and comparing them is more efficient than the other attempts due to
// direct memory comparison, SSO, no new string allocation but a view, etc...
// 24ms
class Solution {
public:
    int strStr(string& haystack, string& needle) {
        for(int hs_index = 0; hs_index < haystack.size(); ++hs_index) {
            if(haystack.substr(hs_index, needle.size()) == needle)
                return hs_index;
        }

        return -1;
    }
};
*/