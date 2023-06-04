//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// this question based on suffix array sum;

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2=0,sum3=0,i1=0,i2=0,i3=0;
        for(int &val:S1){
            sum1+=val;
        }
        for(int &val:S2){
            sum2+=val;
        }
        for(int &val:S3){
            sum3+=val;
        }
        while(i1<N1&&i2<N2&&i3<N3){
            if(sum1==sum2&&sum2==sum3){
                return sum1;
            }
            if(sum1>sum2||sum1>sum3){
                sum1-=S1[i1++];
            }
            if(sum2>sum1||sum2>sum3){
                sum2-=S2[i2++];
            }
            if(sum3>sum1||sum3>sum2){
                sum3-=S3[i3++];
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends