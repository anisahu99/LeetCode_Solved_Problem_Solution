//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void solve(string S,string asf,set<string>& st){
	    if(S.length()==0){
	        st.insert(asf);
	        return;
	    }
	    
	    
	    for(int i=0;i<S.length();i++){
	            string l=S.substr(0,i);
    	        string r=S.substr(i+1);
    	        solve(l+r,asf+S[i],st);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    set<string> st;
		    solve(S,"",st);
		    for(auto it:st){
		        ans.push_back(it);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends