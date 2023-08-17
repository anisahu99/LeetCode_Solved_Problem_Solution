class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());//it used as check wordList word exist  and also used as visited
        
        queue<string> q;
        q.push(beginWord);
        
        int ladder=1;
        
        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                string word=q.front();q.pop();
                if(word==endWord) return ladder;
                
                for(int i=0;i<word.length();i++){
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(dict.find(word)!=dict.end()){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[i]=original;
                }
            }
            ladder++;
        }
        return 0;
    }
};