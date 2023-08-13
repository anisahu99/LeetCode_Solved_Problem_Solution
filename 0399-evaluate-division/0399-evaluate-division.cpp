class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Write your code here.
    int n=equations.size();
    unordered_map<string,vector<pair<string,double>>> mp;
    for(int i=0;i<n;i++){
        string n=equations[i][0];
        string d=equations[i][1];
        double val=values[i];
        mp[n].push_back({d,val});
        mp[d].push_back({n,1.0/val});
    }
    int s=queries.size();
    vector<double> ans(s,-1.0);
    for(int i=0;i<s;i++){
        string start=queries[i][0];
        if(mp.find(start)==mp.end()) continue;
        string target=queries[i][1];
        queue<pair<string,double>> q;
        q.push({start,1.00});
        unordered_set<string> seen;
        seen.insert(start);
        while(!q.empty()){
            string node=q.front().first;
            double val=q.front().second;q.pop();
            if(node==target){
                ans[i]=val;
                break;
            }

            for(pair<string,double> &next:mp[node]){
                string adj=next.first;
                double v=next.second;
                if(seen.find(adj)==seen.end()){
                    seen.insert(adj);
                    q.push({adj,val*v});
                }
            }
        }
    }
    return ans;
    }
};