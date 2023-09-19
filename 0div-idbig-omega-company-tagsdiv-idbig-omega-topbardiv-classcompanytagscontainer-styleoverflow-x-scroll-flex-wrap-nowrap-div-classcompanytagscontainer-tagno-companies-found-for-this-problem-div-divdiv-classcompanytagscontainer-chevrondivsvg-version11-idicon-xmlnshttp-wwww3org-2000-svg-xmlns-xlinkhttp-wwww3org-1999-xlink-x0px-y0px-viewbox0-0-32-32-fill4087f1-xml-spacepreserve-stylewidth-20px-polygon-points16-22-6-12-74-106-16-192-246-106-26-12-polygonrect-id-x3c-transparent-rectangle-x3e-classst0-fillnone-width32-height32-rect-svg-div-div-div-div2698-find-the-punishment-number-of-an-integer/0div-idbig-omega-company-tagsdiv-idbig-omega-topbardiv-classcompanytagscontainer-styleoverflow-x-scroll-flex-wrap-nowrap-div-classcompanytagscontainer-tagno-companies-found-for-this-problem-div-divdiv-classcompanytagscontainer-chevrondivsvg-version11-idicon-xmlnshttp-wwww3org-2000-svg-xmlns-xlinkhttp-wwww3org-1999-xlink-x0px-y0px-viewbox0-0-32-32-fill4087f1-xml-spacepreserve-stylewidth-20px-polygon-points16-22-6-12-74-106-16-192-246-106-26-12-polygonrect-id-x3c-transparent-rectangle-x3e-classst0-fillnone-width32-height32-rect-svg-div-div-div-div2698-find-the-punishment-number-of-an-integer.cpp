class Solution {
public:
    //(36,"1296",0)
    //for 1296 we try break into substring such that sum of the integer values of these substrings equals to target 
    bool brute(int &i,string num,int sum){
        if(num==""&&sum==i){
            //cout<<sum<<endl;
            return true;
        }
        
        for(int l=1;l<=num.size();l++){
            string pre=num.substr(0,l);
            string ros=num.substr(l);
            //cout<<"length "<<l<<"-"<<ros<<endl;
            int numI=stoi(pre);
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