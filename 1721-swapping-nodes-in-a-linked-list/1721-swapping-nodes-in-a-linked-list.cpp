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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        int n=0;
        while(fast&&fast->next){
            n=n+2;
            fast=fast->next->next;
        }
        if(fast) n=n+1;
        int i=1;
        ListNode* res1;
        int f;
        ListNode* res2;
        int s;
        fast=head;
        while(fast!=NULL){
            if(i==k){
                res1=fast;
                f=fast->val;
            }
            if(i==(n+1-k)){
                res2=fast;
                s=fast->val;
            }
            i++;
            fast=fast->next;
        }
        res1->val=s;
        res2->val=f;
        return head;
    }
};