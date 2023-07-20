//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       vector<int> freq(26);
       queue<char> q;
       char first='$';
       for(char &ch:S){
           if(freq[ch-'a']==0){
               freq[ch-'a']++;
               q.push(ch);
               if(q.size()){
                   first=q.front();
               }
               if(q.size()==0){
                   first='$';
               }
           }
           else{
               int sz=q.size();
               for(int i=0;i<sz;i++){
                   if(q.front()!=ch){
                       q.push(q.front());
                       q.pop();
                   }
                   else{
                       q.pop();
                   }
               }
               if(q.size()&&q.front()==ch){
                   q.pop();
               }
               if(q.size()){
                   first=q.front();
               }
               if(q.size()==0){
                   first='$';
               }
           }
       }
       return first;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends