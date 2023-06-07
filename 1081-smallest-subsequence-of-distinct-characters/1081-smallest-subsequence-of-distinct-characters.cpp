class Solution {
public:
    string smallestSubsequence(string s) {
        // to keep count of number of each characters in string
        vector<int> count(26);
        
        // bit mask to mark the characters that are already present in the stack
        int visited=0;
        
        // we will use stack to keep track of characters that are less than current 
        // characters and appear in later part of the string
        stack<int> st;
        
        
        int n=s.size();
        for (char ch:s){
            count[ch-'a']++;
        }
        
        
        for (int i=0;i<n;i++){
            // bring characters into the range 0-25
            int ch = s[i]-'a';
            
            // decrease the count of characters
            count[ch]--;
            
            // if the character is already present in the stack then we don't need to do anythinh
            if (((1<<ch)&visited)>0) continue;

            // if the character at the top of the stack is less than the current character and there are
            // more of it left, i.e. it occurs later in the string then remove it
            while (!st.empty() and st.top()>ch and count[st.top()]>0){
                
                // mark it univisited since no longer present in the stack
                visited = visited & ~(1<<st.top());
                st.pop();
            }
            
            // push the characters in the stack and mark it visited
            st.push(ch);
            visited = visited|(1<<ch);
        }
        string ans="";
        while (!st.empty()){
            char ch = 'a'+st.top();
            st.pop();
            
            // the characters in the stack will be in reverse order of their appearance in the string
            ans.insert(ans.begin(),ch);
        }
        return ans;
    }
};