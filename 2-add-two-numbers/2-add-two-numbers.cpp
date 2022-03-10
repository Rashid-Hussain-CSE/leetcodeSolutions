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
    ListNode* reverse(ListNode* head){
        ListNode *temp, *prev=NULL, *curr=head;
        while(curr){
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rl1 = (l1);
        ListNode *rl2 = (l2);
        ListNode *result = new ListNode(0);
        ListNode *resultHead=result;
        int carry=0;
        while(rl1 || rl2){
            if(rl1 && rl2){
                int sum = rl1->val + rl2->val + carry;
                if(sum<10){
                    result->next = new ListNode(sum);
                    carry=0;
                    result=result->next;
                }
                else{
                    carry = sum/10;
                    result->next = new ListNode(sum%10);
                    result = result->next;
                }
                rl1=rl1->next;
                rl2=rl2->next;
            }
            else if(rl1){
                int sum = rl1->val + carry;
                if(sum<10){
                    result->next = new ListNode(sum);
                    carry=0;
                    result=result->next;
                }
                else{
                    carry = sum/10;
                    result->next = new ListNode(sum%10);
                    result = result->next;
                }
                rl1=rl1->next;
            }
            else if(rl2){
                int sum = rl2->val + carry;
                if(sum<10){
                    result->next = new ListNode(sum);
                    carry=0;
                    result=result->next;
                }
                else{
                    carry = sum/10;
                    result->next = new ListNode(sum%10);
                    result = result->next;
                }
                rl2=rl2->next;
            }
        }
        if(carry!=0){
            result->next = new ListNode(carry);
            result = result->next;
        }
        return resultHead->next;
    }
};