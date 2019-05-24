// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author : Hao Chen
// Date   : 2015-06-10

/********************************************************************************** 
 * 211. Add and Search Word - Data structure design [Medium]
 * Design a data structure that supports the following two operations:
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * search(word) can search a literal word or a regular expression string containing only letters `a-z` or `.`
 * A `.` means it can represent any one letter.
 * 
 * For example:
 * 
 *   addWord("bad")
 *   addWord("dad")
 *   addWord("mad")
 *   search("pad") -> false
 *   search("bad") -> true
 *   search(".ad") -> true
 *   search("b..") -> true
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 * click to show hint.
 * 
 * You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
 * 
 *               
 **********************************************************************************/
#include <string.h>
#include <iostream>
#include <string>
using namespace std;


// 116 ms, faster than 62.29% of C++, 46.9 MB, less than 44.10% of C++
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

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root  = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto c:word){
            
            if(!cur->children[c-'a'])cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->has = true;
        return ;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* cur = root;
        return searchResc(cur,word);
    }
private:
    bool searchResc(TrieNode* cur,string word) {
        if(!cur)return false;
        for(int i = 0;i<word.size();i++){
            if(word[i] == '.'){
                for(auto pt:cur->children)
                    if( searchResc(pt,string(word,i+1,word.size()-i-1)) )return true;
                return false;
            }
            else{
               if(!cur->children[word[i]-'a'])return false;
                cur = cur->children[word[i]-'a']; 
            }
        }
        return cur->has;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */






// 84 ms, faster than 97.84% of C++, 44.9 MB, less than 58.80% of C++

const int MAX_CHARS = 26;

/*Trie Node*/
class TrieNode {
public:
    TrieNode():isWord(false) {
        memset(childern, 0, sizeof(childern));
    }
    TrieNode* & operator [] (char idx){
        int i = (idx-'a') % MAX_CHARS;
        return childern[i];
    }
    TrieNode* & operator [] (int idx){
        int i = idx % MAX_CHARS;
        return childern[i];
    }
    bool isWord;
private:
    TrieNode* childern[MAX_CHARS];
};


/*Trie Tree*/
class TrieTree {
public:
    TrieTree():root(new TrieNode()){ }
    ~TrieTree() { freeTree(root); }
    
    void put(string &s) {
        TrieNode* node = root;
        for (int i=0; i<s.size(); i++){
            if ((*node)[s[i]] == NULL){
                (*node)[s[i]] = new TrieNode();
            }
            node = (*node)[s[i]];
        }
        node->isWord = true;
    }
    bool search(string &s){
        return get(s, this->root);
    }

private:

    bool get(string &s, TrieNode* root, int idx=0){
        TrieNode* node = root;
        for (int i=idx; i<s.size(); i++){
            if (s[i]!='.'){
                node = (*node)[s[i]];
                if (node == NULL) return false;
            }else{
                for (int j=0; j<MAX_CHARS; j++) {
                    TrieNode *p = (*node)[j];
                    if (p == NULL ) {
                        continue;//try next
                    }
                    // p!=NULL
                    if (i<s.size()-1) {
                        if (this->get(s, p, i+1)) {
                            return true;
                        }
                        continue; //try next
                    }
                    // p!=NULL && i == s.size()-1
                    if (p->isWord) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->isWord; 
    }
    
private:
    void freeTree(TrieNode* root){
        for(int i=0; i<MAX_CHARS; i++){
            if ((*root)[i]!=NULL){
                freeTree((*root)[i]);
            }
        }
        delete root;
    }
    TrieNode *root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        tree.put(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return tree.search(word);
    }
private:
    TrieTree tree;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");








int main()
{
    WordDictionary wd;
    wd.addWord("a");
    cout << wd.search("a.") <<endl;;
    cout << wd.search(".a") << endl;;
    wd.addWord("bad");
    cout << wd.search("bad") <<endl;;
    cout << wd.search("b..") <<endl;;
    return 0;
}



