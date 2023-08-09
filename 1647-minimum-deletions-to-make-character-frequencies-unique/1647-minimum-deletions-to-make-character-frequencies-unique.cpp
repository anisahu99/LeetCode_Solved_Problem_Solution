class Solution {
public:
    int minDeletions(string &s) {
        vector<int> freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        
        int cnt=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            for(int j=i+1;j<26;j++){
                if(freq[j]==0) continue;
                if(freq[i]==freq[j]){
                    freq[j]--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};