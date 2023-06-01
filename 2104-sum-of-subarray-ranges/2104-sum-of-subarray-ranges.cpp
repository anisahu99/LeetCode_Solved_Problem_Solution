class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int si=0;si<n;si++){
            int mn=nums[si];
            int mx=nums[si];
            for(int ei=si+1;ei<n;ei++){
                mn=min(nums[ei],mn);
                mx=max(nums[ei],mx);
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};