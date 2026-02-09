// a better solution would be to sort in place instead of allocating a ton of new space, however me lazy
// 0ms

#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int array[10000];
        int index = 0;
        for(ListNode* list : lists) {
            while(list != nullptr) {
                array[index++] = list->val;
                list = list->next;
            }
        }

        sort(array, array+index);

        ListNode* head = new ListNode(), *current = head;
        for(int i = 0; i < index; ++i) {
            current->next = new ListNode(array[i]);
            current = current->next;
        }

        return head->next;
    }
};