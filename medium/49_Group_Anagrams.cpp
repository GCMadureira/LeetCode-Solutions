// Sort each string and store the sorted value as the key to the vector of anagrams
// 6ms


#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;

        for(string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(s);
        }

        vector<vector<string>> res;
        for(auto itr = anagrams.begin(); itr != anagrams.end(); ++itr) {
            res.push_back(move(itr->second));
        }

        return res;
    }
};