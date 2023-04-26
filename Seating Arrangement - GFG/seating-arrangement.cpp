//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        int available_seats=0;
        int i=0;
        int cnt_vacant=0;
        int restrict=0;
        while(i<m){
            if(seats[i]==0){
                if(i-1>=0&&seats[i]!=seats[i-1]){
                    //restrict++;
                    cnt_vacant-=1;
                }
                    cnt_vacant++;
            }
            else{
                if(i-1>=0&&seats[i]!=seats[i-1]){
                    //restrict++;
                    cnt_vacant-=1;
                }
                if(cnt_vacant>0){
                    available_seats+=(cnt_vacant/2+cnt_vacant%2);
                }
                cnt_vacant=0;
            }
            i++;
        }
        if(cnt_vacant>0){
                    available_seats+=(cnt_vacant/2+cnt_vacant%2);
                }
        if(available_seats>=n){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends