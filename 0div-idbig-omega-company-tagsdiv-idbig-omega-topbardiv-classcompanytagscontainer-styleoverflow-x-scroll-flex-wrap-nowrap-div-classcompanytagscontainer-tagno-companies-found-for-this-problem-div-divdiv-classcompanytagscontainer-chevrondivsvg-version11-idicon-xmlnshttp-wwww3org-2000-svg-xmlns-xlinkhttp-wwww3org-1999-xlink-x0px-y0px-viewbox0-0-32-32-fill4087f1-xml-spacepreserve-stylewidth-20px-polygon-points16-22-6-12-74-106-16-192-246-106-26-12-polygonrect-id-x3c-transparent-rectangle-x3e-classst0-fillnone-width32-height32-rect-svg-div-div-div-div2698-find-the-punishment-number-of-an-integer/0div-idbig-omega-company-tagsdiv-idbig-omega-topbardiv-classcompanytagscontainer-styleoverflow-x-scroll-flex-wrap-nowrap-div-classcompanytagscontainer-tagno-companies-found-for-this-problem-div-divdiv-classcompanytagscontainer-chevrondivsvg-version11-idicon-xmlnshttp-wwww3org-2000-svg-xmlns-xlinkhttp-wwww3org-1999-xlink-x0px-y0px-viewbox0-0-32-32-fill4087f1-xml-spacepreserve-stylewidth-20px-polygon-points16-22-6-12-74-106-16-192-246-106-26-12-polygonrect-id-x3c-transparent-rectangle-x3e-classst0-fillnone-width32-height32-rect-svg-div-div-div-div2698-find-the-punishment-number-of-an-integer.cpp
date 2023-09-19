class Solution {
public:
    //(36,"1296",0)
    //for 1296 we try break into substring such that sum of the integer values of these substrings equals to target 
    bool brute(int &i,string num,int sum){
        if(num==""&&sum==i){
            //cout<<sum<<endl;
            return true;
        }
        int numI=0;
        string pre="";
        for(int l=1;l<=num.size();l++){
            pre+=num[l-1];
            string ros=num.substr(l);
            //cout<<"length "<<l<<"-"<<ros<<endl;
            numI=numI*10+(num[l-1]-'0');
            if(sum+numI<=i){
                if(brute(i,ros,sum+numI)) return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            //cout<<i<<"*"<<i<<"= "<<i*i<<endl;
            if(brute(i,to_string(i*i),0)){
                //cout<<i<<endl;
                sum+=i*i;
            }
            
        }
        return sum;
    }
};