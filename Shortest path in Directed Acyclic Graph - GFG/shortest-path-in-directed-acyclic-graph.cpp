//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> g(n);
        for(vector<int>& edge:edges){
            g[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<int> D(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        D[0]=0;
        while(!pq.empty()){
            int node=pq.top().first;
            int dist=pq.top().second;pq.pop();
            for(pair<int,int> next:g[node]){
                int d=next.second;
                int adj=next.first;
                if(dist+d<D[adj]){
                    D[adj]=dist+d;
                    pq.push({adj,D[adj]});
                }
            }
        }
        for(int i=1;i<n;i++){
            if(D[i]==INT_MAX){
                D[i]=-1;
            }
        }
        return D;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends