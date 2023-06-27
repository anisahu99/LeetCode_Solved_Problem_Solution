//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

class compare{
  public:
  bool operator()(const struct Node* h1,const struct Node* h2){
      return h1->data<h2->data;
  }
};
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<struct Node*,compare> v;
        while(head1){
            v.insert(head1);
            head1=head1->next;
        }while(head2){
            v.insert(head2);
            head2=head2->next;
        }
        bool flag=true;
        struct Node* temp;
        for(auto it=v.begin();it!=v.end();it++){
            if(flag){
                head1=*it;
                flag=false;
                temp=*it;
                
            }
            else{
                temp->next=*it;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        return head1;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends