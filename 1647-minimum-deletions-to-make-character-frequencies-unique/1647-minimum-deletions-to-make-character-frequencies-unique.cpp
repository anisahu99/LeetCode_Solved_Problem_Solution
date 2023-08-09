class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        //map<char,int> mp;
        for(char &ch:s){
            freq[ch-'a']++;
            //mp[ch]++;
        }
        // for(auto it:mp){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        int cnt=0;
        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<26;i++){
                if(freq[i]==0) continue;
                //cout<<char(i+'a')<<endl;
                for(int j=0;j<26;j++){
                    if(i!=j&&freq[i]!=0&&freq[j]!=0&&freq[i]==freq[j]){
                        freq[j]--;
                        cnt++;
                        flag=true;
                    }
                }
            }
        }
        return cnt;
    }
};