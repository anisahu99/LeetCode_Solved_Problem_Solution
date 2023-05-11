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
        vector<ListNode*> node;
        while(!st.empty()){
            ListNode* temp=st.top();st.pop();
            if(temp->val>=mx){
                node.push_back(temp);
                mx=temp->val;
            }
        }
        int n=node.size();
        head=node[n-1];
        head->next=NULL;
        ListNode* temp=head;
        for(int i=n-2;i>=0;i--){
            temp->next=node[i];
            node[i]->next=NULL;
            temp=node[i];
        }
        return head;
    }
};