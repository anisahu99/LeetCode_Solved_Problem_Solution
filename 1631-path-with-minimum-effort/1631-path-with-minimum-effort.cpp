class Solution {
public:
    vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};
    //with the help of node matrix we do numbering to make cell a node with specific value
    
    // {
    //     {0,1,2},
    //     {3,4,5},
    //     {6,7,8}
    // }
    void help(int &lr,int& lc,vector<vector<int>>& node){
        int i=0;
        for(int row=0;row<lr;row++){
            for(int col=0;col<lc;col++){
                node[row][col]=i;
                i++;
            }
        }
    }
    //make weighted graph between these adjacent nodes
    void makeGraph(int &lr,int &lc,vector<vector<int>>& heights,vector<vector<int>> &node,vector<vector<pair<int,int>>> &g,int &mx){
        
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
                        g[node[row][col]].push_back({node[r][c],abs(heights[row][col]-heights[r][c])});
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
        int n=lr*lc;
        vector<vector<int>> node(lr,vector<int>(lc,0));
        vector<vector<pair<int,int>>> g(n);
        int mx=INT_MIN;
        help(lr,lc,node);
        makeGraph(lr,lc,heights,node,g,mx);
        
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