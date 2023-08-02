class Solution {
public:
    int find_length(vector<int>& freq,int k){
        int ans=0;
        for(int &val:freq){
            if(val>=k){
                ans+=val;
            }
            else if(val!=0){
                return 0;
            }
        }
        
        return ans;
    }
    int longestSubstring(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int ln=find_length(freq,k);
                //cout<<ln<<",";
                ans=max(ans,ln);
            }
            //cout<<endl;
        }
        return ans;
    }
};