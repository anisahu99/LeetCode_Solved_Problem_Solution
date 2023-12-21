class Solution {
public:
    // myself
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<pair<int,int>> order;
        for(int i=0;i<n;i++){
            order.push_back({ratings[i],i});
        }
        sort(order.begin(),order.end());
        // sort rating
        vector<int> res(n);
        // distribute in ascending order
        // if child`s rating greater than neighbouring child`s rating then we give extra one
        for(int j=0;j<n;j++){
            int rating=order[j].first;
            int idx=order[j].second;
            int candy=0;
            if(idx-1>=0&&rating>ratings[idx-1]){
                candy=max(candy,res[idx-1]);
            }
            if(idx+1<n&&rating>ratings[idx+1]){
                candy=max(candy,res[idx+1]);
            }
            res[idx]=1+candy;
        }
        // count all the given candies
        int count=0;
        for(int &c:res){
            count+=c;
        }
        return count;
    }
};