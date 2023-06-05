class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        int dy=(coordinates[1][1]-coordinates[0][1]);
        int dx=(coordinates[1][0]-coordinates[0][0]);
        for(int i=2;i<n;i++){
            int DY=(coordinates[i][1]-coordinates[i-1][1]);
            int DX=(coordinates[i][0]-coordinates[i-1][0]);
            if(dy*DX!=dx*DY)
                return false;
        }
        return true;
    }
};