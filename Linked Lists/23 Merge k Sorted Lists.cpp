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
        struct Compare {
            bool operator()(ListNode* l1, ListNode* l2) {
                return l1->val > l2->val;
            }
        };
    
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
            for(ListNode* list : lists){
                if(list)    pq.push(list);
            }
    
            ListNode *result = new ListNode(-1), *temp=result;
            temp = result;
    
            while(!pq.empty())
            {
                ListNode *node = pq.top();
                pq.pop();
    
                temp->next = node;
                temp = temp->next;
    
                if(node->next)  pq.push(node->next);
            }
            return result->next;
        }
    };