//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.
//
//click to show hint.
//
//You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

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
	void set_childen(int i,TrieNode *node){
		this->children[i] = node;
	}
	bool iswords(){
		return is_words;
	}
	void markAsWord(){
		this->is_words = true;
	}
	bool is_words;
	TrieNode* children[26];
};

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode;
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.size();
		TrieNode* parent = root, *node;  
        for(int i=0;i<len; i++){  
			node = parent->get_childen(word[i]);  
            if(node == NULL){  
                node=new TrieNode();  
				parent->set_childen(word[i] - 'a', node);  
            }  
            parent = node;  
        }  
        parent->markAsWord();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		return search(word,root);       
    }
	bool search(string word,TrieNode* root){
		int len = word.size();
		TrieNode *node = root;
		for(int i=0;i<len;i++){
			if(word[i]!='.'){
				node = node->get_childen(word[i]);
				if(node==NULL)
					return false;
			}
			else{
				for(int j=0;j<26;j++){
					if(node->children[j]&&search(word.substr(i+1),node->children[j])){//dfs
						cout << word.substr(i+1) <<endl;
						return true;
					}
				}
				return false;
			}
		}
		return node->iswords();
	}
private:
	TrieNode* root;
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
	bool result=false;
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	result = wordDictionary.search("pad");
	assert(result==false);
	result = wordDictionary.search("bad");
	assert(result==true);
	result = wordDictionary.search(".ad");
	assert(result==true);
	result = wordDictionary.search("b..");
	assert(result==true);
	return 0;
}