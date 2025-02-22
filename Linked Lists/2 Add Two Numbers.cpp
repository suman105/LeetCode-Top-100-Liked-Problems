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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *result = new ListNode(-1),*temp;
            temp = result;
            int carry = 0,sum=0;
            while(l1 || l2 || carry)
            {
                if(l1 && l2){
                    sum = l1->val + l2->val + carry;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if(l1){
                    sum = l1->val + carry;
                    l1 = l1->next;
                }
                else if(l2){
                    sum = l2->val + carry;
                    l2=l2->next;
                }
                else    sum = carry;
                carry = sum/10;
                temp->next = new ListNode(sum%10);
                temp = temp->next;
            }  
            return result->next;
        }
    };