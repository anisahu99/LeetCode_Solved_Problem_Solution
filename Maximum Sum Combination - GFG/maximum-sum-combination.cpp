//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(),a.end());
    	sort(b.begin(),b.end());
    	priority_queue<pair<int,pair<int,int>>> pq;
    	pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    	set<pair<int,int>> vis;
    	vis.insert({n-1,n-1});
    	vector<int> ans;
    	while(k--){
    		int sum=pq.top().first;
    		ans.push_back(sum);
    		int i=pq.top().second.first;
    		int j=pq.top().second.second;pq.pop();
    		
    		
    		if(j-1>=0&&vis.find({i,j-1})==vis.end()){
    			pq.push({a[i]+b[j-1],{i,j-1}});
    			vis.insert({i,j-1});
    		}
    		if(i-1>=0&&vis.find({i-1,j})==vis.end()){
    			pq.push({a[i-1]+b[j],{i-1,j}});
    			vis.insert({i-1,j});
    		}
    	}
    	return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends