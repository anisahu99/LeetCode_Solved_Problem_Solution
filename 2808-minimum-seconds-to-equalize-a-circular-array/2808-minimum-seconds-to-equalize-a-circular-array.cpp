class Solution {
public:
    
    int minimumTime(int &n,vector<int> &index){
        int Max_Seconds=0;
        for(int i=0;i<index.size();i++){
            if(i!=index.size()-1){
                int number_of_seconds=(index[i+1]-index[i])/2;
                Max_Seconds=max(Max_Seconds,number_of_seconds);
            }
            else{
                int number_of_seconds=(index[0]+n-index[i])/2;
                Max_Seconds=max(Max_Seconds,number_of_seconds);
            }
        }
        return Max_Seconds;
    }
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        
        //pos=every element ocurrence index
        unordered_map<int,vector<int>> pos;
        
        for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        
        int time=INT_MAX;
        
        for(auto it:pos){
            time=min(time,minimumTime(n,it.second));
        }
        return time;
    }
};