//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    void reverse(node* s,node* e){
        node* curr=s;
        node* prev=NULL;
        while(prev!=e){
            node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
         if(head==NULL|| head->next==NULL||k==1)
        return head;
        node* dummy=new node(-1);
        dummy->next=head;
        node* prev=dummy;
        node* e=head;
        int t=0;
        while(e!=NULL){
            t++;
            if(t%k==0||e->next==NULL){
                node *start=prev->next,*temp=e->next;
                reverse(start,e);
                prev->next=e;
                start->next=temp;
                prev=start;
                e=temp;
            }
            else
            e=e->next;
        }
         return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends