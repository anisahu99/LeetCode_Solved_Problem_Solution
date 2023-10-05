class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==2&&nums[0]!=nums[1]) return nums;
        if(n==2) return {nums[0]};
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        
        int occur=(n/3)+1;
        int i=1;
        int cnt=1;
        int pre=nums[0];
        if(cnt>=occur) ans.push_back(pre);
        while(i<n){
            if(nums[i]!=pre){
                pre=nums[i];
                cnt=1;
            }
            else{
                cnt++;
            }
            
            if(cnt>=occur&&(ans.size()==0||ans.back()!=nums[i])) ans.push_back(nums[i]);
            i++;
        }
        return ans;
    }
};