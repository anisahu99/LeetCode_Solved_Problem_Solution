cout<<ans<<endl;
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
int temp=arr[i].length()+solve(arr,i+1,freq,ans+"-"+arr[i]);
cnt=max(cnt,temp);
decrease(arr,i,freq);
​
}
cnt=max(cnt,solve(arr,i+1,freq,ans));
return cnt;
}
int maxLength(vector<string>& arr) {
n=arr.size();
vector<int> freq(26,0);
return solve(arr,0,freq,"");
}
};