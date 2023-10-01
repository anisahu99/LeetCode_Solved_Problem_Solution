class Solution {
public:
    //this is optimal brute force
    //using hashmap
    //rolling sum concept/idea
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int> left;
        for(int l=0,left_sum=0;l<=n&&left_sum<=x;l++){
            //{sum,length}=>length corresponding to sum
            left[left_sum]=l;
            if(l<n){
                left_sum+=nums[l];
            }
        }
        
        int res=INT_MAX;
        for(int right_idx=n,right_sum=0;right_idx>=0;right_idx--){
            if(right_idx<n) right_sum+=nums[right_idx];
            
            int target=x-right_sum;
            auto it=left.find(target);
            if(it==left.end()) continue;
            int left_idx=it->second-1;
            //It is used to avoid overlapping of sum from left(l) and right(r) side.
            if(left_idx<right_idx){
                
                int ans=(left_idx+1)+(n-right_idx);
                res=min(res,ans);
            }
        }
        return res==INT_MAX?-1:res;
    }
};