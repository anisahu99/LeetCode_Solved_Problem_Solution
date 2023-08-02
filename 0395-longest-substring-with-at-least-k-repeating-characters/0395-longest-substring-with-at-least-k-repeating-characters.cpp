class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        if(n==0||n<k) return 0;
        if(k<=1) return n;
        
        unordered_map<char,int> count;
        for(char &ch:s) count[ch]++;
        int l=0;
        while(l<n&&count[s[l]]>=k) l++;
        if(l>=n-1) return l;
        
        int ans1=longestSubstring(s.substr(0,l),k);
        
        while(l<n&&count[s[l]]<k) l++;
        
        int ans2=(l<n)?longestSubstring(s.substr(l),k):0;
        return max(ans1,ans2);
    }
};