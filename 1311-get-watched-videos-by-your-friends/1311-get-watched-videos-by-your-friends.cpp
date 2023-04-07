class Solution {
public:
    
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> mt;
        int n=friends.size();
        vector<int> vis(n,0);
        queue<pair<int, int>>q;
        q.push({id, 0});
        vis[id] = true;
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            if(node.second == level){
                for(string str:watchedVideos[node.first]){
                    mt[str]++;
                }
                continue;
            }
            
            for(int next_node:friends[node.first]){
                if(!vis[next_node]){
                    vis[next_node] = true;
                    q.push({next_node, node.second+1});
                }
            }
        }
        
        vector<pair<int, string>> movies;
        for(auto i:mt) movies.push_back({i.second,i.first});
        sort(movies.begin(), movies.end());
        vector<string>ans;
        for(auto i:movies) ans.push_back(i.second);
        return ans;
    }
};