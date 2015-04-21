//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].

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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if(matrix.empty())	
			return result;
		int x_begin = 0,x_end = matrix[0].size()-1;
		int y_begin = 0,y_end = matrix.size()-1;

		for(;;){
			for(int j = x_begin;j<=x_end;j++)
				result.push_back(matrix[y_begin][j]);
			y_begin++;
			if(y_begin > y_end)	break;
			for(int i= y_begin;i<=y_end;i++)
				result.push_back(matrix[i][x_end]);
			x_end--;
			if(x_begin > x_end)	break;
			for(int j = x_end;j>=x_begin;j--)
				result.push_back(matrix[y_end][j]);
			y_end--;
			if(y_begin > y_end)	break;
			for(int i = y_end;i>=y_begin;i--)
				result.push_back(matrix[i][x_begin]);
			x_begin++;
			if(x_begin > x_end)	break;
		}
		return result;
    }
};

int main()
{

	int a1[]={1,   3,  5,  7};
	int a2[]={10, 11, 16, 20};
	int a3[]={23, 30, 34, 50};
	vector<int> num1(a1,a1+4);
	vector<int> num2(a2,a2+4);
	vector<int> num3(a3,a3+4);
	vector<vector<int> > matrix;
	matrix.push_back(num1);
	matrix.push_back(num2);
	matrix.push_back(num3);
	vector<int> result;
	Solution solute;
	result = solute.spiralOrder(matrix);	
	return 0;
}