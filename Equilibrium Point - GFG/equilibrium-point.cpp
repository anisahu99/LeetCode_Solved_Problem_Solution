//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int right=0;
        for(int i=0;i<n;i++){
            right+=a[i];
        }
        int left=0;
        if(left==right) return 0;
        right-=a[0];
        if(left==right) return 0+1;
        for(int i=1;i<n;i++){
            left+=a[i-1];
            right-=a[i];
            if(left==right) return i+1;
        }
        return -1;
    }

};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends