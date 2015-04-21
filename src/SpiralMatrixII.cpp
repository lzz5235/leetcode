//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

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
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix(n,vector<int>(n,0));//n*n
		if(n==0)
			return matrix;
		int num = 1,end = n*n;

		int x_begin = 0,x_end = n-1;
		int y_begin = 0,y_end = n-1;

		for(;num<end+1;){
			for(int j = x_begin;j<=x_end;j++)
				matrix[y_begin][j]=num++;
			y_begin++;
			if(y_begin > y_end)	break;
			for(int i= y_begin;i<=y_end;i++)
				matrix[i][x_end]=num++;
			x_end--;
			if(x_begin > x_end)	break;
			for(int j = x_end;j>=x_begin;j--)
				matrix[y_end][j]=num++;
			y_end--;
			if(y_begin > y_end)	break;
			for(int i = y_end;i>=y_begin;i--)
				matrix[i][x_begin]=num++;
			x_begin++;
			if(x_begin > x_end)	break;
		}
		return matrix;
    }
};

int main()
{
	vector<vector<int> > matrix;
	Solution solute;
	matrix = solute.generateMatrix(3);	
	return 0;
}