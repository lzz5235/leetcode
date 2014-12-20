//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1,1,2],
//
//Your function should return length = 2, and A is now [1,2].

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)
			return 0;
		int length=0;
		for(int i=1;i<n;i++)
		{
			if(A[length]!=A[i])
			{
				length++;
				A[length]=A[i];
			}
		}
		return length+1;
    }
	int removeDuplicates2(int A[], int n) {
		return distance(A, unique(A, A + n));
	}
};

int main()
{
	int a[] = {1,1,2};
	Solution solute;

    int result = solute.removeDuplicates2(a,3);   
    return 0;
}