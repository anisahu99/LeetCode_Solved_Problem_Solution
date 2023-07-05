//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solveTab(int &n, vector<int> &prices){
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int BS=0;BS<=1;BS++){
                int ans=0;
        
                if(BS){
                    int buy=curr[0]-prices[i];
                    int not_buy=next[BS];
                    
                    ans=max(buy,not_buy);
                }
                else{
                    int sell=prices[i]+next[1];
                    int not_sell=next[BS];
                    
                    ans=max(sell,not_sell);
                }
                
                curr[BS]=ans;
            }
            next=curr;
        }
        return next[1];
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        
        return solveTab(n,prices);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends