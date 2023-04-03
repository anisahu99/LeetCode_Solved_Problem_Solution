class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < size(s); ) {
            int zeros = 0;
            while (i < size(s) && s[i] == '0') { ++i; ++zeros; }
            int ones = 0;
            while (i < size(s) && s[i] == '1') { ++i; ++ones; }
            ans = max(ans, min(zeros, ones) * 2);
        }

        return ans;
    }
};