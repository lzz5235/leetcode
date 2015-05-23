//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <hash_map>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
using namespace std;

class TrieNode {
public:
	
    // Initialize your data structure here.
    TrieNode() {
		this->is_words = false;
		for(int i=0;i<26;i++)
			this->children[i] = NULL;
    }
	TrieNode* get_childen(char c){
		return this->children[c-'a'];
	}
	bool set_childen(int i,TrieNode *node){
		return this->children[i] = node;
	}
	bool iswords(){
		return is_words;
	}
	void markAsWord(){
		this->is_words = true;
	}
private:
	bool is_words;
	TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
		int len = s.size();
		TrieNode* parent = root, *node;  
        for(int i=0;i<len; i++){  
			node = parent->get_childen(s[i]);  
            if(node == NULL){  
                node=new TrieNode();  
				parent->set_childen(s[i] - 'a', node);  
            }  
            parent = node;  
        }  
        parent->markAsWord();  
    }

    // Returns if the word is in the trie.
    bool search(string key) {
		int len = key.size();
		TrieNode *node = root;
		for(int i=0;i<len;i++){
			node = node->get_childen(key[i]);
			if(node==NULL)
				return false;
		}
		return node->iswords();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();  
        TrieNode* node = root;  
        for(int i=0; i<len; i++){  
			node = node->get_childen(prefix[i]);  
            if(node==NULL){  
                return false;  
            }  
        }  
        return true;  
    }

private:
    TrieNode* root;
};

int main(){
	bool result=false;
	Trie trie;
	trie.insert("somestring");
	trie.insert("key");
	result = trie.search("key");
	assert(result==true);
	trie.insert("keyfsasda");
	result = trie.search("some");
	assert(result==false);
	return 0;
}