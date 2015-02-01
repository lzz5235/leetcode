//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]!=elem)
			{	
				A[index] = A[i];
				index++;
			}
		}
		return index;
    }
};

int main()
{
	int A[10]={2,4,5,8,10,3,5};
	Solution solute;
	int length = solute.removeElement(A,6,5);
	for(int i=0;i<length;i++)
		printf("%d\t",A[i]);
	printf("length=%d\n",length);
}