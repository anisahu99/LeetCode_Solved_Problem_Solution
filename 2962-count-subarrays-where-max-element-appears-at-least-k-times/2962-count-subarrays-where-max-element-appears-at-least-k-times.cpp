class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        // find Max Element from given vector
        int max_ele=0;
        for(int &num:nums){
            max_ele=max(max_ele,num);
        }
        // slide the window
        int index=-1;
        int i=0,j=0,n=nums.size();
        int max_count=0;
        long long total=0;
        while(j<n){
            if(nums[j]==max_ele) max_count++;
            
            while(max_count==k&&nums[i]!=max_ele) i++;
            
            if(max_count==k){
                long long l1=(i-index-1);
                long long l2=(n-j-1);
                total+=l1+l2+l1*l2+1;
                max_count-=1;
                index=i;
                i++;
            }
            j++;
        }
        return total;
    }
};