class Solution {
public:
    // do myself
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(nums.size(),0);
        for(auto it:mp){
            vector<int> arr=it.second;
            int s=arr.size();
            if(s==1){
                ans[arr[0]]=0;
                continue;
            }
            vector<long> prefix(s,0);
            vector<long> suffix(s,0);
            prefix[0]=arr[0];
            suffix[s-1]=arr[s-1];
            for(int i=1;i<s;i++){
                prefix[i]=prefix[i-1]+arr[i];
            }
            for(int i=s-2;i>=0;i--){
                suffix[i]=arr[i]+suffix[i+1];
            }
            
            for(int i=0;i<s;i++){
                long long left=0;long long right=0;
                
                if(i==0){
                    right=suffix[i+1]-(s-1-i)*1LL*arr[i];
                }
                else if(i==s-1){
                    left=abs(prefix[i-1]-(i-0)*1LL*arr[i]);
                }
                else{
                    left=abs(prefix[i-1]-(i-0)*1LL*arr[i]);
                    right=suffix[i+1]-(s-1-i)*1LL*arr[i];
                }
                ans[arr[i]]=left+right;
            }
        }
        return ans;
    }
};