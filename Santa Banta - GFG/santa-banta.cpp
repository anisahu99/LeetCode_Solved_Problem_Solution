//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


vector<int> Prime;
class Solution{
public:
    
    void precompute()
     {
    int n=1e6;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
    for (int p = 2; p <= n; p++){
        if (prime[p]){
            Prime.push_back(p);
        }
     }
    }
    
    vector<int> rank1;
    vector<int> par;
    int find_parent(int val){
        if(par[val]==val) return val;
        par[val]=find_parent(par[val]);
        return par[val];
    }
    void union_( int a, int b) 
    {
        int a_parent=find_parent(a);
        int b_parent=find_parent(b);
        if(a_parent==b_parent) return;
        if(rank1[a_parent]==rank1[b_parent]){
            par[b_parent]=a_parent;
            rank1[a_parent]++;
        }else{
            if(rank1[a_parent]>rank1[b_parent]){
                par[b_parent]=a_parent;
            }
            else{
                par[a_parent]=b_parent;
            }
        }
        return;
    }
    
    //Function to check whether 2 nodes are connected or not.
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        // if(m==0)
        // return -1;
        rank1.resize(n+1);
        par.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int &j:g[i]){
                union_(i,j);
            }
        }
        vector<int> cnt(n+1,0);
        
        for(int i=1;i<=n;i++){
            cnt[par[i]]++;
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(mx,cnt[i]);
        }
        if(mx==1){
            return -1;
        }
        return Prime[mx-1];
        
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends