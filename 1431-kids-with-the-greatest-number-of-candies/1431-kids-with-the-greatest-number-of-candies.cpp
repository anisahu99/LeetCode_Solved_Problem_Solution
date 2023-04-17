class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int mx=0;
        for(int &candy:candies){
            mx=max(candy,mx);
        }
        for(int &candy:candies){
            if(extraCandies+candy>=mx){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};