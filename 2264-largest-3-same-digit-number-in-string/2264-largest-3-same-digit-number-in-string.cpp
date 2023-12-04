class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int i=1,n=num.length();
        int cnt=1;
        int digit=0;
        while(i<n){
            if(num[i-1]!=num[i]){
                cnt=1;
                //cout<<i<<",s, "<<num[i]<<endl;
            }if(num[i-1]==num[i]){
                cnt++; 
                // cout<<i<<",f, "<<num[i]<<endl;
            }if(cnt==3&&num[i]-'0'>digit||ans==""&&cnt==3){
                cnt=1;
                digit=num[i]-'0';
                ans="";
                ans.push_back(num[i]);                
                ans.push_back(num[i]);                
                ans.push_back(num[i]);
            }
            
            i++;
        }
        return ans;
    }
};