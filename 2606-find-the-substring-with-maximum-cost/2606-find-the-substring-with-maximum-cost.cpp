class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> m;
        int n=s.length();
        for(int i=0;i<chars.length();i++){
            m[chars[i]]=vals[i];
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                v.push_back(s[i]-'a'+1);
            }
            else{
                v.push_back(m[s[i]]);
            }
        }
        int ans=INT_MIN;
        int sum=0;
        for(int val:v){
            sum+=val;
            if(sum<0)
                sum=0;
            ans=max(ans,sum);
        }
        return ans;
    }
};