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
    int size(ListNode* head){
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=size(head);
        vector<ListNode*> ans(k);
        ListNode* temp=head;
        int group_size=sz/k;
        int i=0;
        while(temp){
            if(sz%k!=0){
                group_size=sz/k+1;
                sz-=1;
                
            }
            else{
                group_size=sz/k;
                
            }
            //cout<<group_size<<endl;
            ListNode* tempp=temp;
            while(--group_size&&tempp){
                tempp=tempp->next;
            }
            ListNode* curr=tempp;
            tempp=tempp==NULL?tempp:tempp->next;
            if(curr){
                curr->next=NULL;
            }
            
            ans[i++]=temp;
            temp=tempp;
        }
        return ans;
    }
};