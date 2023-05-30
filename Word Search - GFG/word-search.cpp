//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int m,n;
    bool solve(int i,int row,int col,string word,vector<vector<char>>& board){
        if(i>=word.length()){
            return true;
        }
        if(row<0||row>=m||col<0||col>=n||board[row][col]=='0'){
            return false;
        }
        if(board[row][col]!=word[i]){
            return false;
        }
        
        
        char chr=board[row][col];
        board[row][col]='0';
        for(int k=0;k<4;k++){
            
            if(solve(i+1,row+x[k],col+y[k],word,board)){
                return true;
            }
        }
        board[row][col]=chr;
        
        return false;
        
    }



    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        m=board.size(),n=board[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                char ch=board[row][col];
                if(ch==word[0]){
                    if(solve(0,row,col,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends