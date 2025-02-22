class Solution {
    public:
        ListNode* sortList(ListNode* head) 
        {
            if (!head || !head->next) {
                return head;
            }
    
            ListNode* mid = findMiddle(head);
            ListNode* left = head;
            ListNode* right = mid->next;
            mid->next = nullptr;
    
            left = sortList(left);
            right = sortList(right);
    
            return merge(left, right);
        }
    
        ListNode* findMiddle(ListNode* head) {
            if (!head) return nullptr;
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            return slow;
        }
    
        ListNode* merge(ListNode* left, ListNode* right) {
            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;
    
            while (left && right) {
                if (left->val < right->val) {
                    current->next = left;
                    left = left->next;
                } else {
                    current->next = right;
                    right = right->next;
                }
                current = current->next;
            }
            
            if (left) current->next = left;
            if (right) current->next = right;
    
            return dummy->next;
        }
    };
    