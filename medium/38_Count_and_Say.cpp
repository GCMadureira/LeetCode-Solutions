// iterative solution focusing on efficiency, not cleanliness
// 0ms

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        char _array1[5000], _array2[5000];
        char* array1 = _array1, *array2 = _array2; // use pointers instead so we can swap them later
        array1[0] = '1'; array1[1] = 0;
        for(int i = 1; i < n; ++i) {
            // rle encode the contents in array1 into array2
            int index2 = 0, current = array1[0], count = 1;
            for(int index1 = 1; array1[index1]; ++index1) {
                if(array1[index1] == current) ++count;
                else {
                    string num = to_string(count);
                    for(char c : num) array2[index2++] = c;

                    array2[index2++] = current;
                    current = array1[index1];
                    count = 1;
                }
            }

            string num = to_string(count);
            for(char c : num) array2[index2++] = c;

            array2[index2++] = current;
            array2[index2] = 0;

            // invert the array pointers
            char* temp = array1;
            array1 = array2;
            array2 = temp;
        }

        return string(array1);
    }
};