// Overcomplicated logic just to do everything in a single loop, at least was fun to do
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = l1; // store the result in l1
        ListNode* end;
        while(l1 != nullptr || l2 != nullptr) {
            int l2val = (l2 == nullptr ? 0 : l2->val); // if l1 is bugger than l2, keep stuffing l2 with 0s

            l1->val = (l1->val + l2val + carry)%10;
            carry = (l1->val < l2val + carry ? 1 : 0);

            // if l2 is bugger than l1, keep stuffing l1 with 0s
            if(l1->next == nullptr && l2 != nullptr && l2->next != nullptr) l1->next = new ListNode(0);
            l2 = (l2 == nullptr ? nullptr : l2->next);
            end = l1; // keep track of the end of the list
            l1 = l1->next;
        }

        if(carry == 1) end->next = new ListNode(1);
        return result;
    }
};