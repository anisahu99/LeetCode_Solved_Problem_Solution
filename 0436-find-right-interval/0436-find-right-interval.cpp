class Solution {
public:
    int search(int j,int n,int val,vector<vector<int>>& intervals){
        int ans=-1;
        int start=j,end=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(intervals[mid][0]==val){
                return mid;
            }
            else if(intervals[mid][0]>val){
                ans=mid;
                end=mid-1;
            }
            else if(intervals[mid][0]<val){
                start=mid+1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        int i=0;
        vector<int> ans(n,-1);
        while(i<n){
            int starti=intervals[i][0];int endi=intervals[i][1];
            int j=search(i,n-1,endi,intervals);
            //cout<<j<<endl;
            if(j!=-1){
                ans[intervals[i][2]]=intervals[j][2];
            }
            else{
                ans[intervals[i][2]]=-1;
            }
            i++;
        }
        return ans;
    }
};