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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while(head){
            st.push(head);
            head=head->next;
        }
        int mx=INT_MIN;
        head=NULL;
        while(!st.empty()){
            ListNode* temp=st.top();st.pop();
            if(temp->val>=mx){
                temp->next=NULL;
                if(!head){
                    head=temp;
                }else{
                    ListNode* t=head;
                    head=temp;
                    head->next=t;
                }
                mx=temp->val;
            }
        }
        
        return head;
    }
};