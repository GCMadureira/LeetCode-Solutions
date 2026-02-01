// Construct two lists and join them at the end
// 0ms

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr, *lessTail = nullptr;
        ListNode* greaterHead = nullptr, *greaterTail = nullptr;

        while(head != nullptr) {
            if(head->val < x){
                if(lessHead == nullptr){
                    lessHead = head;
                    lessTail = head;
                }
                else {
                    lessTail->next = head;
                    lessTail = head;
                }
            }
            else{
                if(greaterHead == nullptr){
                    greaterHead = head;
                    greaterTail = head;
                }
                else {
                    greaterTail->next = head;
                    greaterTail = head;
                }
            }

            head = head->next;
        }

        if(lessTail != nullptr) lessTail->next = greaterHead;
        if(greaterTail != nullptr) greaterTail->next = nullptr;

        if(lessTail == nullptr) return greaterHead;
        else return lessHead;
    }
};