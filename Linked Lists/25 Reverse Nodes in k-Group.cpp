/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            if (!head || k <= 1) return head;
    
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* prevGrp = dummy;
    
            while (true) {
                ListNode* grpStart = prevGrp->next;
                ListNode* grpEnd = prevGrp;
    
                for (int i = 0; i < k && grpEnd; i++) {
                    grpEnd = grpEnd->next;
                }
                if (!grpEnd) break;  
                ListNode* nextGrpStart = grpEnd->next;
    
                ListNode* prev = nextGrpStart;
                ListNode* cur = grpStart;
                while (cur != nextGrpStart) {
                    ListNode* temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
    
                prevGrp->next = grpEnd;
                prevGrp = grpStart;  
            }
    
            return dummy->next;
        }
    };