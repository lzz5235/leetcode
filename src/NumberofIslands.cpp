//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer: 1
//
//Example 2:
//
//11000
//11000
//00100
//00011
//Answer: 3
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
		int i = grid.size();
		if(i<=0)
			return 0;
		int j = grid[0].size();
		int count=0;
		for(int m=0;m<i;m++){
			for(int n=0;n<j;n++){
				if(grid[m][n]=='1'){
					count++;
					DFS(grid,m,n);
				}
			}
		}
        return count;
    }
	void buildvector(vector<vector<char>> &grid,char (*a)[5],int m,int n){
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
	void DFS(vector<vector<char>> &grid, int i, int j)
	{
		grid[i][j]='0';
		int m = grid.size();
		int n = grid[0].size();
		if(i>0&&grid[i-1][j]=='1')
			DFS(grid,i-1,j);
		if(j>0&&grid[i][j-1]=='1')
			DFS(grid,i,j-1);
		if(i<m-1&&grid[i+1][j]=='1')
			DFS(grid,i+1,j);
		if(j<n-1&&grid[i][j+1]=='1')
			DFS(grid,i,j+1);
	}
};

int main()
{

	char a1[][5]={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},
				{'0','0','0','0','0'}};
	char a2[][5]={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},
				{'0','0','0','1','1'}};
	vector<vector<char>> grid;
	int result = 0;
	Solution solute;
	solute.buildvector(grid,a1,4,5);
	result = solute.numIslands(grid);
	assert(result==1);
	grid.clear();
	solute.buildvector(grid,a2,4,5);
	result = solute.numIslands(grid);
	assert(result==3);
	return 0;
}