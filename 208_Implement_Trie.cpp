/*
Question:
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/


//Sol:1 248ms
/*
class Trie {
private:
    //map of character and next trie Node
    map<char, Trie*> next = {};
    //end of the word; Completely traversed.
    bool isword = false;
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        //this will give current Trie Tree constructed till now.
        Trie* node = this;
        for(char ch:word)
        {
            if(!(node->next).count(ch))
            {
                node->next[ch]=new Trie();
            }
            node=node->next[ch];
        }
        node->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(char ch:word)
        {
            if(!(node->next).count(ch))return false;
            node=node->next[ch];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 */
 
 //Sol:2 196ms
 class TrieNode{
  public:
    vector<TrieNode*> dict;
    bool isEnd;
    TrieNode(){
        isEnd = false;
        dict.resize(26, nullptr);
    }
};
class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a']==nullptr){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            node = node->dict[s[i]-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a']==nullptr)
                return false;
            node = node->dict[s[i]-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a']==nullptr)
                return false;
            node = node->dict[s[i]-'a'];
        }
        return true;
    }
};
