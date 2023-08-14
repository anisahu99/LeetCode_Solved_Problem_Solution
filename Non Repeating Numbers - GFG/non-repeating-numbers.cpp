//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorr=0;
        for(int &val:nums){
            xorr^=val;
        }
        int rmsbm=xorr&(-xorr);
        xorr=0;
        int xor1=0;
        for(int &val:nums){
            if(rmsbm&val){
                xorr^=val;
            }
            else{
                xor1^=val;
            }
        }
        vector<int> ans;
        if(xorr>xor1){
            ans.push_back(xor1);
            ans.push_back(xorr);
        }
        else{
            ans.push_back(xorr);
            ans.push_back(xor1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends