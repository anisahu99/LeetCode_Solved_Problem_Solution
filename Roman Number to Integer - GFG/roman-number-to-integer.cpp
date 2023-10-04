//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int> mp1={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        unordered_map<string,int> mp2={{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        
        int n=s.length();
        int ans=0;
        int i=0;
        while(i+1<n){
            string s1="";
            s1+=s[i];
            s1+=s[i+1];
            if(mp2.find(s1)!=mp2.end()){
                ans+=mp2[s1];
                i+=2;
            }
            else{
                ans+=mp1[s[i]];
                i++;
            }
        }
        if(i==n-1){
            ans+=mp1[s[i]];
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends