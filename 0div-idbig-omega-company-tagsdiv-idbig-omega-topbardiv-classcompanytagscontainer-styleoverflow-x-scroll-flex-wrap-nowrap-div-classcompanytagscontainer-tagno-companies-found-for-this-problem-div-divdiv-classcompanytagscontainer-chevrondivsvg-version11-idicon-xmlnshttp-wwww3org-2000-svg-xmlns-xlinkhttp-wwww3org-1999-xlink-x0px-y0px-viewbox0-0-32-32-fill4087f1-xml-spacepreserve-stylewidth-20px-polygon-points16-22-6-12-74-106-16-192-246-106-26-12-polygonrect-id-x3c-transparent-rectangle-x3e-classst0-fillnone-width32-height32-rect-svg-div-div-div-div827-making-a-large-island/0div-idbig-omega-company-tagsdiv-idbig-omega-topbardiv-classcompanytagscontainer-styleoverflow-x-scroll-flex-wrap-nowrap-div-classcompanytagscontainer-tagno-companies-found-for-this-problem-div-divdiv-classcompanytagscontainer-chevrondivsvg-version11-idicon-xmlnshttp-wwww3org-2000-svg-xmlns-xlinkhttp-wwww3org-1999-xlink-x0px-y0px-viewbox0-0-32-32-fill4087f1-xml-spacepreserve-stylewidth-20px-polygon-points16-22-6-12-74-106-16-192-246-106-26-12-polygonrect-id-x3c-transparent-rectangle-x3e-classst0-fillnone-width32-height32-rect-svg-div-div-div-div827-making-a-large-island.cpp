class Solution {
public:
    vector<int> size;
    vector<int> parent;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    
    void Union_Size(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            if(size[x]>=size[y]){
                parent[py]=px;
                size[px]+=size[py];
            }
            else if(size[py]>size[px]){
                parent[px]=py;
                size[y]+=size[px];
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        size.resize(m*m,1);
        parent.resize(m*m);
        for(int i=0;i<m*m;i++){
            parent[i]=i;
        }
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(int row=0;row<m;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]){
                    for(int k=0;k<4;k++){
                        int nr=row+dir[k].first;
                        int nc=col+dir[k].second;
                        if(nr>=0&&nr<m&&nc>=0&&nc<m&&grid[nr][nc]){
                            Union_Size((row*m+col),(nr*m+nc));
                        }
                    }
                }
            }
        }
        int ans=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<m;col++){
                if(!grid[row][col]){
                    unordered_set<int> total_comp;
                    int cnt=1;
                    for(int k=0;k<4;k++){
                        int nr=row+dir[k].first;
                        int nc=col+dir[k].second; 
                        if(nr>=0&&nr<m&&nc>=0&&nc<m&&grid[nr][nc]&&total_comp.find(find(nr*m+nc))==total_comp.end()){
                            total_comp.insert(find(nr*m+nc));
                            cnt+=size[find(nr*m+nc)];
                        }
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        
        for(int i=0;i<m*m;i++){
            ans=max(ans,size[i]);
        }
        return ans;
    }
};