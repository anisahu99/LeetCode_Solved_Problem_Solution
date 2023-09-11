//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        // code here
        if(n%2==0) return false;
        vector<int> temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        int increment=2;
        while(temp.size()>=increment){
            vector<int> extra;
            for(int i=0;i<temp.size();i++){
                if((i+1)%increment!=0){
                    extra.push_back(temp[i]);
                    //cout<<temp[i]<<", ";
                }
            }
            //cout<<endl;
            temp=extra;
            increment++;
        }
        for(int val:temp){
            if(val==n) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends