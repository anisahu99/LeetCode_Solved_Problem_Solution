// Algorithm Steps:
// Initialize Variables:

// Initialize the modulo value mod = 1e9 + 7.
// Define a helper function binaryExponentiation to compute exponentiation modulo mod.
// Find First and Last Occurrences:

// Create two hash maps: pos to store the first and last occurrences of distinct elements, and freq to store the frequency of each element in nums.
// Iterate Through the Elements:

// Traverse through the elements in nums.
// Update pos with the first and last occurrences of each distinct element.
// Update freq to keep track of the frequency of each element.
// Prepare Intervals:

// Construct intervals using the first and last occurrences of distinct elements stored in the pos map.
// Store these intervals in a 2D vector intervals.
// Sort Intervals and Find Distinct Intervals:

// Sort the intervals based on the start positions.
// Use the find_distinct_interval function to determine the number of distinct intervals formed.
// Compute Number of Good Partitions:

// Calculate total as the count of distinct intervals.
// Return the result of binaryExponentiation(2, total - 1) as the number of good partitions.
// Code Explanation:
// binaryExponentiation: Implements modular exponentiation efficiently.
// find_distinct_interval: Determines the count of distinct intervals based on the intervals formed by the first and last occurrences of elements in the input intervals.
// numberOfGoodPartitions: Orchestrates the overall process:
// Stores the first and last occurrences of distinct elements.
// Prepares intervals from these occurrences.
// Calculates the count of distinct intervals and returns the count of good partitions.
// This code employs a combination of interval manipulation and modular exponentiation to efficiently count the number of good partitions in a given array of integers.

class Solution {
public:
    // myself
    int mod=1e9+7;
    int binaryExponentiation(int a,int b){
        int ans=1;
        while(b){
            if(b&1){
                ans=(1LL*ans*a)%mod;
            }
            a=(1LL*a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    
    int find_distinct_interval(vector<vector<int>> &intervals,int &sz){
        if(sz==1) return 1;
        int count=1;
        int i=1;
        int first=intervals[0][0];
        int second=intervals[0][1];
        while(i<sz){
            if(second>intervals[i][0]){
                second=max(second,intervals[i][1]);
            }
            else{
                first=intervals[i][0];
                second=intervals[i][1];
                count++;
            }
            i++;
        }
        return count;
    }
    
    int numberOfGoodPartitions(vector<int>& nums) {
        
        // store first and last occurence of distinct element in nums
        unordered_map<int,pair<int,int>> pos;
        
        // store frequency to store first occurence of element
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(freq.find(nums[i])==freq.end()){
                pos[nums[i]].first=i;
            }
            pos[nums[i]].second=i;
            freq[nums[i]]++;
        }
        int sz=pos.size();
        vector<vector<int>> intervals(sz,vector<int>(2,0));
        int i=0;
        for(auto it:pos){
            intervals[i][0]=it.second.first;
            intervals[i][1]=it.second.second;
            i++;
        }
        sort(intervals.begin(),intervals.end());
        int total=find_distinct_interval(intervals,sz);
        return binaryExponentiation(2,total-1);
    }
};

        //for(int j=0;j<sz;j++){
        //     cout<<intervals[j][0]<<", "<<intervals[j][1]<<endl;
        // }
        // for(auto it:pos){
        //     cout<<it.first<<"->("<<it.second.first<<", "<<it.second.second<<")"<<endl;
        // }