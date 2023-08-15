//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        
        // Your code goes here
        int max_sum=0;
        int cur_sum=0;
        int val;
        int countOfOnes=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                countOfOnes++;
            }
            val=(a[i]==0)?1:-1;
            cur_sum+=val;
            max_sum=max(max_sum,cur_sum);
            if(cur_sum<0)
            {
                cur_sum=0;
            }
        }
        return (countOfOnes+max_sum);
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends