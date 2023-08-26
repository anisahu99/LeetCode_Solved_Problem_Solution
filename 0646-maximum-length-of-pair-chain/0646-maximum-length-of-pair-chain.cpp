class Solution {
public:
    int t[1002][1002];
    int longest_chain(vector<vector<int>>& pairs,int i,int prev){
        if(i==pairs.size()) return 0;
        if(t[i][prev+1]!=-1) return t[i][prev+1];
        
        int take=0;
        if(prev==-1||pairs[i][0]>pairs[prev][1]){
            take=1+longest_chain(pairs,i+1,i);
        }
        
        int not_take=0+longest_chain(pairs,i+1,prev);
        
        return t[i][prev+1]=max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(t,-1,sizeof(t));
        
        return longest_chain(pairs,0,-1);
    }
};