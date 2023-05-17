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
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        int i=0;
        temp=head;
        while(i!=(n/2-1)){
            temp=temp->next;
            i++;
        }
        temp->next=reverseList(temp->next);
        
        ListNode* ptr1=head;
        ListNode* ptr2=temp->next;
        int ans=0;
        while(ptr2){
            ans=max(ans,(ptr1->val+ptr2->val));
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        return ans;
    }
};