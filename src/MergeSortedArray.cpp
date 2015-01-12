//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Note:
//You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int i,j;
		int cur = m + n-1;
		
		for(i = m-1,j=n-1;i>=0 && j>= 0;cur--)
		{
			if(A[i]>=B[j])
			{
				A[cur] = A[i];
				i--;
			}
			else
			{
				A[cur] = B[j];
				j--;
			}
		}
		while(j>=0)
			A[cur--]=B[j--];
    }
};

int main()
{
	int A[10]={2,4,5};
	int B[3]={1,3,4};
	Solution solute;
	solute.merge(A,3,B,3);
}