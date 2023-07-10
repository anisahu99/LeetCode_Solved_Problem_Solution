//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        if(t.length() > s.length()) return "-1";
        if(s == t) return s;
        
        int i=0, j =0, minLen =INT_MAX, start =-1, cnt =0;
        
        vector<int> mpp(26,0);
        for(auto ch: t){ 
            if(mpp[ch-'a'] == 0) cnt++;
            mpp[ch-'a']++;
        }

        while(j<s.length()){
            mpp[s[j] -'a']--;
            if(mpp[s[j] -'a'] == 0) cnt--;

            if(cnt == 0){       
                while(cnt == 0){
                    if(j-i+1 < minLen){                     
                        start= i;
                        minLen= j-i+1;
                    }
                    mpp[s[i]-'a']++;
                    if(mpp[s[i] -'a'] == 1) cnt++;
                    i++;
                }
            }
            j++;
        }

        if(minLen == INT_MAX) return "-1";
        else return s.substr(start,minLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends