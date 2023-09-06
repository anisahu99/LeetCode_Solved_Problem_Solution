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
    void help(Node*head,unordered_map<Node*,int> &pos){
        Node* temp=head;
        int i=0;
        while(temp){
            pos[temp]=i++;
            temp=temp->next;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* cHead=NULL;
        Node* pre=NULL;
        unordered_map<Node*,int> pos;
        help(head,pos);
        map<pair<int,int>,Node*> mp;
        int i=0;
        while(temp){
            Node* cre=new Node(temp->val);
            
            mp[{i++,temp->val}]=cre;
            if(!cHead){
                cHead=cre;
            }
            else{
                pre->next=cre;
            }
            pre=cre;
            temp=temp->next;
        }
        temp=head;
        pre=cHead;
        while(temp){
            if(temp->random){
                int idx=pos[temp->random];
                pre->random=mp[{idx,temp->random->val}];
            }
            temp=temp->next;
            pre=pre->next;
        }
        return cHead;
    }
};