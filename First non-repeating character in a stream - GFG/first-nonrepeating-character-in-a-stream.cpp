//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> freq(26);
		    queue<char> q;
		    string ans;
		    for(char &ch:A){
		        if(freq[ch-'a']==0){
		            q.push(ch);
		            freq[ch-'a']++;
		            if(q.size()>0){
		                ans.push_back(q.front());
		            }
		            if(q.size()==0){
		                ans.push_back('#');
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
		            if(q.size()>0){
		                ans.push_back(q.front());
		            }
		            if(q.size()==0){
		                ans.push_back('#');
		            }
		        }
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends