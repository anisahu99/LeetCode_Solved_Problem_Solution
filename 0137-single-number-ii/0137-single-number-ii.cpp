class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32,0);
        for(int & num:nums){
            for(int i=0;i<32;i++){
                if(num&(1<<i)){
                    bit[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(bit[i]%3==1){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};