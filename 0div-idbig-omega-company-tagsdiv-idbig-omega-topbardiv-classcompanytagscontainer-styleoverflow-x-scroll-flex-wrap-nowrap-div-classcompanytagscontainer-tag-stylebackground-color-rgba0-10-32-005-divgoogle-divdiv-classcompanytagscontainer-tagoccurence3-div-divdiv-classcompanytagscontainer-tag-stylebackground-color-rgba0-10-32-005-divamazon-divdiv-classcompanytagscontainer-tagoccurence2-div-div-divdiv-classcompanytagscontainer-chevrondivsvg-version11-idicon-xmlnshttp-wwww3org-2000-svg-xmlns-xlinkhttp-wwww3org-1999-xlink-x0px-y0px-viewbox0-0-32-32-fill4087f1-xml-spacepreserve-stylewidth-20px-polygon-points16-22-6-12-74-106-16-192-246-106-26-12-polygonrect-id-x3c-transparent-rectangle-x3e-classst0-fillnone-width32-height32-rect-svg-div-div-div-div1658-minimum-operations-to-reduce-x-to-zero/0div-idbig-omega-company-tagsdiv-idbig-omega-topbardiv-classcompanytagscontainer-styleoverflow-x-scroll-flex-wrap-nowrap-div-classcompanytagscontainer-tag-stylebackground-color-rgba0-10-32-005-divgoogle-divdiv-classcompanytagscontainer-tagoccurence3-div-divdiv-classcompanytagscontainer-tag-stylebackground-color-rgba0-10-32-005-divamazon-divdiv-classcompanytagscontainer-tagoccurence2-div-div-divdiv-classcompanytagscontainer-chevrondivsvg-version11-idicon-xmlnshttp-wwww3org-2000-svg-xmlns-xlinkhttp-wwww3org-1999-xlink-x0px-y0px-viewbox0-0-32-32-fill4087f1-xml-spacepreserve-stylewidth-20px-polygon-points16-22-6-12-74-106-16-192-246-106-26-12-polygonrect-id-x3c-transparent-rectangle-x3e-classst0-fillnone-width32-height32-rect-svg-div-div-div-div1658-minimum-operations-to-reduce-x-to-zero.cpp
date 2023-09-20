class Solution {
public:
    //little bit logical help resource from discussion
    //https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/2136555/C%2B%2BPython-Simple-Solution-w-Explanation-or-Sliding-Window
    
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int i = 0,j = 0;
        bool found = false;
        while(j<n) {
            curr_sum += nums[j];
            while (i <= j && curr_sum > target) {
                curr_sum -= nums[i];
                i++;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, j - i + 1);
            }
            j++;
        }
        return found ? n - max_len : -1;
    }
};