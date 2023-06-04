//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
    string reverseEqn (string s)
        {
            //code here.
            string ans;
            int n=s.length();
            for(int i=n-1;i>=0;i--){
                if(s[i]>='0'&&s[i]<='9'){
                    string num;
                    while(i>=0&&s[i]>='0'&&s[i]<='9'){
                        num.push_back(s[i]);
                        i--;
                    }
                    i++;
                    int k=num.length()-1;
                    while(k>=0){
                        ans.push_back(num[k]);
                        k--;
                    }
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends