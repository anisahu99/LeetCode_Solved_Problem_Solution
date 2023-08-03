class Solution {
public:
//     void solve(string &digits,vector<string> &mp,vector<string> &ans,int index,string str){
//         if(index==digits.length()){
//             cout<<str<<endl;
//             return;
//         }
        
//         string letters=mp[digits[index]-'0'];
//         for(char& ch:letters){
//             solve(digits,mp,ans,index+1,str+ch);
//         }
//     }
    vector<string> solve(string &digits,vector<string> &mp,int index){
        if(index==digits.length()){
            vector<string> base;
            base.push_back("");
            return base;
        }
        
        string letters=mp[digits[index]-'0'];
        vector<string> res;
        for(char& ch:letters){
            vector<string> temp=solve(digits,mp,index+1);
            for(string &str:temp){
                // cout<<"hi";
                if(str.length()==0){
                    string ans;
                    ans.push_back(ch);
                    res.push_back(ans);
                }else{
                    res.push_back(ch+str);
                }
                
            }
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {
        // unordered_map<int,string> mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"}}
        if(digits.length()==0) return {};
        vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        return solve(digits,mp,0);;
    }
};