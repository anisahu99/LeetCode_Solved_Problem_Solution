class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        int nq = q.size();
        vector<int> ans(nq,0);
        
        if(n==1) return ans;
        
        vector<int> arr(n,0);
        
        int tcol=0;
        
        for(int i=0;i<nq;i++){
            
            int id=q[i][0];
            int col=q[i][1];
            
            if(id==0){
                int pval=(arr[id]==arr[id+1]);
                if(arr[id]!=0)
                    tcol-=pval;
                arr[id]=col;
                int nval=(arr[id]==arr[id+1]);
                tcol+=nval;
                
                ans[i]=tcol;
            }
            else if(id==n-1){
                int pval=(arr[id]==arr[id-1]);
                if(arr[id]!=0)
                    tcol-=pval;
                arr[id]=col;
                int nval=(arr[id]==arr[id-1]);
                tcol+=nval;
                
                ans[i]=tcol;
            }
            else{
                int pval=(arr[id]==arr[id-1])+(arr[id]==arr[id+1]);
                if(arr[id]!=0)
                    tcol-=pval;
                arr[id]=col;
                int nval=(arr[id]==arr[id-1])+(arr[id]==arr[id+1]);
                tcol+=nval;
                
                ans[i]=tcol;
            }
        }
        return ans;
    }
};