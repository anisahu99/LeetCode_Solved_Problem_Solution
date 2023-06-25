class Solution {
public:
int n;
int solve(vector<int>& locations, int start, int finish, int fuel,string path){
if(fuel<0)
return 0;
if(start==finish){
cout<<path<<endl;
int ans=1;
for(int i=0;i<n;i++){
if(i==start) continue;
ans=ans+solve(locations,i,finish,fuel-abs(locations[start]-locations[i]),path+to_string(i));
}
return ans;
}
int ans=0;
for(int i=0;i<n;i++){
if(i==start) continue;
ans=ans+solve(locations,i,finish,fuel-abs(locations[start]-locations[i]),path+to_string(i));
}
return ans;
}
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
n=locations.size();
return solve(locations,start,finish,fuel,"1");
}
};