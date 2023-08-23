class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }
        priority_queue<pair<int,char>> pq;
        //int total_char=0;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                //total_char+=freq[i];
                pq.push({freq[i],char(i+'a')});
                //cout<<char(i+'a')<<"-"<<freq[i]<<endl;
            }
        }
        // while(!pq.empty()){
        //     int cnt=pq.top().first;
        //     char curr=pq.top().second;pq.pop();
        //     cout<<curr<<"-"<<cnt<<endl;
        // }
        char prev='$';
        string ans="";
        while(!pq.empty()){
            int cnt=pq.top().first;
            char curr=pq.top().second;pq.pop();
            //cout<<curr<<"-"<<cnt<<endl;
            
            if(prev=='$'||prev!=curr){
                ans+=curr;
                prev=curr;
                if(cnt!=1){
                    pq.push({cnt-1,curr});
                }
                
            }
            else if(prev==curr&&pq.size()){
                char next=pq.top().second;
                int next_cnt=pq.top().first;pq.pop();
                ans+=next;
                prev=next;
                if(next_cnt!=1){
                    pq.push({next_cnt-1,next});
                    
                }
                if(cnt>=1){
                    pq.push({cnt,curr});
                }
            }
            else{
                return "";
            }
        }
        return ans;
    }
};