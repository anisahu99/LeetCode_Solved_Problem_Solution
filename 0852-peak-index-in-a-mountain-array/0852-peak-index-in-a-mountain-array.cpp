class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int ans=-1;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                ans=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};