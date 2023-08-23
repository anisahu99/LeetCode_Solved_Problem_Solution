//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(int row,int col,int dir,int i,int &m,int &n,vector<vector<char>> &grid, string &word,vector<vector<int>> &d){
        if(i==word.length()) return true;
        auto isSafe=[&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==word[i];
        };
        
        char temp=grid[row][col];
        grid[row][col]='$';
        bool ans=false;
        if(dir!=-1){
                int r=row+d[dir][0];
                int c=col+d[dir][1];
                if(isSafe(r,c)&&search(r,c,dir,i+1,m,n,grid,word,d)){
                    ans=true;
                }
        }
        else{
            for(int k=0;k<8;k++){
                int r=row+d[k][0];
                int c=col+d[k][1];
                if(isSafe(r,c)&&search(r,c,k,i+1,m,n,grid,word,d)){
                    ans=true;
                    break;
                }
            }
        }
        grid[row][col]=temp;
        if(ans) return true;
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    //0->diagonally down right//1->right//2->down//3-left//4-up//5-diagonally top left
	    //6-diagonally down left//7-diagonally top right
	    vector<vector<int>> d{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>> ans;
	    for(int row=0;row<m;row++){
	        for(int col=0;col<n;col++){
	            if(word[0]==grid[row][col]&&search(row,col,-1,1,m,n,grid,word,d)){
	                ans.push_back({row,col});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends