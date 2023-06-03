class Solution {
public:
    unordered_map<int,vector<int>> al;
    int ans=0,mx=0;
    void dfs(int manager,vector<int>& informTime){
        mx=max(mx,ans);
        for(auto employee:al[manager]){
            ans+=informTime[manager];
            dfs(employee,informTime);
            ans-=informTime[manager];
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       
       for(int i=0;i<manager.size();i++){
           int el=manager[i];
           if(el!=-1){
               al[el].push_back(i);
           }
       }
        for(auto it:al){
            cout<<it.first<<"->"<<it.second.size()<<endl;
        }
        dfs(headID,informTime);
        return mx;
    }
};