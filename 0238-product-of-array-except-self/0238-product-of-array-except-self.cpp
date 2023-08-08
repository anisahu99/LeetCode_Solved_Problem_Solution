class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suffix(n,1);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        int left=-1;
        int leftProd=1;
        int i=0;
        int right=1;
        while(i<n){
            if(left==-1){
                suffix[i]=suffix[right];
                leftProd*=nums[i];
            }
            else if(right==n){
                suffix[i]=leftProd;
            }
            else{
                suffix[i]=suffix[right]*leftProd;
                leftProd*=nums[i];
            }
            left++;i++;right++;
        }
        return suffix;
    }
};