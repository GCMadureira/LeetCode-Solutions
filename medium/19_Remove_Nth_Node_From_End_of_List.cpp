// very easy problem, should not have medium difficulty
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        for(int i = 0; i < n; ++i) current = current->next;

        // the element to remove is the first one
        if(current == nullptr) return head->next;
        current = current->next;

        ListNode* toRemove = head; // this is the element before the one to be removed
        while(current != nullptr) {
            current = current->next;
            toRemove = toRemove->next;
        }

        toRemove->next = toRemove->next->next;
        return head;
    }
};