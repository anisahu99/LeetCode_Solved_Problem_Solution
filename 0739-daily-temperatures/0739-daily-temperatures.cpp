class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
			
			// Popping all indices with a lower or equal temperature than the current index
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
				
			// If the stack still has elements, then the next warmer temperature exists!
            if(!st.empty())
                ans[i] = st.top() - i;
				
			// Inserting current index in the stack: monotonicity is maintained!
            st.push(i);
        }
        
        return ans;
    }
};