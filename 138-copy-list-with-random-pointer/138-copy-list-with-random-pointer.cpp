/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copyList(Node *head){
        Node *curr=head, *temp;
        while(curr){
            Node *copy=new Node(curr->val);
            temp = curr->next;
            curr->next = copy;
            copy->next = temp;
            curr = curr->next->next;
        }
    }
    void addRandom(Node *head){
        Node *curr=head;
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
    }
    Node* detach(Node *head){
        Node *org=head, *copy=head->next, *copyHead=copy;
        while(copy->next && org->next){
            org->next = org->next->next;
            copy->next = copy->next->next;
            org = org->next;
            copy = copy->next;
        }
        org->next = NULL;
        return copyHead;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return nullptr;
        copyList(head);
        addRandom(head);
        return detach(head);
    }
};