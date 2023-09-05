class Solution {
public:
    unordered_map<string,string> parent;
    unordered_map<string,int> rank;
    
    string find(string i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(string x, string y) {  
        string p_x=find(x);
        string p_y=find(y);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_set<string> unique;
        for(vector<string> &v:accounts){
            for(int i=1;i<v.size();i++){
                unique.insert(v[i]);
            }
        }
        int n=unique.size();
        
        for(auto it:unique){
            parent[it]=it;
            rank[it]=1;
        }
        for(vector<string> &v:accounts){
            for(int i=2;i<v.size();i++){
                Union(v[1],v[i]);
            }
        }
        unordered_map<string,vector<string>> list;
        for(auto it:parent){
            find(it.first);
            //find(it.second);
        }
        for(auto it:parent){
            //cout<<it.first<<"-"<<it.second<<endl;
            list[it.second].push_back(it.first);
        }
        
        for(auto it:list){
            bool flag=false;
            for(vector<string> &v:accounts){
                for(int i=1;i<v.size();i++){
                    if(it.first==v[i]){
                        sort(list[it.first].begin(),list[it.first].end());
                        list[it.first].insert(list[it.first].begin(),v[0]);
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            
        }
        vector<vector<string>> res;
        for(auto it:list){
            res.push_back(it.second);
        }
        return res;
    }
};