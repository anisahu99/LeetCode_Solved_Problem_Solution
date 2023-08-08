class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        vector<int> suffix(n,1);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        vector<int> ans(n,0);
        int left=-1;
        int i=0;
        int right=1;
        while(i<n){
            if(left==-1){
                ans[i]=suffix[right];
            }
            else if(right==n){
                ans[i]=prefix[left];
            }
            else{
                ans[i]=suffix[right]*prefix[left];
            }
            left++;i++;right++;
        }
        return ans;
    }
};