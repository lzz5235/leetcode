//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place? 
//转两次，第一次对角线转，第二次上下中心线转

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int size = matrix.size();
		for(int i=0;i<size;i++)
			for(int j=0;j<size-i;j++)
				swap(&matrix[i][j],&matrix[size-1-j][size-1-i]);
		for(int i=0;i<size/2;i++)
			for(int j=0;j<size;j++)
				swap(&matrix[i][j],&matrix[size-1-i][j]);
    }
	void swap(int *a,int *b){
		int temp = *a;
		*a=*b;
		*b = temp;
	}
};

int main()
{
	vector<int> vec1,vec2;
	vector<vector<int> > matrix;
	vec1.push_back(1);
	vec1.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);
	matrix.push_back(vec1);
	matrix.push_back(vec2);
	Solution solute;
	solute.rotate(matrix);

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}