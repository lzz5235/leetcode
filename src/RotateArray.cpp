//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
		if(k>=n)
			k=k%n;
		if(k==0)
			return;
		if(n==1)
			return;
		if(n==2&&k==1)
		{
			swap(&nums[0],&nums[1]);
			return;
		}

		int first = n-k-1;
		int second = n-k;
		for(int i=0;i<=first/2;i++)
			swap(&nums[i],&nums[first-i]);
		for(int i=second;i<=(second+n-1)/2;i++)
			swap(&nums[i],&nums[second+n-1-i]);
		for(int i=0;i<n/2;i++)
			swap(&nums[i],&nums[n-1-i]);
    }
	void swap(int *a,int *b){
		int temp = *a;
		*a=*b;
		*b = temp;
	}
};

int main()
{
	//int A[7]={1,2,3,4,5,6,7};
	int A[4]={-1,-100,3,99};
	Solution solute;
	solute.rotate(A,4,3);

	for(int i=0;i<4;i++)
	{
		printf("%d\t",A[i]);
	}
}