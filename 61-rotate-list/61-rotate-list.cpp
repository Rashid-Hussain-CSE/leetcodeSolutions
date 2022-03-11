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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        temp=head;
        while(k--){
            temp=temp->next;
        }
        ListNode *start=head;
        while(temp->next){
            start=start->next;
            temp=temp->next;
        }
        cout<<start->val<<" "<<temp->val;
        temp->next=head;
        head=start->next;
        start->next=nullptr;
        return head;
    }
};