class Solution {
public:
vector<int> sortArrayByParity(vector<int>& nums) {
sort(nums.begin(),nums.end());
int n=nums.size();
int i=0,j=n-1;
while(i<j){
while(i<j&&nums[i]%2==0){
//cout<<i<<", ";
i++;
}
//cout<<i<<endl;
while(i<j&&nums[j]%2==1){
//cout<<j<<", ";
j--;
}
//cout<<j<<endl;
if(i<j){
//cout<<i<<", "<<j<<endl;
int temp=nums[i];
nums[i]=nums[j];
nums[j]=temp;
i++;
j--;
}
}
return nums;
}
};