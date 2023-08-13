class Solution {
public:
    int find(vector<int> &LIS,int &val,int n){
        
        int start=0,end=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(val>LIS[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return start;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> LIS(n+1,INT_MAX);
        LIS[0]=INT_MIN;
        for(int i=0;i<n;i++){
            int index=find(LIS,nums[i],n);
            //cout<<"index: "<<index<<" num: "<<nums[i];
            if(index>0&&index<=n){
                LIS[index]=nums[i];
            }
            
        }
        
        for(int i=n;i>0;i--){
            if(LIS[i]!=INT_MAX) return i;
        }
        return 1;
    }
};