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
        if(!head||!head->next) return head;
        
        ListNode* pre=head;
        ListNode* curr=head->next;
        pre->next=NULL;
        
        while(curr){
            ListNode* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* p=reverse(head);
        ListNode* t=p->next;
        // Max node contains the node which has the max value till those nodes which are travesed
        ListNode* max=p;
        while(t)
        {
            //checking if there is max valued node is present
            if(max->val>t->val)
                max->next=t->next;
            else
                max=t;
            t=t->next;
        }
        return reverse(p);
    }
};