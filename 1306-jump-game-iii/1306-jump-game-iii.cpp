class Solution {
public:
    bool reach(int i,int n,vector<int>& arr){
        if(i<0||i>=n) return false;
        if(arr[i]==0) return true;
        
        bool left=false;
        if(arr[i]!=-1){
            int temp=arr[i];
            arr[i]=-1;
            left=reach(i-temp,n,arr);
            arr[i]=temp;
        }
        if(left) return true;
        bool right=false;
        if(arr[i]!=-1){
            int temp=arr[i];
            arr[i]=-1;
            right=reach(i+temp,n,arr);
            arr[i]=temp;
        }
        return right;
    }
    bool canReach(vector<int>& arr, int start) {
        //visited array
        return reach(start,arr.size(),arr);
    }
};