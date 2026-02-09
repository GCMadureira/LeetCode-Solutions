// decently elegant solution if I do say so myself
// 0ms

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* lastPair = new ListNode(0, head);
        ListNode* nextPair = head;
        head = lastPair;

        while(nextPair != nullptr && nextPair->next != nullptr) {
            lastPair->next = nextPair->next;
            nextPair->next = nextPair->next->next;
            lastPair->next->next = nextPair;

            lastPair = nextPair;
            nextPair = nextPair->next;
        }

        return head->next;
    }
};