class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        int maxi=INT_MIN;
        vector<vector<int>> graph(n+1);

        //creation of graph
        for(auto it: edges){
            graph[it[0]].push_back(vals[it[1]]); //storing the value of adj node in prev node
            graph[it[1]].push_back(vals[it[0]]); 
        }

        for(int i=0; i<n; i++){
            sort(graph[i].begin(), graph[i].end(), greater<int>());
            int sum=0;
            sum=vals[i]; //the value of the node on which you are
            //you need to consider the value of node as well

            for(int j=0; j<k && j<graph[i].size(); j++){ //extra condition to avoid runtime error
                if(graph[i][j]<0)
                    break;
                sum+=graph[i][j]; //comparing with 0, while taking sum
                //to avoid negative numbers in sum
            }
            
            maxi=max(maxi, sum); //taking the maximum possible sum
        }
        return maxi;
    }
};