//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//For example,
//Given words = ["oath","pea","eat","rain"] and board =
//
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//Return ["eat","oath"].
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.
//
//click to show hint.
//
//You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
//
//If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int m = board.size();
		int n = board[0].size();
		vector<string> result;
		
		sort(words.begin(),words.end());
		vector<string>::iterator end_unique=unique(words.begin(),words.end());
		words.erase(end_unique,words.end());
		for(int k = 0;k<words.size();k++){
			reverse(words[k].begin(),words[k].end());
		}

		for(int k = 0;k<words.size();k++){
			vector<vector<bool>> visit(m,vector<bool>(n,false));
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(dfs(board,words[k],0,i,j,visit))
					{
						reverse(words[k].begin(),words[k].end());
						result.push_back(words[k]);
						goto out;
					}
				}
			}
out:
			continue;
		}
		sort(result.begin(),result.end());
		end_unique=unique(result.begin(),result.end());
		result.erase(end_unique,result.end());
		return result;        
    }
	void buildvector(vector<vector<char>> &grid,char (*a)[4],int m,int n){
		vector<char> temp;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				temp.push_back(a[i][j]);
			}
			grid.push_back(temp);
			temp.clear();
		}
	}
private:
	bool dfs(vector<vector<char>>& board,string &word,int step,int x,int y,
														vector<vector<bool>> &visit){
		if(step==word.size())
			return true;

		if(x<0||y<0||x>=board.size()||y>=board[0].size())
			return false;

		if(visit[x][y])
			return false;

		if(board[x][y]!=word[step])
			return false;

		visit[x][y]=true;
		bool ret = dfs(board,word,step+1,x+1,y,visit)||
			dfs(board,word,step+1,x-1,y,visit)||
			dfs(board,word,step+1,x,y-1,visit)||
			dfs(board,word,step+1,x,y+1,visit);
		visit[x][y]=false;
		return ret;
	}
};


int main()
{
	char a1[][4]={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	vector<string> result;
	vector<vector<char>> board;
	vector<string> words;
	words.push_back(string("oathflvrkaena"));
	words.push_back(string("oath"));
	words.push_back(string("pea"));
	words.push_back(string("eat"));
	words.push_back(string("oathflvrkaena"));
	words.push_back(string("rain"));
	Solution solute;
	solute.buildvector(board,a1,4,4);
	result = solute.findWords(board,words);

	return 0;
}