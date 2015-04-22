//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.
//
//click to show follow up.
//
//Follow up:
//A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one-pass algorithm using only constant space?

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
using namespace std;

//red, white, and blue
//0		1		2
//class Solution {
//public:
//    void sortColors(int A[], int n) {
//        int red=0,blue=n-1;
//		for(int i=0;i<blue+1;){
//			if(A[i]==0)
//				swap(A[i++],A[red++]);
//			else if(A[i]==2)
//				swap(A[i],A[blue--]);
//			else
//				i++;
//		}
//    }
//};
class Solution {
public:
    void sortColors(int A[], int n) {
		int count[3]={0};
		for(int i=0;i<n;i++)
			count[A[i]]++;
		for(int i=0,index=0;i<3;i++){
			for(int j=0;j<count[i];j++)
				A[index++] = i;
		}
    }
};

int main()
{

	int a[]={0,1,2,1,1,1,0,0,0,0,0,2,2,2,1,1,1,2,1,0,0,1,1,2,2,2};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	int result = 0;
	Solution solute;
	solute.sortColors(a,sizeof(a)/sizeof(a[0]));
	
	return 0;
}