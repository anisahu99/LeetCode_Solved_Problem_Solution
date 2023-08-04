class TrieNode{
    public:
    char data;
    TrieNode* children [26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string words){

        if(words.length()==0){
            root->isTerminal=true;
            return;
        }

        TrieNode* child;

        int index=words[0]-'a';
        //present
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(words[0]);
            root->children[index]=child;
        }

        insertUtil(child,words.substr(1));
    }
    void insertWord(string words){
        insertUtil(root,words);
    }

    void searchUtilR(TrieNode* root,string words){
        if(words.length()==0){
            root->isTerminal=false;
            return;
        }

        TrieNode* child;

        int index=words[0]-'a';
        //present
        if(root->children[index]){
            child=root->children[index];
            searchUtilR(child,words.substr(1));
        }
        return;
    }

    void searchWordR(string words){
         searchUtilR(root,words);
    }

    void removeWord(string words){
        searchWordR(words);
    }
    bool searchUtil(TrieNode* root,string words){
        if(words.length()==0){
            return root->isTerminal;
        }

        TrieNode* child;

        int index=words[0]-'a';
        //present
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,words.substr(1));
    }

    bool searchWord(string words){
        return searchUtil(root,words);
    }
};


class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s,Trie* t){
        if(s=="") return true;
        if(mp.find(s)!=mp.end()) return mp[s];
        for(int i=s.length();i>=1;i--){
            string ss=s.substr(0,i);
            if(t->searchWord(ss)){
                string ros=s.substr(i);
                //cout<<ss<<"-"<<ros<<endl;
                bool ans=solve(ros,t);
                if(ans){
                    mp[s]=true;
                    return true;
                } 
            }
        }
        return mp[s]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        Trie* t=new Trie();
        for(string &str:wordDict){
            t->insertWord(str);
        }
        return solve(s,t);
    }
};