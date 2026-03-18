// half cheating to get a lower time (I did not even think about using XOR somehow)
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bool hashmap[60001] = {false};
        for(int num : nums) {
            hashmap[num + 30000] = !hashmap[num + 30000];
        }
        
        for(int num : nums) {
            if(hashmap[num + 30000]) return num;
        }

        return -1;
    }
};