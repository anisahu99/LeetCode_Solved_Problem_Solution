class Solution {
public:
    int calculate(string s) {
        stack<pair<int,char>> st;
        int n=s.length();
        long long sum=0;
        int sign=1;
        
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                long long num=0;
                while(i<n&&s[i]>='0'&&s[i]<='9'){
                    num=(num*10)+(s[i]-'0');
                    i++;
                }
                i--;
                sum+=(sign)*num;
                sign=1;
            }
            else if(s[i]=='('){
                st.push({sum,sign});
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }
            else if(s[i]=='-'){
                sign=(-1*sign);
            }
            
        }
        return sum;
    }
};