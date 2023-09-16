
class Solution {
public:
    typedef pair<int,int> P; 
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int cnt=0;
        int n=coordinates.size();
        map<P,int> mp;
        for(int i=0;i<n;i++){
            int x2=coordinates[i][0],y2=coordinates[i][1];
            for(int possible=0;possible<=100;possible++){
                if(k-possible<0) continue;
                int x1=possible^x2;
                int x2=(k-possible)^y2;
                if(mp.find({x1,x2})!=mp.end()){
                    cnt+=mp[{x1,x2}];
                }
            }
            mp[{x2,y2}]++;
        }
        return cnt;
    }
};