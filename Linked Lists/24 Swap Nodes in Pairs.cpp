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
        ListNode* swapPairs(ListNode* head) 
        {
            if(!head || !head->next)    return head;
    
            ListNode *result = new ListNode(-1), *temp=result;
            ListNode *prev = result, *cur = head;
    
            while(cur && cur->next)
            {
                ListNode *first = cur, *second = cur->next;
    
                first->next = second->next;
                second->next = first;
                prev->next = second;
    
                prev = first;
                cur = first->next;
            }
            return result->next;
        }
    };