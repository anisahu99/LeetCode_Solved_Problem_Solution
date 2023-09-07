class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> cnt(31, 0);
        long long s = 0;
        int n = nums.size();
        
        // we can do beacuse our val/nums[i] is only power of 2.
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            cnt[int(log2(x))]++;
            s += x;
        }
        // for(int i=0;i<31;i++){
        //     for(int &val:nums){
        //         if(val&(1<<i)){
        //             cnt[i]++;
        //         }
        //     }
        // }

        if (s < target) {
            return -1;
        }

        int i = 0, minimum_Division = 0;
        while (i < 30) {
            if ((1 << i) & target) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                } else {
                    int j=i;
                    while(j<30&&cnt[j]==0){
                        minimum_Division++;
                        j++;
                    }
                    cnt[j]--;
                    while(j>i){
                        cnt[--j]++;
                    }
                }
            }
            cnt[i + 1] += cnt[i] / 2;
            i++;
        }
        
        return minimum_Division;
    }
};
