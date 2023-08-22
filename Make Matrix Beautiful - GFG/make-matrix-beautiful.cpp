//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowSum(n,0);
        vector<int> colSum(n,0);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                rowSum[row]+=matrix[row][col];
            }
        }
        for(int col=0;col<n;col++){
            for(int row=0;row<n;row++){
                colSum[col]+=matrix[row][col];
            }
        }
        int MaxRowSum=0;
        int MaxColSum=0;
        for(int i=0;i<n;i++){
            MaxRowSum=max(MaxRowSum,rowSum[i]);
            MaxColSum=max(MaxColSum,colSum[i]);
        }
        int requiredIncrement_row=0;
        int requiredIncrement_col=0;
        for(int i=0;i<n;i++){
            requiredIncrement_row+=MaxRowSum-rowSum[i];
            requiredIncrement_col+=MaxColSum-colSum[i];
        }
        return max(requiredIncrement_row,requiredIncrement_col);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends