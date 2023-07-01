//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201]; //Cache momory for fast response
    
    int helper(int eggs, int floors){
        // Base Cases
        // If we reach at the bottom then return that
        if(floors == 0 || floors == 1) return floors;
        
        // If we have just one eggs we can't experiment more
        if(eggs == 1) return floors;
        
        // If sub Problem is already calculated then return from there
        if(t[eggs][floors] != -1) return t[eggs][floors];
        
        int ans = INT_MAX; // Create ans varible with max value
         
        // Just using MCM fomat
        for(int k=1;k<=floors;k++){
            int temp = 1 + max(helper(eggs-1, k-1), helper(eggs, floors-k));
            
            ans = min(ans, temp);
        }
        return t[eggs][floors] = ans;
    }
    
    int eggDrop(int n, int k) {
        memset(t, -1, sizeof(t)); // Initislize with all '-1'
        return helper(n, k); // Call our servent - helper function
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends