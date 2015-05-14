//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ["ABCE"],
//  ["SFCS"],
//  ["ADEE"]
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.

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
    bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();

        vector<vector<bool>> visit(m,vector<bool>(n,false));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(dfs(board,word,0,i,j,visit))
					return true;
			}
		}
		return false;
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
	char a1[][4]={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	bool result = false;
	vector<vector<char>> board;
	Solution solute;
	solute.buildvector(board,a1,3,4);
	result = solute.exist(board,string("ABCCED"));
	assert(result==true);
	result = solute.exist(board,string("SEE"));
	assert(result==true);
	result = solute.exist(board,string("ABCB"));
	assert(result==false);
	return 0;
}