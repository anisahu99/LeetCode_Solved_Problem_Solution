//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=1e5;
        if(start==end) return 0;
        queue<int> q;
        int level=1;
        vector<int> vis(mod);
        vis[start]=1;
        for(int &val:arr){
            if(!vis[(val*start)%mod]){
                q.push((val*start)%mod);
                vis[(val*start)%mod]=1;
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();q.pop();
                if(node==end) return level;
                for(int &val:arr){
                    if(!vis[(val*node)%mod]){
                        q.push((val*node)%mod);
                        vis[(val*node)%mod]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends