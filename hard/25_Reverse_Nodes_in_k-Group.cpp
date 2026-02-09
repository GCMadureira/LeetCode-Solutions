// not that elegant of a solution, could have been simpler


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextHead = head, *temp;
        ListNode* previousHead = new ListNode(0, head);
        head = previousHead;
        while(true) {
            // if the remaining list is too small to be inverted, then we arrived at the solution
            for(int i = 0; i < k; ++i) {
                if(nextHead == nullptr) return head->next;
                else nextHead = nextHead->next;
            }

            ListNode* current = previousHead->next;
            ListNode* currentNext = current->next;
            current->next = nextHead; // make the first element of this group (soon to be last) point to the first of the next group
            // invert the connection between current and currentNext in each step
            while(currentNext != nextHead) {
                temp = currentNext->next;
                currentNext->next = current;
                current = currentNext;
                currentNext = temp;
            }
            
            // make the last element of the last group point to the last (now first) element of this group
            temp = previousHead->next;
            previousHead->next = current;
            previousHead = temp;
        }

        // should not hit this return
        return head->next;
    }
};