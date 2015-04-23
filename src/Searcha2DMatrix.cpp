//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix:
//
//[
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//Given target = 3, return true.

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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.empty()) return false;
		int m = matrix.size();
		int n = matrix[0].size();

		int first = 0;
		int last = m*n;

		while(first < last){
			int mid = first + (last - first)/2;
			int value = matrix[mid/n][mid%n];

			if(value == target)
				return true;
			else if(value < target)
				first = mid+1;
			else
				last = mid;
		}
		return false;
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
	bool result;
	Solution solute;
	result = solute.searchMatrix(matrix,9);
	assert(result==false);
	result = solute.searchMatrix(matrix,34);
	assert(result==true);
	
	return 0;
}