class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> v(32,0);
        for(int &num:nums){
            for(int i=0;i<32;i++){
                int bit=(num&(1<<i));
                if(bit){
                    v[i]=1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<32;i++){
            if(v[i]){
                sum+=(1<<i);
            }
        }
        return sum;
    }
};