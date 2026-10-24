// O(n^2) solution, choose each number in turn from left to right, calculating its offset each time
// 0ms

#include <stdlib.h>

char* getPermutation(int n, int k) {
    int fact = 1;
    for(int i = 2; i < n; ++i) fact *= i;

    char used[9] = {0};
    char* result = (char*)malloc((n + 1) * sizeof(char));

    k = k - 1;
    for(int i = 0; i < n; ++i) {
        // calculate the index of the number to use, inside the unused number array
        int pos = k/fact;

        // weird simplified loop, originally I used a while and incremented inside; gets the real index of the unused number
        int index = 0;
        for(int p = pos; p != 0 || used[index]; ++index) {
            if(!used[index]) p -= 1;
        }

        used[index] = 1;
        result[i] = (index + 1) + '0';
        k -= pos*fact; // go one layer in, remove the offset used for this current layer
        fact /= (n - i - 1) ? (n - i - 1) : 1; // avoid division by 0
    }

    result[n] = 0;
    return result;
}