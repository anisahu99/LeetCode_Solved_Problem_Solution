class Solution {
public:
    
    int isValid(vector<int>& nums,int n,int target){
        int i=0;
        int valid_pairs=0;
        while(i+1<n){
            if(nums[i+1]-nums[i]<=target){
                valid_pairs++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return valid_pairs;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans;
        int start=0,end=nums[n-1];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(nums,n,mid)>=p){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};