/*
I cant even explain how I arrived at this solution...
The currentCandy is the candy the last child currently has, the totalCandy keeps track of the result, 
cascading and lastBig are for later. At any step while iterating through the array, if the rating of the 
current child is more than the one before, then the child needs to get one more candy (currentCandy + 1, the first if statement).
If it is equal to the one before, then it does not matter how many candies the previous child has, we more or less enter a new section
of the array. Therefore, we can assign it 1 candy, which is the minimum. However the problem gets complicated if the rating of
the current child is less than the previous one. In this situation, the best case scenario for us is to assign 1 candy to them, feasible if
the previous child has more than one candy. However, if they have only one candy, then we need to assign one candy to the current child and
also assign one additional candy to the previous child. This additional candy assignment can cascade, which justifies the existance of
the cascading variable. Imagine the following situation:

[1,2,3,1,0], the solution is 9

Using the incomplete algorithm I defined above, we assign a candy to the first child, then, since the rating of the second child is higher,
we assign 1 + 1 = 2 candies to the second child. It follows that we need to assign 3 candies to the third child (2 + 1). Afterwards, since the
next child has a lower rating, we can assing only a single candy to them. The current totalCandy would be 7 and the currentCandy would be 1.
However, the next child has an even lower rating, so we should assign them 1 candy. That would however break the rules of the problem since this
child would have the same exact amount of candies as the last one which had higher rating. Therefore we need to assign one additional candy
to the last child. The current candy distribution would then be [1,2,3,2,1], which is the correct solution. 

We did miss a very important detail though. The cascading of candies might be larger than just increasing the last child's candy count. Imagine
the slightly modified situation:

[1,2,2,1,0], the solution is also 9

Following the same logic, we have a candy distribution like [1,2,1,....]. When reaching the fourth child, we have to cascade like we did before, so
we get [1,2,2,1...]. However, this time, when we reach the fifth child, we have to cascade again, since currentCandy=1 and the rating is lower.
So we would get [1,2,2,2,1]. This breaks the rules since the third child has a higher rating than the fourth one, but right now they have the
same candy amount. The solution is to keep cascading the +1 candy addition to the third child and not only the fourth, getting [1,2,3,2,1],
the correct solution. Hence, cascading needs to be done if the currentCandy=1 and the previous child has higher rating (meaning we need to 
assign 1 candy to this one), and we also need to cascade as long as the rating is strictly higher in contiguous previous children. The
cascading variable keeps track of how many continuous decreases in rating there have been, reseting if the rating increases or stays the same.

However, going back to the first problem:

[1,2,3,1,0]

If we cascade when we reach the fifth child following the previously established rule, we will cascade +1 candy to the fourth child (correct) and
also cascade +1 candy to the third child (incorrect). This incorrect cascading happens because, while the third child is part of the continuous
decreases I explained before, it already has a high value (3) of candies due to the children that came before (the first and second), and so
it needs no cascading. To prevent these uncessary cascadings, the lastBig variable keeps track of amount of candies of the last child whose rating
is a local maximum in the array. That is, if that child is in index i, array[i - 1] < array[i] and array[i + 1] < array[i]. If this local maximum
is already bigger than the cascading amount, then this local maximum child does not need additional candy. With the help of the descending
variable, we can easily keep track of the last local maximum.

Concluding, the first if statement deals with increases in rating, the second one deals with cascading, and the third one deals with everything
else, which is just assigning the minimum amount of candies possible to the current child (1 candy).
*/

// I cant even explain how I arrived at this solution... (I tried above so I do not forget) but it is O(n) time complexity and O(1) space complexity
// also chat gpt says there is a slope method are it is so much more readable than what I did and the logic is the same...
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int currentCandy = 1, totalCandy = 1, cascading = 0, lastBig = 0;
        bool descending = false;
        for(int i = 1; i < ratings.size(); ++i) {
            cascading = (cascading + 1)*(ratings[i] < ratings[i - 1]);
            lastBig = (ratings[i] < ratings[i - 1] && !descending ? currentCandy : lastBig);
            descending = (ratings[i] < ratings[i - 1]);

            if(ratings[i] > ratings[i - 1]) totalCandy += ++currentCandy;
            else if(ratings[i] < ratings[i - 1] && currentCandy == 1) totalCandy += cascading + (lastBig > cascading ? 0 : 1);
            else {
                ++totalCandy;
                currentCandy = 1;
            }
        }

        return totalCandy;
    }
};