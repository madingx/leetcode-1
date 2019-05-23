// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 208. Implement Trie (Prefix Tree) [Medium]
 * Implement a trie with insert, search, and startsWith methods.

 * Example:

 * Trie trie = new Trie();

 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * Note:

 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 **********************************************************************************/

// 104 ms, faster than 32.39% of C++, 36 MB, less than 83.86% of C++
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {   }
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size()<=0) return;
        TrieNode * node = root;
        for (int i=0; i<s.size(); i++) {
            if (node->children.find(s[i]) == node->children.end()){
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return retrieve(key, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return retrieve(prefix, false);
    }

private:

    inline bool retrieve(const string& key, bool isWord) {
        if (key.size() <= 0) return false;
        TrieNode * node = root;
        for (int i=0; i<key.length(); i++) {
            if (node->children.find(key[i]) == node->children.end()) {
                return false;
            }
            node = node->children[key[i]];
        }
        return isWord ? node->isWord : true;
    }

    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");





// 80 ms, faster than 86.65% of C++, 48.3 MB, less than 18.07% of C++
class TrieNode {
public:
    bool has;
    vector<TrieNode*> children;
    TrieNode(){
        has = false;
        children = vector<TrieNode*>(26,NULL);
    }
    ~TrieNode(){
        for(auto i:children){
            delete i;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c:word){
            if( !cur->children[c-'a'] ) cur->children[c-'a'] = new TrieNode();             
            cur = cur->children[c-'a'];
        }
        cur->has = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c:word){
            if( cur->children[c-'a'] )   cur = cur->children[c-'a'];
            else  return false;
        }
        return cur->has;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c:prefix){
            if( cur->children[c-'a'] )   cur = cur->children[c-'a'];
            else  return false;
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