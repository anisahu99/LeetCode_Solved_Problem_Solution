class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        vector<int> result(n);
        result[0]=(prefix[n-1]-prefix[0])-((n-1)*nums[0]);
        result[n-1]=((n-1)*nums[n-1])-prefix[n-2];
        for(int i=1;i<n-1;i++){
            result[i]=((i)*nums[i])-(prefix[i-1]) + (prefix[n-1]-prefix[i])-((n-(i+1))*nums[i]);
        }
        return result;
    }
};