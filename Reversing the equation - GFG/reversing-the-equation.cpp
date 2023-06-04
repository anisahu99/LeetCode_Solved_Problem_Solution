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
            stack<char> st;
            int n=s.length();
            for(int i=0;i<n;i++){
                if(s[i]>='0'&&s[i]<='9'){
                    string num;
                    while(i<n&&s[i]>='0'&&s[i]<='9'){
                        num.push_back(s[i]);
                        i++;
                    }
                    i--;
                    int k=num.length()-1;
                    while(k>=0){
                        st.push(num[k]);
                        k--;
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            string ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
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