//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int N,int M,int k)
    {
 		// Your code goes here.
 		int MXR=N-1,MXC=M-1;
 		int MNR=0,MNC=0;
 		int cnt=0;
 		int ans=-1;
 		while(cnt<k){
 		    //upper wall
 		    for(int i=MNR,j=MNC;j<=MXC&&cnt<k;j++){
 		        ans=a[i][j];
 		     //   cout<<a[i][j]<<" ";
 		        cnt++;
 		    }
 		    MNR++;
 		    //right wall
 		    for(int i=MNR,j=MXC;i<=MXR&&cnt<k;i++){
 		        ans=a[i][j];
 		     //   cout<<a[i][j]<<" ";
 		        cnt++;
 		    }
 		    MXC--;
 		    //bottom wall
 		    for(int i=MXR,j=MXC;j>=MNC&&cnt<k;j--){
 		        ans=a[i][j];
 		     //   cout<<a[i][j]<<" ";
 		        cnt++;
 		    }
 		    MXR--;
 		    //left wall
 		    for(int i=MXR,j=MNC;i>=MNR&&cnt<k;i--){
 		        ans=a[i][j];
 		     //   cout<<a[i][j]<<" ";
 		        cnt++;
 		    }
 		    MNC++;
 		}
 		return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends