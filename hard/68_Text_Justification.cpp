// O(n) solution considering only the ammount of strings, each one is processed only twice
// 0ms

#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int letterCount = 0;
        for(string& s : words) letterCount += s.size();

        vector<string> res; // reserve more space than needed because why not
        res.reserve(letterCount * 2 / maxWidth);
        
        // index of the first word of the line, 1 after the last word of the line, and the line on the vector respectively
        int lineStart = 0, lineEnd = 0, line = 0;
        letterCount = 0; // maintain a count of how many letters we have filled the current line with
        for(; lineEnd < words.size(); ++lineEnd) {
            // when the next work does not fit in the current line
            if(letterCount + words[lineEnd].size() > maxWidth) {
                int spaces = maxWidth - letterCount + lineEnd - lineStart; // how many spaces the line has
                string tempLine;
                tempLine.reserve(maxWidth);

                for(int i = lineStart; i < lineEnd; ++i) {
                    // weird math that I came up with
                    int currentSpaces = lineEnd - i > 1 ? ceil(spaces/(float)(lineEnd - i - 1)) : spaces;
                    tempLine.append(words[i]);
                    tempLine.append(currentSpaces, ' ');
                    spaces -= currentSpaces;
                }
                
                res.emplace_back(tempLine);
                lineStart = lineEnd;
                letterCount = words[lineEnd].size() + 1;
                ++line;
            } // else the word fits in the current line (+1 for the space)
            else letterCount += words[lineEnd].size() + 1;
        }

        // last line to be inserted, must be left justified
        if(lineEnd != lineStart) {
            int spaces = maxWidth - letterCount + lineEnd - lineStart;
            string tempLine;
            tempLine.reserve(maxWidth);

            for(int i = lineStart; i < lineEnd; ++i) {
                tempLine.append(words[i]);
                tempLine.append(spaces > 0, ' ');
                spaces -= 1;
            }
            tempLine.append(max(0, spaces), ' ');
            res.emplace_back(tempLine);
        }

        return res;
    }
};