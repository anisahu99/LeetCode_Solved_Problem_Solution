//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
    vector<int> left(n, -1);
    vector<int> right(n, -1);

    stack<int> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {
            stack.pop();
        }
        if (!stack.empty()) {
            left[i] = stack.top();
        }
        stack.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {
            stack.pop();
        }
        if (!stack.empty()) {
            right[i] = stack.top();
        }
        stack.push(i);
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        int leftDist = left[i] == -1 ? INT_MAX : i - left[i];
        int rightDist = right[i] == -1 ? INT_MAX : right[i] - i;
        if (leftDist < rightDist || (leftDist == rightDist && left[i] != -1 && arr[left[i]] <= arr[right[i]])) {
            result[i] = left[i];
        } else if (leftDist > rightDist || (leftDist == rightDist && right[i] != -1 && arr[right[i]] < arr[left[i]])) {
            result[i] = right[i];
        } else {
            result[i] = -1;
        }
    }
    return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends