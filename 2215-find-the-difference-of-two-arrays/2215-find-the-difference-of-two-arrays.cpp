class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>>res;
            vector<int>res1;
            vector<int>res2;
            unordered_set<int>m1;
            unordered_set<int>m2;
            for(int i=0;i<nums1.size();i++){
                    m1.insert(nums1[i]);
            }
            for(int i=0;i<nums2.size();i++){
                    if(m1.find(nums2[i])!=m1.end()){
                            m1.erase(nums2[i]);
                    }
                    m2.insert(nums2[i]);
            }
            for(int i=0;i<nums1.size();i++){
                    if(m2.find(nums1[i])!=m2.end()){
                            m2.erase(nums1[i]);
                    }
            }
            for(auto it:m1)
                    res1.push_back(it);
            for(auto it:m2)
                    res2.push_back(it);
            res.push_back(res1);
            res.push_back(res2);
            return res;
    }
};