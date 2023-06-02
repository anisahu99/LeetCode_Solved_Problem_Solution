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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* Nhead=new ListNode(0);
        ListNode* pointer=Nhead;
        while(temp1&&temp2){
            Nhead->next=new ListNode((temp1->val+temp2->val+carry)%10);
            carry=(temp1->val+temp2->val+carry)/10;
            Nhead=Nhead->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            Nhead->next=new ListNode((temp1->val+carry)%10);
            carry=(temp1->val+carry)/10;
            Nhead=Nhead->next;
            temp1=temp1->next;
        }
        while(temp2){
            Nhead->next=new ListNode((temp2->val+carry)%10);
            carry=(temp2->val+carry)/10;
            Nhead=Nhead->next;
            temp2=temp2->next;
        }
        if(carry){
            Nhead->next=new ListNode(carry%10);
            carry=carry/10;
            Nhead=Nhead->next;
        }
        pointer=reverseList(pointer->next);
        return pointer;
    }
};