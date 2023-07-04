class Solution {
public:
    
    int solve(int i,int n,vector<int>& res,vector<vector<int>>& requests){
        
        if(i==requests.size()){
            for(int j=0;j<n;j++){
                if(res[j]!=0){
                    return INT_MIN;
                }
            }
            return 0;
        }
        
        int not_take=0+solve(i+1,n,res,requests);
        
        //take
        res[requests[i][0]]--;res[requests[i][1]]++;
        int take=1+solve(i+1,n,res,requests);
        res[requests[i][0]]++;res[requests[i][1]]--;
        
        return max(take,not_take);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> res(n,0);
        return solve(0,n,res,requests);
    }
};