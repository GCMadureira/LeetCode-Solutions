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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        // get the node beofre the first inverted one
        ListNode* start = new ListNode(0, head);
        for(int i = 1; i < left; ++i) start = start->next;

        // at every iteration invert the direction of current -> after to after -> current
        ListNode* before = start, *current = before->next, *after = current->next;
        for(int i = left; i < right; ++i) {
            before = current;
            current = after;
            after = after->next;
            current->next = before;
        }

        start->next->next = after; // invert where the first inverted node is pointing
        start->next = current;     // move the last node in the inversion group to the start

        return (left == 1 ? start->next : head);
    }
};