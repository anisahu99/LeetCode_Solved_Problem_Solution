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
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverseList(head);
        vector<int> ans;
        ListNode* temp=head;
        stack<int> st;
        while(temp){
           if(st.empty()){
               ans.push_back(0);
               st.push(temp->val);
           }
            else{
                while(!st.empty()&&st.top()<=temp->val){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(st.top());
                    st.push(temp->val);
                }else{
                    ans.push_back(0);
                    st.push(temp->val);
                    
                }
            }
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};