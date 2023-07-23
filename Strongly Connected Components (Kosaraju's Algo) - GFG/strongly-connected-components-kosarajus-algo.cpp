//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topoSort(int node,vector<int>& vis,stack<int>& st,vector<vector<int>>& adj){
	    
	    vis[node]=1;
	    for(int &next:adj[node]){
	        if(!vis[next]){
	            topoSort(next,vis,st,adj);
	        }
	        
	    }
	    
	    st.push(node);
	}
	void dfs(int node,vector<int>& vis,vector<vector<int>>& revAdj){
	    
	    vis[node]=1;
	    for(int &next:revAdj[node]){
	        if(!vis[next]){
	            dfs(next,vis,revAdj);
	        }
	        
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int node=0;node<V;node++){
            if(!vis[node]){
                topoSort(node,vis,st,adj);
            }
        }
        vector<vector<int>> revAdj(V);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                revAdj[v].push_back(u);
            }
        }
        vis=vector<int>(V,0);
        int scc=0;
        while(!st.empty()){
            if(!vis[st.top()]){
                scc++;
                dfs(st.top(),vis,revAdj);
            }
            st.pop();
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends