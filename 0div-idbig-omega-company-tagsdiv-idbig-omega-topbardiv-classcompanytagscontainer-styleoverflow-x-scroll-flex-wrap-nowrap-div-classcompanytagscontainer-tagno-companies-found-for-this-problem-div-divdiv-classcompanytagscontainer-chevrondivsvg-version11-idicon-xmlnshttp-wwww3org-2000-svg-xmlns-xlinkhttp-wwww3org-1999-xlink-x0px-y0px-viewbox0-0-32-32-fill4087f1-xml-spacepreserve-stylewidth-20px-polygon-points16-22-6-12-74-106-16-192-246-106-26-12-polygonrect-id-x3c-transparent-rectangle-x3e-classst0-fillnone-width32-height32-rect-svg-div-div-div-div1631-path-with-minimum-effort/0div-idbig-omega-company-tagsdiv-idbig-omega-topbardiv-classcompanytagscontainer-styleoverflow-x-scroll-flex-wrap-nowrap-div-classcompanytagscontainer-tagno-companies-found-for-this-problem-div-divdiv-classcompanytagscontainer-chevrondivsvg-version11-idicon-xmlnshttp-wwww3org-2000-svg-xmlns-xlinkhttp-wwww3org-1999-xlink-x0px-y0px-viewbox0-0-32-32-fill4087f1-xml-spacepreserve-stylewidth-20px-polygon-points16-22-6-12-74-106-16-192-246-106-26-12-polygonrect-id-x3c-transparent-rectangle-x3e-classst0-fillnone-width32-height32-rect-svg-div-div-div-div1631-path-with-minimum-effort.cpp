class Solution {
public:
    vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};
    
    //
    // make cell as node so we do observation
    // grid[row][col]=row*n+col
    //n is size of column here n=lc.
    //conver cell to node
    // striver link to convert cell to node
    // min 08:00
    
    //https://www.youtube.com/watch?v=Rn6B-Q4SNyA
    
    
    // {
    //     {0,1,2},
    //     {3,4,5},
    //     {6,7,8}
    // }
    //make weighted graph between these adjacent nodes
    void makeGraph(int &lr,int &lc,vector<vector<int>>& heights,vector<vector<pair<int,int>>> &g,int &mx){
        
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<lr && y>=0 && y<lc;
        };
        for(int row=0;row<lr;row++){
            for(int col=0;col<lc;col++){
                mx=max(mx,heights[row][col]);
                for(int k=0;k<4;k++){
                    int r=row+d[k].first;
                    int c=col+d[k].second;
                    if(isSafe(r,c)){
                        g[row*lc+col].push_back({r*lc+c,abs(heights[row][col]-heights[r][c])});
                    }
                }
            }
        }
    }
    
    // we select that edge which cost <=poss_cost
    bool traverse(int &poss_cost,int &n,vector<vector<pair<int,int>>> &g){
        queue<int> q;
        vector<int> vis(n);//take visited array taki ham usi node par na pahuch jaae jaha se aaye the
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            if(node==n-1) return true;
            for(pair<int,int> &edge:g[node]){
                //take edge a-b which cost <=poss_cost
                if(edge.second<=poss_cost&&!vis[edge.first]){
                    q.push(edge.first);
                    vis[edge.first]=1;
                }
            }
        }
        return false;
    }
    //
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lr=heights.size(),lc=heights[0].size();
        int n=lr*lc;//total elements
        vector<vector<pair<int,int>>> g(n);
        int mx=INT_MIN;
        makeGraph(lr,lc,heights,g,mx);
        
        int start=0,end=mx;
        int ans=mx;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(traverse(mid,n,g)){
                ans=min(ans,mid);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};