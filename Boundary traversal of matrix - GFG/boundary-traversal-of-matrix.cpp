//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int m, int n) 
    {
        // code here
        
        
        if(m==1){
            return matrix[0];
        }
        else if(n==1){
            vector<int> traversal;
            for(int row=0;row<m;row++){
                traversal.push_back(matrix[row][0]);
            }
            return traversal;
        }
        vector<int> traversal;
        for(int col=0;col<n;col++){
            traversal.push_back(matrix[0][col]);
        }
        for(int row=1;row<m;row++){
            traversal.push_back(matrix[row][n-1]);
        }
        for(int col=n-2;col>=0;col--){
            traversal.push_back(matrix[m-1][col]);
        }
        for(int row=m-2;row>=1;row--){
            traversal.push_back(matrix[row][0]);
        }
        return traversal;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends