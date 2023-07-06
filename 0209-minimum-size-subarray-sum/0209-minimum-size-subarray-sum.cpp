class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        
        int n=nums.size();
        int i=0,j=0,sum=0;
        int ans=0;
        while(i<=j){
            while(j<n&&sum<target){
                //cout<<sum<<endl;
                sum+=nums[j];
                j++;
            }
            
            //cout<<sum<<":"<<i;
            if(j==n&&sum>=target){
                cout<<"("<<i<<","<<j<<")"<<endl;
                if(!ans||ans>(j-i)){
                    ans=j-i;
                }
            }
            if(j==n&&sum<target&&!ans){
                return 0;
            }
            if(j<n&&sum>=target){
                //cout<<"("<<i<<","<<j<<")"<<endl;
                if(!ans||ans>(j-i)){
                    ans=j-i;
                }
            }
            if(i<n){
                sum-=nums[i];
            }
            
            i++;
        }
        return ans;
    }
};