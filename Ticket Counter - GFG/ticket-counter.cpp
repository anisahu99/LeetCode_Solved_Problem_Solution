//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  void print(queue<int> q){
      while(!q.empty()){
          cout<<q.front()<<" ";
          q.pop();
      }
      cout<<endl;
  }
    int distributeTicket(int N, int k) {
        // code here
        queue<int> q;
        for(int i=1;i<=N;i++){
            q.push(i);
        }
        
        int l2r=1;
        //print(q);
        while(q.size()>k){
            //print(q);
            if(q.size()>k&&l2r){
                l2r=0;
                for(int i=0;i<k;i++){
                    q.pop();
                }
            }
            if(q.size()>k){
                int sz=q.size()-k;
                for(int i=0;i<sz;i++){
                    //cout<<q.front()<<" ";
                    q.push(q.front());
                    q.pop();
                }
            }
            if(q.size()>k){
                l2r=1;
                for(int i=0;i<k;i++){
                    q.pop();
                }
            }
            
            //print(q);
        }
        while(l2r&&q.size()!=1){
            q.pop();
        }
        return q.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends