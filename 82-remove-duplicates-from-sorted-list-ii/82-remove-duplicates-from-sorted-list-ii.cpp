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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* nh = new ListNode(-101);
        ListNode* it = nh;
        
        
        ListNode* temp=head;
        
        while(temp)
        {
            
            int cnt=0,val=temp->val;
            ListNode* y=temp;
            while(y && y->val==val)
            {
                cnt++;
                y=y->next;
            }
            if(cnt==1)
            {
                ListNode* x = new ListNode(temp->val);
                it->next=x;
                it=it->next;
                temp=temp->next;
            }
            temp=y;
        }
        return nh->next;
    }
};