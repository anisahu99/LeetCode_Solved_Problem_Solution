//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int cnt=0;
        int ans=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                flag=true;
                if(cnt>0){
                    ans++;
                }
                cnt=0;
            }else{
                cnt++;
            }
        }
        if(ans>0){
            if(cnt>0){
                ans++;
            }
        }
        if(ans==0&&!flag)
        return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends