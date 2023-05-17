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
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {//if no node present !head
            return head;
        }
        ListNode*temp=head->next;
        ListNode*temp1=head;
        ListNode*extra=temp;
         temp1->next=NULL;   
            while(temp!=NULL){
                    extra=temp->next;
                    temp->next=temp1;
                    temp1=temp;
                    temp=extra;
            }
            return temp1;;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=reverseList(slow);
        slow=head;
        int ans=0;
        while(fast){
            ans=max(ans,(slow->val+fast->val));
            slow=slow->next;
            fast=fast->next;
        }
        return ans;
    }
};