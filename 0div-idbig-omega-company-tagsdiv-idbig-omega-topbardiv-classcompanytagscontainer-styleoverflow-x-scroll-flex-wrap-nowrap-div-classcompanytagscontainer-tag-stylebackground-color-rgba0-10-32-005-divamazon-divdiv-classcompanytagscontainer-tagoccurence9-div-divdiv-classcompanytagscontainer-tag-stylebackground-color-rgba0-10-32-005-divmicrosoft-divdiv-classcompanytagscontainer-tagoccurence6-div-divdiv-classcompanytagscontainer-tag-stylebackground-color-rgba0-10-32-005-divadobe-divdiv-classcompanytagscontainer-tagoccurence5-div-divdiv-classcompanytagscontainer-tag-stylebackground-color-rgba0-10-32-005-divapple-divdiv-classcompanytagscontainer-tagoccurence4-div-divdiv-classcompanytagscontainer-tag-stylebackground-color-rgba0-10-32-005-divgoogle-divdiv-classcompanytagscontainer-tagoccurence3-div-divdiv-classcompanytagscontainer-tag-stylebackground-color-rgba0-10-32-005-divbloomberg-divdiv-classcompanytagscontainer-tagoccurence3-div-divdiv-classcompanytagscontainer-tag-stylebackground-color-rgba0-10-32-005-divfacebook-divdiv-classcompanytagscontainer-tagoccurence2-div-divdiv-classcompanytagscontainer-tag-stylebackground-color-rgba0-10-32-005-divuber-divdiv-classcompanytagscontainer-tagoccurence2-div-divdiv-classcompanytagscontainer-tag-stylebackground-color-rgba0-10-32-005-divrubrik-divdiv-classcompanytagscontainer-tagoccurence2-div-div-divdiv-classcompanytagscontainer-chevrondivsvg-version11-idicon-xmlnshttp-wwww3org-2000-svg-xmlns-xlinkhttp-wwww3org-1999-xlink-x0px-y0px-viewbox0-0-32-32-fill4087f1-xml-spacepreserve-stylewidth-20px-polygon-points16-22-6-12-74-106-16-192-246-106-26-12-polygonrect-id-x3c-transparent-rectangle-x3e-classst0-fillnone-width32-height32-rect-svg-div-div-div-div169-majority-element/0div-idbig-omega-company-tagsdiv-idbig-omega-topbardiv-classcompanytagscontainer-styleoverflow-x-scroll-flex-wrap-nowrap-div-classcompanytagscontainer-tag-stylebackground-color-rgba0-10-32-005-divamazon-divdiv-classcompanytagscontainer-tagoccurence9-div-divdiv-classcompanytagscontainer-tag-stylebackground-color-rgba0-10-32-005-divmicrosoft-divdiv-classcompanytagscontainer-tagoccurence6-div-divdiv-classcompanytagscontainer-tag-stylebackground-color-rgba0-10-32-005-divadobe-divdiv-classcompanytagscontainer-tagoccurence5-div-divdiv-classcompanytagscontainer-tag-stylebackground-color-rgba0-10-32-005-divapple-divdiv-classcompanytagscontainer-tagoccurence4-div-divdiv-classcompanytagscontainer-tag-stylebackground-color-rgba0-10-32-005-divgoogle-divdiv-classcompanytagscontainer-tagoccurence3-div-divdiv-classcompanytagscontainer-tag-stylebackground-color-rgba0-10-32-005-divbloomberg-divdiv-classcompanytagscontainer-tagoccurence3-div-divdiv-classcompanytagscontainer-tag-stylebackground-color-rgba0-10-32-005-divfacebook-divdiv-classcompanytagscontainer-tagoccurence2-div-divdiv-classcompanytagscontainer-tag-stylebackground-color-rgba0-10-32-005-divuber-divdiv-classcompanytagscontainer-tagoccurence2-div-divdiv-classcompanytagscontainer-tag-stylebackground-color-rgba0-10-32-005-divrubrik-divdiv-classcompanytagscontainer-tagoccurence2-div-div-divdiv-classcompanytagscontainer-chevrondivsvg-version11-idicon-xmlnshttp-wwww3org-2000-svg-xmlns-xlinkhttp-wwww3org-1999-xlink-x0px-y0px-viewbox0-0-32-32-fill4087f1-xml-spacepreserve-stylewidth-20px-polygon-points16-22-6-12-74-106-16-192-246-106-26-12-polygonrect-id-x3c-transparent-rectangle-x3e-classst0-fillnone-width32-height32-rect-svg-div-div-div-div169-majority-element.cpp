

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;
        //int occ=(n/2)+1;
        //possible elements
        // possible_element=n/occ;
        // after observation for every value of possile elements is equal to 1;
        for(int i = 0; i<n; i++) {
            if(nums[i] == maj) {
                count++;
            } else if(count == 0) {
                maj = nums[i];
                count = 1;
            } else {
                count--;
            }

        }

        return maj;
    }
};