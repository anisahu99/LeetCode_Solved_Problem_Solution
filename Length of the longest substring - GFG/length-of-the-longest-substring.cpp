//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int n=s.length();
        if(n==0) return 0;
        int i=0,j=0,maxlen=0;
        vector<int>mp(26,0);
        while(j<n){
            if(mp[s[j]-'a']==0){
                mp[s[j]-'a']++;
              maxlen=max(maxlen,j-i+1);
                
            }
            else{
                while(mp[s[j]-'a']>=1){
                    mp[s[i]-'a']--;
                    i++;
                }
                mp[s[j]-'a']++;
            }
            j++;
        }
        
        return maxlen;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends