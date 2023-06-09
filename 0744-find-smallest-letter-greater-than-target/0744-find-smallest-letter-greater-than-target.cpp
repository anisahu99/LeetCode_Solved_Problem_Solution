class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(letters[mid]>target){
                end=mid-1;
            }
            else if(letters[mid]<=target){
                start=mid+1;
            }
        }
        if(start<0||start>=n)
            return letters[0];
        return letters[start];
    }
};