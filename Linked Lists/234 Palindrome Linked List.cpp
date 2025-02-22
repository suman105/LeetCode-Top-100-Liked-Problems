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
        bool isPalindrome(ListNode* head) 
        {
            ListNode *slow,*fast,*temp;
            slow=fast=head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }   
    
            ListNode *prev=NULL,*help=NULL;
            while(slow)
            {
                prev = slow;
                slow=slow->next;
                prev->next = help;
                help=prev;
            }
    
            while(help && head)
            {
                if(head->val != help->val) return false;
                help = help->next;
                head = head->next;
            }
            return true;
        }
    };