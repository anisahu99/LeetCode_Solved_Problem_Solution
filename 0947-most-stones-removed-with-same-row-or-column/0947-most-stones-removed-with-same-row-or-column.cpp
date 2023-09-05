class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {  
        int p_x=find(x);
        int p_y=find(y);
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_y] = p_x;
                rank[p_x]++;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]){
                    Union(i,j);
                }
                else if(stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int compo=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]) compo++;
        }
        
        return n-compo;
        
    }
};