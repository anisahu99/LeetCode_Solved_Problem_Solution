class Solution {
public:
    // m-pairwise distinct elements means m distinct element both meaning same because
    //let k=4 m=3 subarray=[7,3,1,7]
    // possible distinct pairs (7,3)(7,1)(1,3) total distinct pair is 3
    // so with m distinct elements we only can make m pairwise distinct elements
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