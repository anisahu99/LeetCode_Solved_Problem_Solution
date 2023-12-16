class Solution {
public:
    int mod=1e9+7;
    int binaryExponentiation(int a,int b){
        int ans=1;
        while(b){
            if(b&1){
                ans=(1LL*ans*a)%mod;
            }
            a=(1LL*a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    
    int find_distinct_interval(vector<vector<int>> &intervals,int &sz){
        if(sz==1) return 1;
        int count=1;
        int i=1;
        int first=intervals[0][0];
        int second=intervals[0][1];
        while(i<sz){
            if(second>intervals[i][0]){
                second=max(second,intervals[i][1]);
            }
            else{
                first=intervals[i][0];
                second=intervals[i][1];
                count++;
            }
            i++;
        }
        return count;
    }
    
    int numberOfGoodPartitions(vector<int>& nums) {
        
        unordered_map<int,pair<int,int>> pos;
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(freq.find(nums[i])==freq.end()){
                pos[nums[i]].first=i;
            }
            pos[nums[i]].second=i;
            freq[nums[i]]++;
        }
        int sz=pos.size();
        vector<vector<int>> intervals(sz,vector<int>(2,0));
        int i=0;
        for(auto it:pos){
            intervals[i][0]=it.second.first;
            intervals[i][1]=it.second.second;
            i++;
        }
        sort(intervals.begin(),intervals.end());
        int total=find_distinct_interval(intervals,sz);
        return binaryExponentiation(2,total-1);
    }
};

        //for(int j=0;j<sz;j++){
        //     cout<<intervals[j][0]<<", "<<intervals[j][1]<<endl;
        // }
        // for(auto it:pos){
        //     cout<<it.first<<"->("<<it.second.first<<", "<<it.second.second<<")"<<endl;
        // }