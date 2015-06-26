//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?



#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

//[
//	[1,2,3,4]
//	[5,6,7,8]
//	[7,0,9,0]
//]
//将第一行与第一列作为flag位，来进行标示是否有0，有那么就在最后置零，否则不管，是matrix
//自身的0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.empty())
			return;
		int row = matrix.size();
		int column = matrix[0].size();
		bool rowHas0 = false;
		bool colHas0 = false;

		//check column 0 has 0;
		for(int i=0;i<row;i++){
			if(matrix[i][0]==0){
				colHas0 = true;
				break;
			}
		}

		//check row 0 has 0;
		for(int i=0;i<column;i++){
			if(matrix[0][i]==0){
				rowHas0 = true;
				break;
			}
		}

		for(int i=1;i<row;i++){
			for(int j=1;j<column;j++){
				if(matrix[i][j]==0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for(int i=1;i<row;i++){
			if(matrix[i][0]==0)
				fill_row(matrix,i,row,column);
		}
		for(int j=1;j<column;j++){
			if(matrix[0][j]==0)
				fill_col(matrix,j,row,column);
		}

		if(colHas0)
			fill_col(matrix,0,row,column);
		if(rowHas0)
			fill_row(matrix,0,row,column);

    }
private:
	void fill_row(vector<vector<int>>& matrix,int i,int row,int column){
		for(int j=0;j<column;j++)
			matrix[i][j] = 0;
	}
	void fill_col(vector<vector<int>>& matrix,int j,int row,int column){
		for(int i=0;i<row;i++)
			matrix[i][j] = 0;
	}
};


int main()
{
	vector<vector<int>> matrix;
	int num1[4]={1,2,3,4};
	int num2[4]={5,6,7,8};
	int num3[4]={7,0,9,0};
	int num4[4]={0,10,0,3};
	vector<int> temp1(num1,num1+4);
	vector<int> temp2(num2,num2+4);
	vector<int> temp3(num3,num3+4);
	vector<int> temp4(num4,num4+4);
	Solution solute;
	matrix.push_back(temp1);
	matrix.push_back(temp2);
	matrix.push_back(temp3);
	matrix.push_back(temp4);

	solute.setZeroes(matrix);


	return 0;
}