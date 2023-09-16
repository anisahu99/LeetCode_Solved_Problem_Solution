# define P pair<int,pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        res[0][0]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        auto isSafe=[&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n;
        };
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;pq.pop();
            
            if(row==m-1&&col==n-1) return diff;
            for(int k=0;k<4;k++){
                int nr=row+d[k].first;
                int nc=col+d[k].second;
                if(isSafe(nr,nc)){
                    int maxDiff=max(diff,abs(heights[row][col]-heights[nr][nc]));
                    if(res[nr][nc]>maxDiff){
                        pq.push({maxDiff,{nr,nc}});
                        res[nr][nc]=maxDiff;
                    }
                    
                }
            }
        }
        return res[m-1][n-1];
    }
};