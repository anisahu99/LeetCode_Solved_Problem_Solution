class Solution {
public:
     vector<int> parent,rank;
    
    int find_parent(int x){
        if(parent[x]==x) return x;
        parent[x]=find_parent(parent[x]);
        return parent[x];
    }
    void find_union(int x,int y,int x_parent,int y_parent){
        // int x_parent=find_parent(x);
        // int y_parent=find_parent(y);
        if(x_parent==y_parent) return;
        
        if(rank[x_parent]==rank[y_parent]){
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
        else{
            if(rank[x_parent]>=rank[y_parent]){
                parent[y_parent]=x_parent;
            }
            else{
                parent[x_parent]=y_parent;
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1&&++indegree[leftChild[i]]>1){
                return false;
            }
            if(rightChild[i]!=-1&&++indegree[rightChild[i]]>1){
                return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){
                    return false;
                }
                root=i;
            }
        }
        if(root==-1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                int x_parent=find_parent(i);
                int y_parent=find_parent(leftChild[i]);
                find_union(i,leftChild[i],x_parent,y_parent);
                }
            if(rightChild[i]!=-1){
                int x_parent=find_parent(i);
                int y_parent=find_parent(rightChild[i]);
                find_union(i,rightChild[i],x_parent,y_parent);
                }
        }
        int component=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                component++;
                if(component>1){
                    return false;
                }
            }
        }
        return true;
    }
};