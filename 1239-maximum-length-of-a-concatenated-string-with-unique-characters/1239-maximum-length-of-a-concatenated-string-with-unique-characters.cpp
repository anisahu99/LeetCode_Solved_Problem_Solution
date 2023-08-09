class Solution {
public:
    int increase(vector<string> &arr,int i,vector<int>& freq){
        //cout<<arr[i]<<"->";
        for(int j=0;j<arr[i].length();j++){
            char ch=arr[i][j];
            if(freq[ch-'a']>0){
                return j;
            }
            else{
                freq[ch-'a']++;
            }
        }
        return -1;
    }
    void decrease(vector<string> &arr,int i,vector<int>& freq){
        for(char &ch:arr[i]){
            if(freq[ch-'a']!=0){
                freq[ch-'a']--;
            }
        }
    }
    void decreaseb(vector<string> &arr,int i,int j,vector<int>& freq){
        for(int k=0;k<j;k++){
            if(freq[arr[i][k]-'a']!=0){
                freq[arr[i][k]-'a']--;
            }
            
        }
    }
    
    int n; 
    
    int solve(vector<string> &arr,int i,vector<int>& freq){
        if(i==n){
            //cout<<ans<<endl;
            return 0;
        }
        int index=increase(arr,i,freq);
        //cout<<index<<",";
        if(index!=-1){
            decreaseb(arr,i,index,freq);
        }
        int cnt=0;
        if(index==-1){
            //cout<<index<<"-"<<endl;
            //take
            int temp=arr[i].length()+solve(arr,i+1,freq);
            cnt=max(cnt,temp);
            decrease(arr,i,freq);

        }
        
        cnt=max(cnt,solve(arr,i+1,freq));
        
        return cnt;
    }
    int maxLength(vector<string>& arr) {
        n=arr.size();
        vector<int> freq(26,0);
        return solve(arr,0,freq);
    }
};