//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head){
        if(!head||!head->next) return head;
        
        Node* pre=head;
        Node* curr=head->next;
        pre->next=NULL;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node* p=reverse(head);
         Node* t=p->next;
        // Max node contains the node which has the max value till those nodes which are travesed
        Node* max=p;
        while(t)
        {
            //checking if there is max valued node is present
            if(max->data>t->data)
                max->next=t->next;
            else
                max=t;
            t=t->next;
        }
        return reverse(p);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends