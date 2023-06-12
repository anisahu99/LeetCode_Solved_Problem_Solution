class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int idx=0;
        int n=nums.size();
        while(idx<n){
            int i=idx;
            for(;i<n-1;i++){
                if(((nums[i+1]>=0&&nums[i]>=0)||(nums[i+1]<=0&&nums[i]<=0))&&(nums[i+1]-nums[i]==1)){
                    continue;
                }
                else{
                    break;
                }
            }
            if(i<n&&nums[idx]!=nums[i]){
                ans.push_back(to_string(nums[idx])+"->"+to_string(nums[i]));
            }else if(i<n){
                ans.push_back(to_string(nums[idx]));
            }
            idx=i+1;
        }
        return ans;
    }
};