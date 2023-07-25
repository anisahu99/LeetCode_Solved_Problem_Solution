class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        while(mid>0&&mid<e){
            if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]>arr[mid]&&arr[mid]>arr[mid+1]){
                mid=mid-1;
            }else if(arr[mid-1]<arr[mid]&&arr[mid]<arr[mid+1]){
                mid=mid+1;
            }
        }
        return mid;
    }
};