//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Pair {
public:
    int a, b;
    Pair(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<Pair> st;
        for (int i = 0; i < N; i++) {
            if (!st.empty() && st.top().a == color[i] && st.top().b == radius[i])
                st.pop();
            else
                st.push(Pair(color[i], radius[i]));
        }
        return st.size();
    }
};



//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends