class compare{
    public:
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
        return (p1.first+p1.second<p2.first+p2.second);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                
                if(pq.size()<k){
                    pq.push({nums1[i],nums2[j]});
                }
                else if(pq.top().first+pq.top().second>nums1[i]+nums2[j]){
                    pq.pop();
                    pq.push({nums1[i],nums2[j]});
                    
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first,pq.top().second});
           // cout<<pq.top().first<<":"<<pq.top().second<<endl;
            pq.pop();
        }
        
        return ans;
    }
};
                                       
                                       
                                       
                                       
                                       