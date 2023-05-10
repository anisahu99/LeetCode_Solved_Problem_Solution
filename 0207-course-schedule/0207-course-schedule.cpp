class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(vector<int>& edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        int seen=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                seen++;
            }
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            for(int next:adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                    seen++;
                }
            }
        }
        if(seen==numCourses)
            return true;
        return false;
        
    }
};