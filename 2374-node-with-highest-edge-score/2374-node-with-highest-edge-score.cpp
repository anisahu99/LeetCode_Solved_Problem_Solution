class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> edge_score(n,0);
        long long mx_val=INT_MIN;
        int mx_node=-1;
        for(int i=0;i<n;i++){
            edge_score[edges[i]]+=i;
        }
        
        for(int i=0;i<n;i++){
            if(edge_score[i]>mx_val){
                mx_val=edge_score[i];
                mx_node=i;
            }
        }
        return mx_node;
    }
};