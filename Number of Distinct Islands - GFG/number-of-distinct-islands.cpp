//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    vector<string> dir={"d-","t-","r-","l-"};
    vector<string> rdir={"t-","d-","l-","r-"};
    void dfs(int row,int col,int &n,int &m,vector<vector<int>> &arr,string& s){
        
        arr[row][col]=0;
        for(int k=0;k<4;k++){
            int r=row+dx[k];
            int c=col+dy[k];
            if(r<0||r==n|c<0||c==m||!arr[r][c]) continue;
            s+=dir[k];
            dfs(r,c,n,m,arr,s);
            s+=rdir[k];
        }
    }
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        int n=arr.size(),m=arr[0].size();
        unordered_set<string> shape;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                //cout<<arr[row][col]<<" ";
                if(arr[row][col]){
                    string s="";
                    dfs(row,col,n,m,arr,s);
                    //cout<<s<<endl;
                    shape.insert(s);
                }
            }
        }
    return shape.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends