int new_row=row+lu[k].first;
int new_col=col+lu[k].second;
string str=path;
if(k==0){
str=str+","+"left";
}
else{
str=str+","+"up";
}
int res=back(new_row,new_col,grid,str);
if(res==INT_MIN) continue;
ans=max(ans,temp+res);
}
grid[row][col]=temp;
vis[row][col]=pre_vis;
return ans;
}
int cherryPickup(vector<vector<int>>& grid) {
n=grid.size();
vis.resize(n,vector<int>(n));
int res=dfs(0,0,grid,"");
return res==INT_MIN?0:res;
}
};
​
[[0,1,-1],[1,0,-1],[1,1,1]]
[[1,1,-1],[1,-1,1],[-1,1,1]]
[[1,1,1,0,-1],[0,0,1,0,0],[0,0,1,0,1],[1,0,1,0,0],[-1,0,1,1,1]]
[[1]]