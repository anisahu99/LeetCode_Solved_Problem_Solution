//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
class compare{
    public:
    bool operator()(const struct val &p1,const struct val &p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
};
class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        compare cmp;
        sort(p,p+n,cmp);
        // for(int i=0;i<n;i++){
        //     cout<<"{"<<p[i].first<<","<<p[i].second<<"}"<<endl;
        // }
        int pre=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++){
            if(p[i].first>p[i].second) continue;
            if(p[i].first>pre){
                ans++;
                pre=p[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends