
class Solution {
public:
    // myself
    long long countSubarrays(vector<int>& nums, int k) {
        
        // find Max Element from given vector
        int max_ele=0;
        for(int &num:nums){
            max_ele=max(max_ele,num);
        }
        // slide the window
        int index=-1;
        // index store occurence of max_ele in previous window
        // it uses for no count the overlapping subarray in answer(total).
        int i=0,j=0,n=nums.size();
        int max_count=0;
        long long total=0;
        while(j<n){
            if(nums[j]==max_ele) max_count++;
            
            // make window minimum size with atleast k max_ele
            while(max_count==k&&nums[i]!=max_ele) i++;
            
            // count the possible subarray
            if(max_count==k){
                
                // find length of left side of window from first occurence of max_ele to i
                long long l1=(i-index-1);
                // find length of right side of window from last occurence of max_ele to (n-1)
                long long l2=(n-j-1);
                // count total possible subarray
                total+=l1+l2+l1*l2+1;
                // s[i]==max_ele
                // we will decrease count of max_ele
                // because we will slide the i to i+1 ()
                max_count-=1;
                // we will store first occurence of max_ele in current window
                // for future calculations.
                index=i;
                // slide i to i+1.
                i++;
            }
            j++;
        }
        return total;
    }
};