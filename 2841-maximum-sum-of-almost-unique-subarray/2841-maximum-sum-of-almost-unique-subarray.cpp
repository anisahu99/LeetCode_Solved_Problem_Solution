class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        long long ans=0;
        long long sum=0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k&&mp.size()>=m){
                ans=max(ans,sum);
                sum-=nums[i];
                if(--mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            else if(j-i+1==k&&mp.size()<m){
                sum-=nums[i];
                if(--mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};