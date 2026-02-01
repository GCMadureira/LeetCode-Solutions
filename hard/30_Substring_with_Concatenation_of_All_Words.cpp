// I am not even going to bother understanding past me, good job solving a hard one
// 0ms

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        vector<int> res;
        int wordSize = words[0].size();

        if(s.size() < words.size() * wordSize) return res;

        unordered_map<string_view, pair<int,int>> currentMap; //word -> (maxNum, curNum)
        for(string temp : words) {
            string_view tempSV = string_view(temp);
            if(currentMap.contains(tempSV)) ++currentMap[tempSV].first;
            else currentMap[tempSV] = pair<int,int>({1,0});
        }

        for(int z = 0; z < wordSize; ++z) {
            int currentWords = 0; //number of words present in the current window
            unordered_set<string_view> extraWords;
            for(int i = z; i < words.size() * wordSize + z; i += wordSize) {
                string_view tempWord = s.substr(i, wordSize);
                if(currentMap.contains(tempWord)) {
                    ++currentWords;
                    ++currentMap[tempWord].second;
                    if(currentMap[tempWord].second == currentMap[tempWord].first + 1)
                        extraWords.insert(tempWord);
                }
            }

            // i < s.size()/wordSize  -       words.size()       +        1
            //     num of words in s    words occupied at i = 0    initial position 
            for(int i = z; i < s.size() - words.size()*wordSize + wordSize; i += wordSize) {
                //std::cout << i << " " << currentWords << " " << extraWords.size() << "\n";

                if(currentWords == words.size() && extraWords.empty()) res.push_back(i); //add the solution

                string tempWord = s.substr(i, wordSize);
                if(currentMap.contains(tempWord)) {
                    --currentWords;
                    --currentMap[tempWord].second;
                    if(currentMap[tempWord].second == currentMap[tempWord].first)
                        extraWords.erase(tempWord);
                }

                if(i + words.size() * wordSize + wordSize > s.size()) break;

                string newWord = s.substr(i + words.size() * wordSize, wordSize);
                if(currentMap.contains(newWord)) {
                    ++currentWords;
                    ++currentMap[newWord].second;
                    if(currentMap[newWord].second == currentMap[newWord].first + 1)
                        extraWords.insert(newWord);
                }
            }

            for(auto itr = currentMap.begin(); itr != currentMap.end(); itr++) {
                (*itr).second.second = 0;
            }

        }

        return res;
    }
};